
#ifndef WINDOWS_H_INCLUDED
#define WINDOWS_H_INCLUDED
#include <VGA.h>
#include"cntrlsubgroup.h"
class Win1
{
public:
	Win1();
	~Win1();
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
	void set_time(int count)
	{
		get_time(count);
		data_time4.strcpy_center_text(s);
	}

	CntrlSubGroup data_time1;
	CntrlSubGroup data_time2;
	CntrlSubGroup data_time3;
	CntrlSubGroup data_time4;

	CntrlSubGroup full_name;
	CntrlSubGroup surname;
	CntrlSubGroup surname1;
	CntrlSubGroup name;
	CntrlSubGroup name1;
	CntrlSubGroup middle_name;
	CntrlSubGroup middle_name1;

	CntrlSubGroup eye_ametropia;
	CntrlSubGroup OD;
	CntrlSubGroup OD1;
	CntrlSubGroup OD2;
	CntrlSubGroup OD3;

	CntrlSubGroup OS;
	CntrlSubGroup OS1;
	CntrlSubGroup OS2;
	CntrlSubGroup OS3;

	CntrlSubGroup extern_button0;
	CntrlSubGroup extern_button1;
	CntrlSubGroup extern_button2;
	CntrlSubGroup extern_button3;
	CntrlSubGroup extern_button4;

	CntrlSubGroup extern_button_description0;
	CntrlSubGroup extern_button_description1;
	CntrlSubGroup extern_button_description2;
	CntrlSubGroup extern_button_description3;
	CntrlSubGroup extern_button_description4;
private:
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
	void windows()
	{

		data_time2.strcpy_center_text("2015.12.31");
		data_time4.strcpy_center_text("0:0");

		surname1.strcpy_center_text("Kuznetsov");
		name1.strcpy_center_text("Denis");
		middle_name1.strcpy_center_text("Pavlovich");

		OD1.strcpy_center_text(flag);
		OD2.strcpy_center_text("10.5");
		OD3.strcpy_center_text("-3.2");

		OS1.strcpy_center_text(flag);
		OS2.strcpy_center_text("10.5");
		OS3.strcpy_center_text("-3.2");
		data_time4.strcpy_center_text(s);

	}
	static const subgroup_function sg_f = button;

	CntrlSubGroup* parr[30] = { &data_time1, &data_time2, &data_time3, &data_time4, &full_name, &surname, &surname1, &name, &name1, &middle_name, &middle_name1, &eye_ametropia, &OD, &OD1, &OD2, &OD3, &OS, &OS1, &OS2, &OS3, &extern_button0, &extern_button1, &extern_button2, &extern_button3, &extern_button4, &extern_button_description0, &extern_button_description1, &extern_button_description2, &extern_button_description3, &extern_button_description4 };
	char flag[2];
	char s[7];

};


class Win2
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
	void set_time(int count)
	{
		get_time(count);
		data_time4.strcpy_center_text(s);
	}

	CntrlSubGroup data_time1;
	CntrlSubGroup data_time2;
	CntrlSubGroup data_time3;
	CntrlSubGroup data_time4;

	CntrlSubGroup full_name;
	CntrlSubGroup surname;
	CntrlSubGroup surname1;
	CntrlSubGroup name;
	CntrlSubGroup name1;
	CntrlSubGroup middle_name;
	CntrlSubGroup middle_name1;

	CntrlSubGroup eye_ametropia;
	CntrlSubGroup OD;
	CntrlSubGroup OD1;
	CntrlSubGroup OD2;
	CntrlSubGroup OD3;

	CntrlSubGroup OS;
	CntrlSubGroup OS1;
	CntrlSubGroup OS2;
	CntrlSubGroup OS3;

	CntrlSubGroup extern_button0;
	CntrlSubGroup extern_button1;
	CntrlSubGroup extern_button2;
	CntrlSubGroup extern_button3;
	CntrlSubGroup extern_button4;

	CntrlSubGroup extern_button_description0;
	CntrlSubGroup extern_button_description1;
	CntrlSubGroup extern_button_description2;
	CntrlSubGroup extern_button_description3;
	CntrlSubGroup extern_button_description4;
private:
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
	void windows()
	{

		data_time2.strcpy_center_text("2015.12.31");
		data_time4.strcpy_center_text("0:0");

		surname1.strcpy_center_text("Kuznetsov");
		name1.strcpy_center_text("Denis");
		middle_name1.strcpy_center_text("Pavlovich");

		OD1.strcpy_center_text(flag);
		OD2.strcpy_center_text("10.5");
		OD3.strcpy_center_text("-3.2");

		OS1.strcpy_center_text(flag);
		OS2.strcpy_center_text("10.5");
		OS3.strcpy_center_text("-3.2");
		data_time4.strcpy_center_text(s);

	}
	static const subgroup_function sg_f = information;

	CntrlSubGroup* parr[30] = { &data_time1, &data_time2, &data_time3, &data_time4, &full_name, &surname, &surname1, &name, &name1, &middle_name, &middle_name1, &eye_ametropia, &OD, &OD1, &OD2, &OD3, &OS, &OS1, &OS2, &OS3, &extern_button0, &extern_button1, &extern_button2, &extern_button3, &extern_button4, &extern_button_description0, &extern_button_description1, &extern_button_description2, &extern_button_description3, &extern_button_description4 };
	char flag[2];
	char s[7];

};


#endif