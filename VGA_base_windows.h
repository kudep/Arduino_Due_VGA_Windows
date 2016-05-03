
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


#endif