
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
	CntrlSubGroup();
	~CntrlSubGroup();
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
	static const int string_length = 20;
	IntrfSubGroup ISG;
	Metric_Parameters metric;
	IntrfSubGroup_State state;
	char text[string_length];
	bool modification;
};

#endif