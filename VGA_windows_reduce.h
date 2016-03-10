
#ifndef WINDOWS_H_INCLUDED
#define WINDOWS_H_INCLUDED
#include <VGA.h>
#include"cntrlsubgroup.h"


class Win
{
public:
	Win();
	~Win();

protected:
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
	void get_time(int count)
	{
		s[0] = 0;
		char hh[3];
		char mm[3];
		int var1 = (count / 60) % 24;
		int var2 = count % 60;
		itoa(var1, hh);
		itoa(var2, mm);
		strcat(s, hh);
		strcat(s, ":");
		strcat(s, mm);
	}

	char flag[2];
	char s[7];
};

class Win_help:Win
{
public:
	Win_help();
	~Win_help();
	void update()
	{
		for (size_t i = 0; i < sizeof(parr) / 4; i++)
		{
			(*parr[i]).update();
		}
	}
	void refresh()
	{
		for (size_t i = 0; i < sizeof(parr) / 4; i++)
		{
			(*parr[i]).refresh();
		}
	}
	//void set_time(int count)
	//{
	//	get_time(count);
	//	data_time4.strcpy_center_text(s);
	//}

	CntrlSubGroup background;
	CntrlSubGroup title;
	CntrlSubGroup text;
private:
	void windows()
	{
		text.strcpy_center_text("Supporting information...");
	}

	static const int Top_shift1 = 4;
	static const int Top_shift2 = Top_shift1 + 1;
	static const int Top_shift3 = Top_shift2 + 2;

	static const int width_shift1 = 32;
	static const int width_shift2 = width_shift1-2;

	static const int Left_shift1 = 4;
	static const int Left_shift2 = Left_shift1 + 1;

	static const int Height_shift1 = 22;
	static const int Height_shift2 = Height_shift1-4;



	CntrlSubGroup* parr[3] =
	{
		&background,
		&title,
		&text
	};

};

class Win_Data:Win
{
public:
	Win_Data();
	~Win_Data();
	void update()
	{
		for (size_t i = 0; i < sizeof(parr) / 4; i++)
		{
			(*parr[i]).update();
		}
	}
	void refresh()
	{
		for (size_t i = 0; i < sizeof(parr) / 4; i++)
		{
			(*parr[i]).refresh();
		}
	}
	//void set_time(int count)
	//{
	//	get_time(count);
	//	data_time4.strcpy_center_text(s);
	//}

	//1 string
	CntrlSubGroup data_time0;
	CntrlSubGroup data_time1;

	//2 string
	CntrlSubGroup surname0;
	CntrlSubGroup surname1;

	//3 string
	CntrlSubGroup name0;
	CntrlSubGroup name1;

	//4 string
	CntrlSubGroup middle_name0;
	CntrlSubGroup middle_name1;

	//5 string
	CntrlSubGroup book_numb0;
	CntrlSubGroup book_numb1;

	//Extend button
	CntrlSubGroup extend_button0;
	CntrlSubGroup extend_button1;
	CntrlSubGroup extend_button2;
	CntrlSubGroup extend_button3;
	CntrlSubGroup extend_button4;

	CntrlSubGroup extend_button_description0;
	CntrlSubGroup extend_button_description1;
	CntrlSubGroup extend_button_description2;
	CntrlSubGroup extend_button_description3;
	CntrlSubGroup extend_button_description4;
private:
	void windows()
	{
		char str_data_time0[13] = { 49, 46, 196, 224, 242, 224, 47, 194, 240, 229, 236, 255, 0 };//1.Дата/Время
		data_time0.strcpy_text(str_data_time0);
		data_time1.strcpy_center_text("10.03.16 0:0");


		char str_surname0[13] = { 32, 32, 32, 50, 46, 212, 224, 236, 232, 235, 232, 255, 0 };//   2.Фамилия
		surname0.strcpy_text(str_surname0);
		surname1.strcpy_center_text("Kuznetsov");

		char str_name0[13] = { 32, 32, 32, 32, 32, 32, 32, 51, 46, 200, 236, 255, 0 };//       3.Имя
		name0.strcpy_text(str_name0);
		name1.strcpy_center_text("Denis");

		char str_middle_name0[13] = { 32, 32, 52, 46, 206, 242, 247, 229, 241, 242, 226, 238, 0 };//  4.Отчество
		middle_name0.strcpy_text(str_middle_name0);
		middle_name1.strcpy_center_text("Pavlovich");

		char str_book_numb0[13] = { 32, 32, 32, 53, 46, 35, 32, 234, 224, 240, 242, 251, 0 };//   5.# карты
		book_numb0.strcpy_text(str_book_numb0);
		book_numb1.strcpy_center_text("1251");


		char str_extend_button_description0[8] = { 207, 238, 236, 238, 249, 252, 0 };//Помощь
		extend_button_description0.strcpy_center_text(str_extend_button_description0);

		char str_extend_button_description1[8] = { 209, 225, 240, 238, 241, 0 };//Сброс
		extend_button_description1.strcpy_center_text(str_extend_button_description1);

		char str_extend_button_description2[8] = { 196, 224, 235, 229, 229, 0 };//Далее
		extend_button_description2.strcpy_center_text(str_extend_button_description2);


	}

	CntrlSubGroup* parr[20] = { &data_time0, &data_time1, &surname0, &surname1, &name0, &name1, &middle_name0,  &middle_name1, &book_numb0, &book_numb1, &extend_button0, &extend_button1, &extend_button2, &extend_button3, &extend_button4, &extend_button_description0, &extend_button_description1, &extend_button_description2, &extend_button_description3, &extend_button_description4 };
	

};


class Win2:Win
{
public:
	Win2();
	~Win2();
	void update()
	{
		for (size_t i = 0; i < sizeof(parr) / 4; i++)
		{
			(*parr[i]).update();
		}
	}
	void refresh()
	{
		for (size_t i = 0; i < sizeof(parr) / 4; i++)
		{
			(*parr[i]).refresh();
		}
	}
	//void set_time(int count)
	//{
	//	get_time(count);
	//	data_time4.strcpy_center_text(s);
	//}

	CntrlSubGroup measurement_mode;
	CntrlSubGroup measurement_mode1x1;
	CntrlSubGroup measurement_mode_field1x1;
	CntrlSubGroup measurement_mode2x1;
	CntrlSubGroup measurement_mode_field2x1;
	CntrlSubGroup measurement_mode1x2;
	CntrlSubGroup measurement_mode_field1x2;
	CntrlSubGroup measurement_mode2x2;
	CntrlSubGroup measurement_mode_field2x2;

	CntrlSubGroup training_mode;
	CntrlSubGroup training_mode1x1;
	CntrlSubGroup training_mode_field1x1;
	CntrlSubGroup training_mode1x2;
	CntrlSubGroup training_mode_field1x2;
	CntrlSubGroup training_mode2x2;
	CntrlSubGroup training_mode_field2x2;
	CntrlSubGroup training_mode1x3;
	CntrlSubGroup training_mode_field1x3;
	CntrlSubGroup training_mode2x3;
	CntrlSubGroup training_mode_field2x3;

	CntrlSubGroup start_finish1x1;
	CntrlSubGroup start_finish_field1x1;
	CntrlSubGroup start_finish2x1;
	CntrlSubGroup start_finish_field2x1;

	CntrlSubGroup extend_button0;
	CntrlSubGroup extend_button1;
	CntrlSubGroup extend_button2;
	CntrlSubGroup extend_button3;
	CntrlSubGroup extend_button4;

	CntrlSubGroup extend_button_description0;
	CntrlSubGroup extend_button_description1;
	CntrlSubGroup extend_button_description2;
	CntrlSubGroup extend_button_description3;
	CntrlSubGroup extend_button_description4;
private:
	void windows()
	{

		measurement_mode_field1x1.strcpy_center_text(flag);
		measurement_mode_field2x1.strcpy_center_text("");
		measurement_mode_field1x2.strcpy_center_text(flag);
		measurement_mode_field2x2.strcpy_center_text("");

		training_mode_field1x1.strcpy_center_text("16.5");
		training_mode_field1x2.strcpy_center_text(flag);
		training_mode_field2x2.strcpy_center_text("");
		training_mode_field1x3.strcpy_center_text(flag);
		training_mode_field2x3.strcpy_center_text("");

		start_finish_field1x1.strcpy_center_text("18:20");
		start_finish_field2x1.strcpy_center_text("18:36");

	}
	static const subgroup_function sg_f = information;

	static const int Top_shift1 = 2;
	static const int Top_shift2 = Top_shift1+9;
	static const int Top_shift3 = Top_shift2+10;

	static const int width_shift1 = 18;
	static const int width_shift2 = 14;
	static const int width_shift3 = 3;
	static const int width_shift4 = 8;

	static const int Left_shift0 = 11;
	static const int Left_shift1 = 1;
	static const int Left_shift2 = Left_shift1+width_shift2 + 1;
	static const int Left_shift3 = Left_shift2 + width_shift3 + 1;
	static const int Left_shift4 = Left_shift3 + width_shift2 + 1;



	CntrlSubGroup* parr[34] = 
	{ 
		&measurement_mode, 
		&measurement_mode1x1, &measurement_mode_field1x1, 
		&measurement_mode2x1, &measurement_mode_field2x1, 
		&measurement_mode1x2, &measurement_mode_field1x2, 
		&measurement_mode2x2, &measurement_mode_field2x2,

		&training_mode, 
		&training_mode1x1, &training_mode_field1x1, 
		&training_mode1x2, &training_mode_field1x2, 
		&training_mode2x2, &training_mode_field2x2,
		&training_mode1x3, &training_mode_field1x3,
		&training_mode2x3, &training_mode_field2x3,

		&start_finish1x1, &start_finish_field1x1,
		&start_finish2x1, &start_finish_field2x1,

		&extend_button0, 
		&extend_button1, 
		&extend_button2, 
		&extend_button3, 
		&extend_button4, 

		&extend_button_description0, 
		&extend_button_description1, 
		&extend_button_description2, 
		&extend_button_description3, 
		&extend_button_description4 
	};

};


#endif