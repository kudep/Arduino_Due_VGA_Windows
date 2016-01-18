#include"cntrlsubgroup.h"

CntrlSubGroup::CntrlSubGroup()
{
}

CntrlSubGroup::~CntrlSubGroup()
{
}
void CntrlSubGroup::refresh()
{
	ISG.update();
	modification = false;
}
void CntrlSubGroup::update()
{
	if (modification)ISG.update();
	modification = false;
}
bool CntrlSubGroup::strcpy_center_text(const char*_text)
{
	if (metric.height*metric.width > strlen(_text))
	{
		if (metric.height == 1)
		{
			add_space((metric.width - strlen(_text)) / 2);
			strcat(text, _text);
		}
		else
			strcpy(text, _text);
		modification = true;
		return true;
	}
	else
		return false;
}
bool CntrlSubGroup::strcpy_center_text(int _ntext)
{
	char _text[string_length];
	itoa(_ntext, _text);
	if (metric.height*metric.width > strlen(_text) + 1)
	{
		if (metric.height == 1)
		{
			add_space((metric.width - strlen(_text)) / 2);
			strcat(text, _text);
		}
		else
			strcpy(text, _text);
		modification = true;
		return true;
	}
	else
		return false;
}
bool CntrlSubGroup::strcpy_text(const char*_text)
{
	if (metric.height*metric.width > strlen(_text))
	{
		strcpy(text, _text);
		modification = true;
		return true;
	}
	else
		return false;
}
bool CntrlSubGroup::strcpy_text(int _ntext)
{
	char _text[string_length];
	itoa(_ntext, _text);
	if (metric.height*metric.width > strlen(_text)) 
	{
		strcpy(text, _text);
		modification = true;
		return true;
	}
	else
		return false;
}
void CntrlSubGroup::enable()
{
	state.enable();
	modification = true;
}
void CntrlSubGroup::disable()
{
	state.disable();
	modification = true;
}
void CntrlSubGroup::state_switch()
{
	state.reverse();
	modification = true;
}
void CntrlSubGroup::add_space(int n)
{
	for (size_t i = 0; i < n; i++)
		text[i] = ' ';
	text[n] = 0;
}
void CntrlSubGroup::itoa(int n, char s[])
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
void CntrlSubGroup::reverse(char s[])
{
	int i, j;
	char c;

	for (i = 0, j = strlen(s) - 1; i<j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}