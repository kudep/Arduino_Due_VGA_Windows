#include "SEPS525_OLED.h"
//pin for SEPS525_OLED
static const int seps525_oled_pinSCL = 23;			   //	static const int pinSCL = 22;		
static const int seps525_oled_pinSDI = 25;			   //	static const int pinSDI = 23;		
static const int seps525_oled_pinRS = 29;			   //	static const int pinRS = 24;		
static const int seps525_oled_pinSS = 27;			   //	static const int pinSS = 25;		
static const int seps525_oled_pinReset = 31;			   //	static const int pinReset = 26;		
static const int seps525_oled_pinVddEnable = 33;		   //	static const int pinVddEnable = 27;	
static const int seps525_oled_width = 160;
static const int seps525_oled_height = 128;

void SEPS525_OLED::prog_spi_init(void)
{
	pinMode(seps525_oled_pinSCL, OUTPUT);
	pinMode(seps525_oled_pinSDI, OUTPUT);
	digitalWrite(seps525_oled_pinSCL, HIGH);
	digitalWrite(seps525_oled_pinSDI, HIGH);
}

void SEPS525_OLED::prog_spi_transfer(int8_t data)
{
	for (int8_t i = 0; i < 8; i++)
	{
		digitalWrite(seps525_oled_pinSCL, LOW);
		if ((data & 0x80) == 0x80)
			digitalWrite(seps525_oled_pinSDI, HIGH);
		else
			digitalWrite(seps525_oled_pinSDI, LOW);
		data <<= 1;
		digitalWrite(seps525_oled_pinSCL, HIGH);

	}
	digitalWrite(seps525_oled_pinSDI, HIGH);
}

void SEPS525_OLED::seps525_reg(int idx, int value)
{
	digitalWrite(seps525_oled_pinSS, LOW);
	digitalWrite(seps525_oled_pinRS, LOW);
	prog_spi_transfer(idx);
	digitalWrite(seps525_oled_pinRS, HIGH);
	digitalWrite(seps525_oled_pinSS, HIGH);

	digitalWrite(seps525_oled_pinSS, LOW);
	prog_spi_transfer(value);
	digitalWrite(seps525_oled_pinSS, HIGH);
}

inline void  SEPS525_OLED::seps525_datastart(void)
{
	digitalWrite(seps525_oled_pinSS, LOW);
	digitalWrite(seps525_oled_pinRS, LOW);
	prog_spi_transfer(0x22);
	digitalWrite(seps525_oled_pinRS, HIGH);
}

inline void  SEPS525_OLED::seps525_data(int value)
{
  prog_spi_transfer((value>>8)& 0xFF);
  prog_spi_transfer(value & 0xFF);
}

inline void SEPS525_OLED::seps525_dataend(void)
{
	digitalWrite(seps525_oled_pinSS, HIGH);
}

void  SEPS525_OLED::seps525_set_region(int x, int y, int xs, int ys)
{
  // draw region
  seps525_reg(0x17,x);
  seps525_reg(0x18,x+xs-1);
  seps525_reg(0x19,y);
  seps525_reg(0x1a,y+ys-1);
  
  // start position
  seps525_reg(0x20,x);
  seps525_reg(0x21,y);
}

void SEPS525_OLED::seps525_setup(void)
{
  prog_spi_init();

  //SPI.begin();
  //SPI.setBitOrder(MSBFIRST);
  //SPI.setDataMode(SPI_MODE3);
  //SPI.setClockDivider(SPI_CLOCK_DIV2);
  
  // pin for switcher enable (off by default)
  digitalWrite(seps525_oled_pinVddEnable, HIGH);
  pinMode(seps525_oled_pinVddEnable, OUTPUT);
  
  // pins for seps525
  digitalWrite(seps525_oled_pinRS, HIGH);
  digitalWrite(seps525_oled_pinSS, HIGH);
  digitalWrite(seps525_oled_pinReset, HIGH);
  pinMode(seps525_oled_pinRS, OUTPUT);
  pinMode(seps525_oled_pinSS, OUTPUT);
  pinMode(seps525_oled_pinReset, OUTPUT);
}

void SEPS525_OLED::seps525_init(void)
{
  seps525_setup();
  
  // NOTE: this procedure is from Densitron 
  // DD-160128FC-2B datasheet
  
  digitalWrite(seps525_oled_pinReset, LOW);
  delay(2);
  digitalWrite(seps525_oled_pinReset, HIGH);
  delay(1);
  // display off, analog reset
  seps525_reg(0x04, 0x01);
  delay(1);
  // normal mode
  seps525_reg(0x04, 0x00);
  delay(1);
  // display off
  seps525_reg(0x06, 0x00);
  // turn on internal oscillator using external resistor
  seps525_reg(0x02, 0x01);
  // 90 hz frame rate, divider 0
  seps525_reg(0x03, 0x30);
  // duty cycle 127
  seps525_reg(0x28, 0x7f);
  // start on line 0
  seps525_reg(0x29, 0x00);
  // rgb_if
  seps525_reg(0x14, 0x31);
  // memory write mode
  seps525_reg(0x16, 0x66);

  // driving current r g b (uA)
  seps525_reg(0x10, 0x45);
  seps525_reg(0x11, 0x34);
  seps525_reg(0x12, 0x33);

  // precharge time r g b
  seps525_reg(0x08, 0x04);
  seps525_reg(0x09, 0x05);
  seps525_reg(0x0a, 0x05);

  // precharge current r g b (uA)
  seps525_reg(0x0b, 0x9d);
  seps525_reg(0x0c, 0x8c);
  seps525_reg(0x0d, 0x57);

  seps525_reg(0x80, 0x00);

  // mode set
  seps525_reg(0x13, 0x00);
  
  
  seps525_set_region(0, 0, 160, 128);

  seps525_datastart();
  int n;
  for(n = 0; n < 160*128; n++) {
    seps525_data(0xffff);
  }
  seps525_dataend();
  
  digitalWrite(seps525_oled_pinVddEnable, LOW);
  delay(100);
  
  seps525_reg(0x06, 0x01);
}


SEPS525_OLED::SEPS525_OLED(void) : Adafruit_GFX(seps525_oled_width, seps525_oled_height)
{
}

void SEPS525_OLED::begin(void)
{
	seps525_init();
}

void SEPS525_OLED::drawPixel(int16_t x, int16_t y, uint16_t color)
{
	seps525_set_region(x, y, 1, 1);
	seps525_datastart();
	seps525_data(color);
	seps525_dataend();
}

void SEPS525_OLED::drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color)
{
	seps525_set_region(x, y, 1, h);
	seps525_datastart();
	int n;
	for(n = 0; n < h; n++) seps525_data(color);
	seps525_dataend();
}

void SEPS525_OLED::drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color)
{
	seps525_set_region(x, y, w, 1);
	seps525_datastart();
	int n;
	for(n = 0; n < w; n++) seps525_data(color);
	seps525_dataend();
}

void SEPS525_OLED::fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color)
{
	seps525_set_region(x, y, w, h);
	seps525_datastart();
	int n;
	for (n = 0; n < h*w; n++) seps525_data(color);
	seps525_dataend();
}
void SEPS525_OLED::fillRect_with_back(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color, uint16_t back_color)
{
	static int16_t r_x = 0;
	static int16_t r_y = 0;
	static int16_t r_w = 0;
	static int16_t r_h = 0;
	seps525_set_region(r_x, r_y, r_w, r_h);
	seps525_datastart();
	int n;
	for (n = 0; n < r_h*r_w; n++) seps525_data(back_color);
	seps525_dataend();

	r_x = x;
	r_y = y;
	r_w = w;
	r_h = h;
	seps525_set_region(r_x, r_y, r_w, r_h);
	seps525_datastart();
	for (n = 0; n < r_h*r_w; n++) seps525_data(color);
	seps525_dataend();
}

uint16_t SEPS525_OLED::color565(uint8_t r, uint8_t g, uint8_t b)
{
	return ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | b>>3;
}


// This function opens a Windows Bitmap (BMP) file and
// displays it at the given coordinates.  It's sped up
// by reading many pixels worth of data at a time
// (rather than pixel by pixel).  Increasing the buffer
// size takes more of the Arduino's precious RAM but
// makes loading a little faster.  20 pixels seems a
// good balance.


void SEPS525_OLED::bmpfileDraw(char *filename) {

	static const int BUFFPIXEL = 20;
	File     bmpFile;
	int      bmpWidth, bmpHeight;   // W+H in pixels
	uint8_t  bmpDepth;              // Bit depth (currently must be 24)
	uint32_t bmpImageoffset;        // Start of image data in file
	uint32_t rowSize;               // Not always = bmpWidth; may have padding
	uint8_t  sdbuffer[3 * BUFFPIXEL]; // pixel buffer (R+G+B per pixel)
	uint8_t  buffidx = sizeof(sdbuffer); // Current position in sdbuffer
	boolean  goodBmp = false;       // Set to true on valid header parse
	boolean  flip = true;        // BMP is stored bottom-to-top
	int      w, h, row, col;
	uint8_t  r, g, b;
	uint32_t pos = 0; 

	//startTime = millis();
	//Serial.println();
	//Serial.print("Loading image '");
	//Serial.print(filename);
	//Serial.println('\'');

	// Open requested file on SD card
	if ((bmpFile = SD.open(filename, FILE_READ)) == NULL) {
		Serial.print("File not found");
		return;
	}

	// Parse BMP header
	if (read16(bmpFile) == 0x4D42) { // BMP signature

		//Serial.print("File size: "); Serial.println(read32(bmpFile));

		(void)read32(bmpFile);// BMP signature
		(void)read32(bmpFile); // Read & ignore creator bytes
		bmpImageoffset = read32(bmpFile); // Start of image data

		//Serial.print("Image Offset: "); Serial.println(bmpImageoffset, DEC);
		//// Read DIB header
		//Serial.print("Header size: "); Serial.println(read32(bmpFile));

		(void)read32(bmpFile);
		bmpWidth = read32(bmpFile);
		bmpHeight = read32(bmpFile);
		if (read16(bmpFile) == 1) { // # planes -- must be '1'
			bmpDepth = read16(bmpFile); // bits per pixel

			//Serial.print("Bit Depth: "); Serial.println(bmpDepth);

			if ((bmpDepth == 24) && (read32(bmpFile) == 0)) { // 0 = uncompressed

				goodBmp = true; // Supported BMP format -- proceed!

				/*
				Serial.print("Image size: ");
				Serial.print(bmpWidth);
				Serial.print('x');
				Serial.println(bmpHeight);
				*/

				// BMP rows are padded (if needed) to 4-byte boundary

				rowSize = (bmpWidth * 3 + 3) & ~3;

				// If bmpHeight is negative, image is in top-down order.
				// This is not canon but has been observed in the wild.
				if (bmpHeight < 0) {
					bmpHeight = -bmpHeight;
					flip = false;
				}

				w = bmpWidth;
				h = bmpHeight;

				seps525_set_region(0, 0, seps525_oled_width, seps525_oled_height);
				seps525_datastart();
				for (row = 0; row<h; row++) { // For each scanline...

					// Seek to start of scan line.  It might seem labor-
					// intensive to be doing this on every line, but this
					// method covers a lot of gritty details like cropping
					// and scanline padding.  Also, the seek only takes
					// place if the file position actually needs to change
					// (avoids a lot of cluster math in SD library).
					if (flip) // Bitmap is stored bottom-to-top order (normal BMP)
						pos = bmpImageoffset + (bmpHeight - 1 - row) * rowSize;
					else     // Bitmap is stored top-to-bottom
						pos = bmpImageoffset + row * rowSize;
					if (bmpFile.position() != pos) // Need seek?
					{
						bmpFile.seek(pos);
						buffidx = sizeof(sdbuffer); // Force buffer reload
					}

					for (col = 0; col<w; col++) { // For each pixel...
						// Time to read more pixel data?
						if (buffidx >= sizeof(sdbuffer)) { // Indeed
							bmpFile.read(sdbuffer, sizeof(sdbuffer));
							buffidx = 0; // Set index to beginning
						}

						// Convert pixel from BMP to TFT format, push to display
						seps525_data(color565(sdbuffer[buffidx+2], sdbuffer[buffidx+1], sdbuffer[buffidx]));
						buffidx += 3;

					} // end pixel
				} // end scanline

				seps525_dataend();

				//Serial.print("Loaded in ");
				//Serial.print(millis() - startTime);
				//Serial.println(" ms");

			} // end goodBmp
		}
	}

	bmpFile.close();
	if (!goodBmp) Serial.println("BMP format not recognized.");
	
}

// These read 16- and 32-bit types from the SD card file.
// BMP data is stored little-endian, Arduino is little-endian too.
// May need to reverse subscript order if porting elsewhere.
uint16_t SEPS525_OLED::read16(File f) {
	uint16_t result;
	((uint8_t *)&result)[0] = f.read(); // LSB
	((uint8_t *)&result)[1] = f.read(); // MSB
	return result;
}
uint32_t SEPS525_OLED::read32(File f) {
	uint32_t result;
	((uint8_t *)&result)[0] = f.read(); // LSB
	((uint8_t *)&result)[1] = f.read();
	((uint8_t *)&result)[2] = f.read();
	((uint8_t *)&result)[3] = f.read(); // MSB
	return result;
}
