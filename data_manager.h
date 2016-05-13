
#ifndef DATA_MANAGER_H_INCLUDED
#define DATA_MANAGER_H_INCLUDED
#include <SPI.h>
#include <SD.h>
#include "database_structure.h"

#define SD_CS   2  // Chip select line for SD card

struct slide_test_obj_data
{
	int numb = 0;
	int x = 0;
	int y = 0;
	int l = 0;
	int h = 0;
	int orient = 1;
	char name[30] = { 0 };
	void reset()
	{
		numb = 0;
		x = 0;
		y = 0;
		l = 0;
		h = 0;
		orient = 1;
		name[0] = 0;
	}
};

struct slide_data
{
	int numb = 1;
	int numb_VIZ3 = 1;
	int numb_VIZ7 = 1;
	int max_numb_VIZ3 = 1;
	int max_numb_VIZ7 = 1;
	bool VIZ = false;
	slide_test_obj_data test_obj;
	void reset()
	{

		numb = 1;
		numb_VIZ3 = 1;
		numb_VIZ7 = 1;
		max_numb_VIZ3 = 1;
		max_numb_VIZ7 = 1;
		VIZ = false;
		test_obj.reset();
	}
	bool load_slide(int ID_product)
	{
		char _str[13] = { 0 };
		char s[7];
		if (ID_product<10)
			stradd(_str, "00");
		else
		if (ID_product<100)
			stradd(_str, "0");
		itoa(ID_product, s);
		stradd(_str, s);
		stradd(_str, "SL");

		if (numb<10)
			stradd(_str, "0");
		itoa(numb, s);
		stradd(_str, s);
		stradd(_str, ".txt");

		File _file = SD.open(_str, FILE_READ);
		max_numb_VIZ3 = _file.parseInt();
		max_numb_VIZ7 = _file.parseInt();
		if (VIZ)
		{
			if (max_numb_VIZ7 == 0)
			{

				_file.close();
				return false;
			}

			if (numb_VIZ7>max_numb_VIZ7 + 1)
				numb_VIZ7 = 1;
			numb_VIZ7++;

			for (int i = 1; i < (numb_VIZ7 + max_numb_VIZ3); i++)
				_file.readStringUntil('\n');
			test_obj.x = _file.parseInt();
			test_obj.y = _file.parseInt();
			test_obj.l = _file.parseInt();
			test_obj.h = _file.parseInt();
			test_obj.orient = _file.parseInt();
			test_obj.name[0] = 0;
			char _str[2] = { 0, 0 };
			switch (test_obj.orient)
			{
			case 0:
				_str[0] = 24;
				stradd(test_obj.name, _str);
				break;
			case 1:
				_str[0] = 26;
				stradd(test_obj.name, _str);
				break;
			case 2:
				_str[0] = 25;
				stradd(test_obj.name, _str);
				break;
			case 3:
				_str[0] = 27;
				stradd(test_obj.name, _str);
				break;
			default:
				_str[0] = 0;
				stradd(test_obj.name, _str);
				break;
			}
			stradd(test_obj.name, (char*)_file.readStringUntil('\n').c_str());
			_file.close();
			return true;
		}
		{
			if (max_numb_VIZ3 == 0)
			{

				_file.close();
				return false;
			}

			if (numb_VIZ3>max_numb_VIZ3)
				numb_VIZ3 = 1;
			numb_VIZ3++;

			for (int i = 1; i < (numb_VIZ3); i++)
				_file.readStringUntil('\n');
			test_obj.x = _file.parseInt();
			test_obj.y = _file.parseInt();
			test_obj.l = _file.parseInt();
			test_obj.h = _file.parseInt();
			test_obj.orient = _file.parseInt();
			test_obj.name[0] = 0;
			char _str[2] = {0,0};
			switch (test_obj.orient)
			{
			case 0:
				_str[0] = 24;
				stradd(test_obj.name, _str);
				break;
			case 1:
				_str[0] = 26;
				stradd(test_obj.name, _str);
				break;
			case 2:
				_str[0] = 25;
				stradd(test_obj.name, _str);
				break;
			case 3:
				_str[0] = 27;
				stradd(test_obj.name, _str);
				break;
			default:
				_str[0] = 0;
				stradd(test_obj.name, _str);
				break;
			}
			stradd(test_obj.name, (char*)_file.readStringUntil('\n').c_str());
			_file.close();
			return true;
		}
	}
private:
	void stradd(char s[], char add[])
	{
		int len = strlen(s);
		for (int i = 0; i <= strlen(add); i++)
			s[i + len] = add[i];
		s[strlen(s) + strlen(add) - 1] = 0;
		//s[0] = 187;
		//s[1] = 0;
	}
	void itoa(int n, char s[])
	{
		int i, sign;

		if ((sign = n) < 0)  /* записываем знак */
			n = -n;          /* делаем n положительным числом */
		i = 0;
		do {       /* генерируем цифры в обратном порядке */
			s[i++] = n % 10 + '0';   /* берем следующую цифру */
		} while ((n /= 10) > 0);     /* удаляем */
		if (sign < 0)
			s[i++] = '-';
		s[i] = '\0';
		reverse(s);
	}
	void reverse(char s[])
	{
		int i, j;
		char c;

		for (i = 0, j = strlen(s) - 1; i<j; i++, j--) {
			c = s[i];
			s[i] = s[j];
			s[j] = c;
		}
	}
};
struct pic_data
{
	int numb = 999;
	int max_numb = 0;
	char name[30] = { 0 };
	char path[13] = { 0 };
	void reset()
	{
		numb = 999;
		max_numb = 0;
		name[0] = 0;
		path[0] = 0;
	}
	bool next_step(int ID_product)
	{
		path[0] = 0;
		char s[7];
		char _str[13] = { 0 };
		if (ID_product < 10)
		{
			stradd(path, "00");
			stradd(_str, "00");
		}
		else
		if (ID_product<100)
		{
			stradd(path, "0");
			stradd(_str, "0");
		}
		itoa(ID_product, s);
		stradd(path, s);
		stradd(_str, s);
		stradd(path, "IM");
		stradd(_str, "ID");
		if (max_numb>numb)
			numb++;
		else
			numb = 1;
		if (numb < 10)
		{
			stradd(path, "0");
			stradd(_str, "0");
		}
		itoa(numb, s);
		stradd(path, s);
		stradd(_str, s);
		stradd(path, ".bmp");
		stradd(_str, ".txt");
		File _file = SD.open(_str, FILE_READ);
		name[0] = 0;
		stradd(name, (char*)_file.readStringUntil('\n').c_str());
		_file.close();
	}
private:
	void stradd(char s[], char add[])
	{
		int len = strlen(s);
		for (int i = 0; i <= strlen(add); i++)
			s[i + len] = add[i];
		s[strlen(s) + strlen(add) - 1] = 0;
		//s[0] = 187;
		//s[1] = 0;
	}
	void itoa(int n, char s[])
	{
		int i, sign;

		if ((sign = n) < 0)  /* записываем знак */
			n = -n;          /* делаем n положительным числом */
		i = 0;
		do {       /* генерируем цифры в обратном порядке */
			s[i++] = n % 10 + '0';   /* берем следующую цифру */
		} while ((n /= 10) > 0);     /* удаляем */
		if (sign < 0)
			s[i++] = '-';
		s[i] = '\0';
		reverse(s);
	}
	void reverse(char s[])
	{
		int i, j;
		char c;

		for (i = 0, j = strlen(s) - 1; i<j; i++, j--) {
			c = s[i];
			s[i] = s[j];
			s[j] = c;
		}
	}
};


struct LCD_data
{
	bool flag_pic = false;
	pic_data pic;
	slide_data slide;
	void reset()
	{
		flag_pic = false;
		pic.reset();
		slide.reset();
	}
};

class Data_Manager
{
public:
	Data_Manager(Temporary_Data& Temp_D) :Temp_D(&Temp_D){};
	Data_Manager();
	~Data_Manager();
	bool init()
	{
		if (!init_card_status)
			init_card_status = SD.begin(SD_CS);
		Serial.print("Verification SD is ");
		Serial.println(init_card_status);
		return init_card_status;
	}
	bool verification()
	{
		init_card_status = SD.begin(SD_CS);
		return (!SD_verfication) || init_card_status;
	}

	void SD_verification_on()
	{
		SD_verfication = true;
	}

	void SD_verification_of()
	{
		SD_verfication = false;
	}
	bool is_valid_file_name(char* name)
	{
		if (init_card_status && (strlen(name) != 0))
		{
			char _name[30] = { 0 };
			stradd(_name, name);
			stradd(_name, ".tsv");
			if (SD.open(_name, FILE_WRITE))
			{
				return true;
			}
			else
			{
				if (SD.exists(_name))
				{
					return true;
				}
			}
		}
		return false;
	}

	bool save_result(void)
	{
		File _file;
		Serial.println((*Temp_D).book_numb);
		if (is_valid_file_name((*Temp_D).book_numb))
		{
			Serial.println("Exist is real");
			char _str[30] = { 0 };
			stradd(_str, (*Temp_D).book_numb);
			stradd(_str, ".tsv");
			if (SD.exists(_str))
			{

				Serial.println("Yes, yes it is real");
				if (_file = SD.open(_str, FILE_WRITE))
				{


					Serial.println("And open");
					// -----------------------------------------------------------------------
					// Data and Time
					_str[0] = 196; //Д
					_str[1] = 224; //а
					_str[2] = 242; //т
					_str[3] = 224; //а
					_str[4] = 32; // 
					_str[5] = 232; //и
					_str[6] = 32; // 
					_str[7] = 194; //В
					_str[8] = 240; //р
					_str[9] = 229; //е
					_str[10] = 236; //м
					_str[11] = 255; //я
					_str[12] = 9; // tab
					_str[13] = 0; // New str

					_file.print(_str);

					_file.print((*Temp_D).data);

					_file.print(" ");

					_file.print((*Temp_D).time);

					_file.println();

					// -----------------------------------------------------------------------
					// Save surname
					_str[0] = 212; //Ф
					_str[1] = 224; //а
					_str[2] = 236; //м
					_str[3] = 232; //и
					_str[4] = 235; //л
					_str[5] = 232; //и
					_str[6] = 255; //я
					_str[7] = 9; // tab
					_str[8] = 0; // New str
					_file.print(_str);

					_file.print((*Temp_D).surname);

					_file.println();

					// -----------------------------------------------------------------------
					// Save name
					_str[0] = 200; //И
					_str[1] = 236; //м
					_str[2] = 255; //я
					_str[3] = 9; // tab
					_str[4] = 0; // New str

					_file.print(_str);

					_file.print((*Temp_D).name);

					_file.println();

					// -----------------------------------------------------------------------
					// Save middle name
					_str[0] = 206; //О
					_str[1] = 242; //т
					_str[2] = 247; //ч
					_str[3] = 229; //е
					_str[4] = 241; //с
					_str[5] = 242; //т
					_str[6] = 226; //в
					_str[7] = 238; //о
					_str[8] = 9; // tab
					_str[9] = 0; // New str

					_file.print(_str);

					_file.print((*Temp_D).middle_name);

					_file.println();

					// -----------------------------------------------------------------------
					// Save book numbeer
					_str[0] = 205; //Н
					_str[1] = 238; //о
					_str[2] = 236; //м
					_str[3] = 229; //е
					_str[4] = 240; //р
					_str[5] = 32; // 
					_str[6] = 234; //к
					_str[7] = 224; //а
					_str[8] = 240; //р
					_str[9] = 242; //т
					_str[10] = 251; //ы
					_str[11] = 9; // tab
					_str[12] = 0; // New str

					_file.print(_str);

					_file.print((*Temp_D).book_numb);

					_file.println();

					// -----------------------------------------------------------------------
					// Save OS 1 line result

					_file.print("OS\t");

					_str[0] = 209; //С
					_str[1] = 240; //р
					_str[2] = 229; //е
					_str[3] = 228; //д
					_str[4] = 237; //н
					_str[5] = 229; //е
					_str[6] = 229; //е
					_str[7] = 32; // 
					_str[8] = 231; //з
					_str[9] = 237; //н
					_str[10] = 224; //а
					_str[11] = 247; //ч
					_str[12] = 229; //е
					_str[13] = 237; //н
					_str[14] = 232; //и
					_str[15] = 229; //е
					_str[16] = 9; // tab
					_str[17] = 0; // New str

					_file.print(_str);

					_str[0] = 207; //П
					_str[1] = 238; //о
					_str[2] = 227; //г
					_str[3] = 240; //р
					_str[4] = 229; //е
					_str[5] = 248; //ш
					_str[6] = 237; //н
					_str[7] = 238; //о
					_str[8] = 241; //с
					_str[9] = 242; //т
					_str[10] = 252; //ь
					_str[11] = 9; // tab
					_str[12] = 0; // New str

					_file.print(_str);

					_str[0] = 202; //К
					_str[1] = 238; //о
					_str[2] = 235; //л
					_str[3] = 232; //и
					_str[4] = 247; //ч
					_str[5] = 229; //е
					_str[6] = 241; //с
					_str[7] = 242; //т
					_str[8] = 226; //в
					_str[9] = 238; //о
					_str[10] = 32; // 
					_str[11] = 232; //и
					_str[12] = 231; //з
					_str[13] = 236; //м
					_str[14] = 229; //е
					_str[15] = 240; //р
					_str[16] = 229; //е
					_str[17] = 237; //н
					_str[18] = 232; //и
					_str[19] = 233; //й
					_str[20] = 9; // tab
					_str[21] = 0; // New str

					_file.print(_str);

					_file.println();

					// -----------------------------------------------------------------------
					// Save OS 2 line result

					_str[0] = 193; //Б
					_str[1] = 235; //л
					_str[2] = 232; //и
					_str[3] = 230; //ж
					_str[4] = 237; //н
					_str[5] = 255; //я
					_str[6] = 255; //я
					_str[7] = 32; // 
					_str[8] = 227; //г
					_str[9] = 240; //р
					_str[10] = 224; //а
					_str[11] = 237; //н
					_str[12] = 252; //ь
					_str[13] = 9; // tab
					_str[14] = 0; // New str

					_file.print(_str);

					_file.print((*Temp_D).m_eye.os_n.seq.average());
					_file.print("\t");

					_file.print((*Temp_D).m_eye.os_n.seq.error());
					_file.print("\t");

					_file.print((*Temp_D).m_eye.os_n.seq.getsize());

					_file.println();

					// -----------------------------------------------------------------------
					// Save OS 3 line result

					_str[0] = 196; //Д
					_str[1] = 224; //а
					_str[2] = 235; //л
					_str[3] = 252; //ь
					_str[4] = 237; //н
					_str[5] = 255; //я
					_str[6] = 255; //я
					_str[7] = 32; // 
					_str[8] = 227; //г
					_str[9] = 240; //р
					_str[10] = 224; //а
					_str[11] = 237; //н
					_str[12] = 252; //ь
					_str[13] = 9; // tab
					_str[14] = 0; // New str

					_file.print(_str);

					_file.print((*Temp_D).m_eye.os_f.seq.average());
					_file.print("\t");

					_file.print((*Temp_D).m_eye.os_f.seq.error());
					_file.print("\t");

					_file.print((*Temp_D).m_eye.os_f.seq.getsize());

					_file.println();

					// -----------------------------------------------------------------------
					// Save OD 4 line result

					_file.print("OD\t");

					_str[0] = 209; //С
					_str[1] = 240; //р
					_str[2] = 229; //е
					_str[3] = 228; //д
					_str[4] = 237; //н
					_str[5] = 229; //е
					_str[6] = 229; //е
					_str[7] = 32; // 
					_str[8] = 231; //з
					_str[9] = 237; //н
					_str[10] = 224; //а
					_str[11] = 247; //ч
					_str[12] = 229; //е
					_str[13] = 237; //н
					_str[14] = 232; //и
					_str[15] = 229; //е
					_str[16] = 9; // tab
					_str[17] = 0; // New str

					_file.print(_str);

					_str[0] = 207; //П
					_str[1] = 238; //о
					_str[2] = 227; //г
					_str[3] = 240; //р
					_str[4] = 229; //е
					_str[5] = 248; //ш
					_str[6] = 237; //н
					_str[7] = 238; //о
					_str[8] = 241; //с
					_str[9] = 242; //т
					_str[10] = 252; //ь
					_str[11] = 9; // tab
					_str[12] = 0; // New str

					_file.print(_str);

					_str[0] = 202; //К
					_str[1] = 238; //о
					_str[2] = 235; //л
					_str[3] = 232; //и
					_str[4] = 247; //ч
					_str[5] = 229; //е
					_str[6] = 241; //с
					_str[7] = 242; //т
					_str[8] = 226; //в
					_str[9] = 238; //о
					_str[10] = 32; // 
					_str[11] = 232; //и
					_str[12] = 231; //з
					_str[13] = 236; //м
					_str[14] = 229; //е
					_str[15] = 240; //р
					_str[16] = 229; //е
					_str[17] = 237; //н
					_str[18] = 232; //и
					_str[19] = 233; //й
					_str[20] = 9; // tab
					_str[21] = 0; // New str

					_file.print(_str);

					_file.println();

					// -----------------------------------------------------------------------
					// Save OD 5 line result

					_str[0] = 193; //Б
					_str[1] = 235; //л
					_str[2] = 232; //и
					_str[3] = 230; //ж
					_str[4] = 237; //н
					_str[5] = 255; //я
					_str[6] = 255; //я
					_str[7] = 32; // 
					_str[8] = 227; //г
					_str[9] = 240; //р
					_str[10] = 224; //а
					_str[11] = 237; //н
					_str[12] = 252; //ь
					_str[13] = 9; // tab
					_str[14] = 0; // New str

					_file.print(_str);

					_file.print((*Temp_D).m_eye.od_n.seq.average());
					_file.print("\t");

					_file.print((*Temp_D).m_eye.od_n.seq.error());
					_file.print("\t");

					_file.print((*Temp_D).m_eye.od_n.seq.getsize());

					_file.println();

					// -----------------------------------------------------------------------
					// Save OD 6 line result

					_str[0] = 196; //Д
					_str[1] = 224; //а
					_str[2] = 235; //л
					_str[3] = 252; //ь
					_str[4] = 237; //н
					_str[5] = 255; //я
					_str[6] = 255; //я
					_str[7] = 32; // 
					_str[8] = 227; //г
					_str[9] = 240; //р
					_str[10] = 224; //а
					_str[11] = 237; //н
					_str[12] = 252; //ь
					_str[13] = 9; // tab
					_str[14] = 0; // New str

					_file.print(_str);

					_file.print((*Temp_D).m_eye.od_f.seq.average());
					_file.print("\t");

					_file.print((*Temp_D).m_eye.od_f.seq.error());
					_file.print("\t");

					_file.print((*Temp_D).m_eye.od_f.seq.getsize());

					_file.println();

					// -----------------------------------------------------------------------
					// Save Time training

					_str[0] = 210; //Т
					_str[1] = 240; //р
					_str[2] = 229; //е
					_str[3] = 237; //н
					_str[4] = 232; //и
					_str[5] = 240; //р
					_str[6] = 238; //о
					_str[7] = 226; //в
					_str[8] = 234; //к
					_str[9] = 224; //а
					_str[10] = 9; // tab
					_str[11] = 0; // New str

					_file.print(_str);

					_str[0] = 193; //Б
					_str[1] = 235; //л
					_str[2] = 232; //и
					_str[3] = 230; //ж
					_str[4] = 237; //н
					_str[5] = 255; //я
					_str[6] = 255; //я
					_str[7] = 32; // 
					_str[8] = 227; //г
					_str[9] = 240; //р
					_str[10] = 224; //а
					_str[11] = 237; //н
					_str[12] = 252; //ь
					_str[13] = 9; // tab
					_str[14] = 0; // New str

					_file.print(_str);

					_str[0] = 196; //Д
					_str[1] = 224; //а
					_str[2] = 235; //л
					_str[3] = 252; //ь
					_str[4] = 237; //н
					_str[5] = 255; //я
					_str[6] = 255; //я
					_str[7] = 32; // 
					_str[8] = 227; //г
					_str[9] = 240; //р
					_str[10] = 224; //а
					_str[11] = 237; //н
					_str[12] = 252; //ь
					_str[13] = 9; // tab
					_str[14] = 0; // New str

					_file.print(_str);

					_str[0] = 194; //В
					_str[1] = 240; //р
					_str[2] = 229; //е
					_str[3] = 236; //м
					_str[4] = 255; //я
					_str[5] = 9; // tab
					_str[6] = 0; // New str

					_file.print(_str);
					_file.println();

					_str[0] = 79; //O
					_str[1] = 83; //S
					_str[2] = 9; // tab
					_str[3] = 0; // New str

					_file.print(_str);

					if ((*Temp_D).t_eye.os_n.seq.getsize()<3)_file.print("*");
					_file.print((*Temp_D).t_eye.os_n.seq.average());
					_file.print("\t");

					if ((*Temp_D).t_eye.os_f.seq.getsize()<3)_file.print("*");
					_file.print((*Temp_D).t_eye.os_f.seq.average());
					_file.print("\t");

					_file.print(get_time((*Temp_D).t_eye.setup_time_os - (*Temp_D).t_eye.time_spend_os));
					_file.println();


					_str[0] = 79; //O
					_str[1] = 68; //D
					_str[2] = 9; // tab
					_str[3] = 0; // New str

					_file.print(_str);

					if ((*Temp_D).t_eye.od_n.seq.getsize()<3)_file.print("*");
					_file.print((*Temp_D).t_eye.od_n.seq.average());
					_file.print("\t");

					if ((*Temp_D).t_eye.od_f.seq.getsize()<3)_file.print("*");
					_file.print((*Temp_D).t_eye.od_f.seq.average());
					_file.print("\t");

					_file.print(get_time((*Temp_D).t_eye.setup_time_od - (*Temp_D).t_eye.time_spend_od));
					_file.println();

					_file.println();


					_file.close();

					_str[0] = 82; //R
					_str[1] = 69; //E
					_str[2] = 67; //C
					_str[3] = 95; //_
					_str[4] = 76; //L
					_str[5] = 73; //I
					_str[6] = 83; //S
					_str[7] = 84; //T
					_str[8] = 0; // New str

					stradd(_str, ".tsv");
					if (_file = SD.open(_str, FILE_WRITE))
					{
						Serial.println("Yes, Writing");
						_file.print((*Temp_D).book_numb);
						_file.print("\t");
						_file.print((*Temp_D).surname);
						_file.print("\t");
						_file.print((*Temp_D).name);
						_file.print("\t");
						_file.print((*Temp_D).middle_name);
						_file.print("\n");

						_file.close();
						return true;
					}
				}

			}
		}
		return false;
	}
	LCD_data LCD_Data;
private:
	Temporary_Data* Temp_D;
	bool init_card_status = false;
	bool SD_verfication = true;
	void stradd(char s[], char add[])
	{
		int len = strlen(s);
		for (int i = 0; i <= strlen(add); i++)
			s[i + len] = add[i];
		s[strlen(s) + strlen(add) - 1] = 0;
		//s[0] = 187;
		//s[1] = 0;
	}
	char s[7];
	void itoa(int n, char s[])
	{
		int i, sign;

		if ((sign = n) < 0)  /* записываем знак */
			n = -n;          /* делаем n положительным числом */
		i = 0;
		do {       /* генерируем цифры в обратном порядке */
			s[i++] = n % 10 + '0';   /* берем следующую цифру */
		} while ((n /= 10) > 0);     /* удаляем */
		if (sign < 0)
			s[i++] = '-';
		s[i] = '\0';
		reverse(s);
	}
	void reverse(char s[])
	{
		int i, j;
		char c;

		for (i = 0, j = strlen(s) - 1; i<j; i++, j--) {
			c = s[i];
			s[i] = s[j];
			s[j] = c;
		}
	}
	const char* get_time(int count)
	{
		s[0] = 0;
		char mm[3];
		char ss[3];
		int var1 = (count / 60) % 60;
		int var2 = count % 60;
		itoa(var1, mm);
		itoa(var2, ss);
		strcat(s, mm);
		strcat(s, ":");
		strcat(s, ss);
		return s;
	}

};
#endif