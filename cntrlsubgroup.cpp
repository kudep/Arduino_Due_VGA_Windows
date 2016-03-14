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
bool CntrlSubGroup::strcpy_center_text(float _ftext, int afterpoint)
{
	char _text[string_length];
	ftoa(_ftext, _text, afterpoint);
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
bool CntrlSubGroup::strcpy_text(float _ftext, int afterpoint)
{
	char _text[string_length];
	ftoa(_ftext, _text, afterpoint);
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
// Converts a floating point number to string.
void CntrlSubGroup::ftoa(float f, char s[], int afterpoint)
{
	// Extract integer part
	int ipart = (int)f;

	// Extract floating part
	float fpart = f - (float)ipart;
	if (fpart < 0)
		fpart = -fpart;
	// convert integer part to string

	char _texti[string_length];
	itoa(ipart, _texti);

	// check for display option after point
	for (int i = 0; i < afterpoint; i++)
	{
		fpart *= 10;
	}
	// convert float part to string

	char _textf[string_length];
	itoa(fpart, _textf);
	s[0] = 0;
	stradd(s, _texti);
	stradd(s, ".");
	stradd(s, _textf);
}
void  CntrlSubGroup::stradd(char s[], char add[])
{
	int len = strlen(s);
	for (int i = 0; i <= strlen(add); i++)
		s[i + len] = add[i];
	s[strlen(s) + strlen(add)-1] = 0;
	//s[0] = 187;
	//s[1] = 0;
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


CntrlSubGroup_Extended_string::CntrlSubGroup_Extended_string()
{
}

CntrlSubGroup_Extended_string::~CntrlSubGroup_Extended_string()
{
}
void CntrlSubGroup_Extended_string::refresh()
{
	ISG.update();
	modification = false;
}
void CntrlSubGroup_Extended_string::update()
{
	if (modification)ISG.update();
	modification = false;
}
bool CntrlSubGroup_Extended_string::strcpy_center_text(const char*_text)
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
bool CntrlSubGroup_Extended_string::strcpy_center_text(int _ntext)
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
bool CntrlSubGroup_Extended_string::strcpy_text(const char*_text)
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
bool CntrlSubGroup_Extended_string::strcpy_text(int _ntext)
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
void CntrlSubGroup_Extended_string::enable()
{
	state.enable();
	modification = true;
}
void CntrlSubGroup_Extended_string::disable()
{
	state.disable();
	modification = true;
}
void CntrlSubGroup_Extended_string::state_switch()
{
	state.reverse();
	modification = true;
}
void CntrlSubGroup_Extended_string::add_space(int n)
{
	for (size_t i = 0; i < n; i++)
		text[i] = ' ';
	text[n] = 0;
}
void CntrlSubGroup_Extended_string::itoa(int n, char s[])
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
void CntrlSubGroup_Extended_string::reverse(char s[])
{
	int i, j;
	char c;

	for (i = 0, j = strlen(s) - 1; i<j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}






















