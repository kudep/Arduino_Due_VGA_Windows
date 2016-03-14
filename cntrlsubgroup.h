
#ifndef CNTRLSUBGROUP_H_INCLUDED
#define CNTRLSUBGROUP_H_INCLUDED
#include <VGA.h>
#include <string.h>
#include "intrfsubgroup.h"

class CntrlSubGroup
{
public:
	CntrlSubGroup(Color_Style style, Metric_Parameters metric) :ISG(IntrfSubGroup_Init_Parameters(style, metric, &state, text)), metric(metric), state(false), modification(false){};
	CntrlSubGroup(Color_Style style, Metric_Parameters metric, const char*_text) :ISG(IntrfSubGroup_Init_Parameters(style, metric, &state, text)), metric(metric), state(false), modification(false){ strcpy_center_text(_text); };
	CntrlSubGroup(Color_Style style, Metric_Parameters metric, int _text) :ISG(IntrfSubGroup_Init_Parameters(style, metric, &state, text)), metric(metric), state(false), modification(false){ strcpy_center_text(_text); };

	CntrlSubGroup(Color_Style style, Metric_Parameters metric, const char*_text, bool center) :ISG(IntrfSubGroup_Init_Parameters(style, metric, &state, text)), metric(metric), state(false), modification(false)
	{
		if (center)
			strcpy_center_text(_text);
		else
			strcpy_text(_text);
	};
	CntrlSubGroup(Color_Style style, Metric_Parameters metric, int _text, bool center) :ISG(IntrfSubGroup_Init_Parameters(style, metric, &state, text)), metric(metric), state(false), modification(false)
	{
		if (center)
			strcpy_center_text(_text);
		else
			strcpy_text(_text);
	}
	CntrlSubGroup();
	~CntrlSubGroup();
	void refresh();
	void update();
	bool strcpy_center_text(const char* _text);
	bool strcpy_center_text(int _ntext);
	bool strcpy_center_text(float _ftext, int afterpoint);
	bool strcpy_text(const char* _text);
	bool strcpy_text(int _ntext);
	bool strcpy_text(float _ftext, int afterpoint);
	void enable();
	void disable();
	void state_switch();

private:
	void add_space(int n);
	void ftoa(float f, char s[], int afterpoint);
	void itoa(int n, char s[]);
	void reverse(char s[]);
	void stradd(char s[], char add[]);
	static const int string_length = 26;
	IntrfSubGroup ISG;
	Metric_Parameters metric;
	IntrfSubGroup_State state;
	char text[string_length];
	bool modification;
};

class CntrlSubGroup_Extended_string
{
public:
	CntrlSubGroup_Extended_string(Color_Style style, Metric_Parameters metric) :ISG(IntrfSubGroup_Init_Parameters(style, metric, &state, text)), metric(metric), state(false), modification(false){};
	CntrlSubGroup_Extended_string(Color_Style style, Metric_Parameters metric, const char*_text) :ISG(IntrfSubGroup_Init_Parameters(style, metric, &state, text)), metric(metric), state(false), modification(false){ strcpy_center_text(_text); };
	CntrlSubGroup_Extended_string(Color_Style style, Metric_Parameters metric, int _text) :ISG(IntrfSubGroup_Init_Parameters(style, metric, &state, text)), metric(metric), state(false), modification(false){ strcpy_center_text(_text); };

	CntrlSubGroup_Extended_string(Color_Style style, Metric_Parameters metric, const char*_text, bool center) :ISG(IntrfSubGroup_Init_Parameters(style, metric, &state, text)), metric(metric), state(false), modification(false)
	{
		if (center)
			strcpy_center_text(_text);
		else
			strcpy_text(_text);
	};
	CntrlSubGroup_Extended_string(Color_Style style, Metric_Parameters metric, int _text, bool center) :ISG(IntrfSubGroup_Init_Parameters(style, metric, &state, text)), metric(metric), state(false), modification(false)
	{
		if (center)
			strcpy_center_text(_text);
		else
			strcpy_text(_text);
	}
	CntrlSubGroup_Extended_string();
	~CntrlSubGroup_Extended_string();
	void refresh();
	void update();
	bool strcpy_center_text(const char* _text);
	bool strcpy_center_text(int _ntext);
	bool strcpy_text(const char* _text);
	bool strcpy_text(int _ntext);
	void enable();
	void disable();
	void state_switch();

private:
	void add_space(int n);
	void itoa(int n, char s[]);
	void reverse(char s[]);
	static const int string_length = 350;
	IntrfSubGroup ISG;
	Metric_Parameters metric;
	IntrfSubGroup_State state;
	char text[string_length];
	bool modification;
};

#endif