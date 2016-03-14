
#ifndef VGA_BASE_WINDOWS_H_INCLUDED
#define VGA_BASE_WINDOWS_H_INCLUDED
#include <VGA.h>
#include"cntrlsubgroup.h"
#include"database_structure.h"
#define POINT_AFTER_COMMA 2
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