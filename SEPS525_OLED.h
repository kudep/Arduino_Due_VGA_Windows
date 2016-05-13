#ifndef _SEPS525_OLED_H_
#define _SEPS525_OLED_H_

#include <SPI.h>
#include <SD.h>
#include "Adafruit_GFX.h"

class SEPS525_OLED : public Adafruit_GFX {
	public:
		SEPS525_OLED(void);

		void begin(void);

		void fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
		void fillRect_with_back(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color, uint16_t back_color);
		void bmpfileDraw(char *filename);
private:
	void drawPixel(int16_t x, int16_t y, uint16_t color);
	void drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color);
	void drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color);
	uint16_t color565(uint8_t r, uint8_t g, uint8_t b);
	uint16_t read16(File f);
	uint32_t read32(File f);

	//low level transmission of seps525
	void prog_spi_init(void);
	void prog_spi_transfer(int8_t data);
	void seps525_reg(int idx, int value);
	inline void seps525_datastart(void);
	inline void seps525_data(int value);
	inline void seps525_dataend(void);
	void seps525_set_region(int x, int y, int xs, int ys);
	void seps525_setup(void);
	void seps525_init(void);
};

#endif
