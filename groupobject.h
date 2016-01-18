
#ifndef GROUPOBJECT_H_INCLUDED
#define GROUPOBJECT_H_INCLUDED
#include <VGA.h>
#include <string.h>
#include "intrfgroup.h"

const int max_subgroup_count_value = 10;
//IntrfSubGroup intrfgroup[subgroup_count];
struct Proportion_System
{
	Proportion_System(uint8_t n0, uint8_t n1, uint8_t n2, uint8_t n3, uint8_t n4, uint8_t n5, uint8_t n6, uint8_t n7, uint8_t n8, uint8_t n9)
	{
		_proproportion_arr[0] = (Proportion)n0 / 100;
		_proproportion_arr[1] = (Proportion)n1 / 100;
		_proproportion_arr[2] = (Proportion)n2 / 100;
		_proproportion_arr[3] = (Proportion)n3 / 100;
		_proproportion_arr[4] = (Proportion)n4 / 100;
		_proproportion_arr[5] = (Proportion)n5 / 100;
		_proproportion_arr[6] = (Proportion)n6 / 100;
		_proproportion_arr[7] = (Proportion)n7 / 100;
		_proproportion_arr[8] = (Proportion)n8 / 100;
		_proproportion_arr[9] = (Proportion)n9 / 100;
	};
	Proportion_System(uint8_t n0, uint8_t n1, uint8_t n2, uint8_t n3, uint8_t n4, uint8_t n5, uint8_t n6, uint8_t n7, uint8_t n8)
	{
		_proproportion_arr[0] = (Proportion)n0 / 100;
		_proproportion_arr[1] = (Proportion)n1 / 100;
		_proproportion_arr[2] = (Proportion)n2 / 100;
		_proproportion_arr[3] = (Proportion)n3 / 100;
		_proproportion_arr[4] = (Proportion)n4 / 100;
		_proproportion_arr[5] = (Proportion)n5 / 100;
		_proproportion_arr[6] = (Proportion)n6 / 100;
		_proproportion_arr[7] = (Proportion)n7 / 100;
		_proproportion_arr[8] = (Proportion)n8 / 100;
	};
	Proportion_System(uint8_t n0, uint8_t n1, uint8_t n2, uint8_t n3, uint8_t n4, uint8_t n5, uint8_t n6, uint8_t n7)
	{
		_proproportion_arr[0] = (Proportion)n0 / 100;
		_proproportion_arr[1] = (Proportion)n1 / 100;
		_proproportion_arr[2] = (Proportion)n2 / 100;
		_proproportion_arr[3] = (Proportion)n3 / 100;
		_proproportion_arr[4] = (Proportion)n4 / 100;
		_proproportion_arr[5] = (Proportion)n5 / 100;
		_proproportion_arr[6] = (Proportion)n6 / 100;
		_proproportion_arr[7] = (Proportion)n7 / 100;
	};
	Proportion_System(uint8_t n0, uint8_t n1, uint8_t n2, uint8_t n3, uint8_t n4, uint8_t n5, uint8_t n6)
	{
		_proproportion_arr[0] = (Proportion)n0 / 100;
		_proproportion_arr[1] = (Proportion)n1 / 100;
		_proproportion_arr[2] = (Proportion)n2 / 100;
		_proproportion_arr[3] = (Proportion)n3 / 100;
		_proproportion_arr[4] = (Proportion)n4 / 100;
		_proproportion_arr[5] = (Proportion)n5 / 100;
		_proproportion_arr[6] = (Proportion)n6 / 100;
	};
	Proportion_System(uint8_t n0, uint8_t n1, uint8_t n2, uint8_t n3, uint8_t n4, uint8_t n5)
	{
		_proproportion_arr[0] = (Proportion)n0 / 100;
		_proproportion_arr[1] = (Proportion)n1 / 100;
		_proproportion_arr[2] = (Proportion)n2 / 100;
		_proproportion_arr[3] = (Proportion)n3 / 100;
		_proproportion_arr[4] = (Proportion)n4 / 100;
		_proproportion_arr[5] = (Proportion)n5 / 100;
	};
	Proportion_System(uint8_t n0, uint8_t n1, uint8_t n2, uint8_t n3, uint8_t n4)
	{
		_proproportion_arr[0] = (Proportion)n0 / 100;
		_proproportion_arr[1] = (Proportion)n1 / 100;
		_proproportion_arr[2] = (Proportion)n2 / 100;
		_proproportion_arr[3] = (Proportion)n3 / 100;
		_proproportion_arr[4] = (Proportion)n4 / 100;
	};
	Proportion_System(uint8_t n0, uint8_t n1, uint8_t n2, uint8_t n3)
	{
		_proproportion_arr[0] = (Proportion)n0 / 100;
		_proproportion_arr[1] = (Proportion)n1 / 100;
		_proproportion_arr[2] = (Proportion)n2 / 100;
		_proproportion_arr[3] = (Proportion)n3 / 100;
	};
	Proportion_System(uint8_t n0, uint8_t n1, uint8_t n2)
	{
		_proproportion_arr[0] = (Proportion)n0 / 100;
		_proproportion_arr[1] = (Proportion)n1 / 100;
		_proproportion_arr[2] = (Proportion)n2 / 100;
	};
	Proportion_System(uint8_t n0, uint8_t n1)
	{
		_proproportion_arr[0] = (Proportion)n0 / 100;
		_proproportion_arr[1] = (Proportion)n1 / 100;
	}
	Proportion _proproportion_arr[max_subgroup_count_value];
};
class Group_Object
{
public:
	Group_Object();
	Group_Object(Metric_Parameters metric, int subgroup_count) :subgroup_count(subgroup_count), metric_group(metric), _proproportion_arr(NULL), mode(default_mode){};
	Group_Object(Metric_Parameters metric, int subgroup_count, Outline_Color_Style outline_style, Color_Style style) :subgroup_count(subgroup_count), metric_group(metric), outline_style(outline_style), _style(style), _proproportion_arr(NULL), mode(default_style){};
	Group_Object(Metric_Parameters metric, int subgroup_count, Outline_Color_Style outline_style, Color_Style *style) :subgroup_count(subgroup_count), metric_group(metric), outline_style(outline_style), _style_arr(style), _proproportion_arr(NULL), mode(extendet_style){};
	//Group_Object(Metric_Parameters metric, int subgroup_count, Outline_Color_Style outline_style, Color_Style style, Proportion_System prop_system) :subgroup_count(subgroup_count), metric_group(metric), outline_style(outline_style), _style(style), _proproportion_arr(prop_system._proproportion_arr), mode(default_style){};
	//Group_Object(Metric_Parameters metric, int subgroup_count, Outline_Color_Style outline_style, Color_Style *style, Proportion_System prop_system) :subgroup_count(subgroup_count), metric_group(metric), outline_style(outline_style), _style_arr(style), _proproportion_arr(prop_system._proproportion_arr), mode(extendet_style){};

	Group_Object(Metric_Parameters metric, int subgroup_count, Outline_Color_Style outline_style, Color_Style style, Proportion* _proproportion_arr) :subgroup_count(subgroup_count), metric_group(metric), outline_style(outline_style), _style(style), _proproportion_arr(_proproportion_arr), mode(default_style){};
	Group_Object(Metric_Parameters metric, int subgroup_count, Outline_Color_Style outline_style, Color_Style *style, Proportion* _proproportion_arr) :subgroup_count(subgroup_count), metric_group(metric), outline_style(outline_style), _style_arr(style), _proproportion_arr(_proproportion_arr), mode(extendet_style){};
	~Group_Object();


	void setup();
	void update();
	void refresh();
	void strcpy_text(int num, const char * text);
	void strcpy_text(int num, int n_text);
	void enable();
	void disable();
	void state_switch();
	void enable_text(int num);
	void disable_text(int num);
	void state_switch_text(int num);
private:
	const char* return_text(int num);
	int strlen_text(int num);
	void itoa(int n, char s[]);
	void reverse(char s[]);


	enum Mode { unsetup, default_mode, default_style, extendet_style, setup_mode };

	Mode mode = unsetup;
	Metric_Parameters metric_group;
	int subgroup_count = 0;
	Color_Style _style;
	Color_Style *_style_arr;
	Color_Style *style_arr;
	Outline_State outline_state;
	Outline_Color_Style outline_style;
	Proportion* _proproportion_arr;
	Proportion* proproportion_arr;

	IntrfSubGroup_State *sg_state_arr;
	Modification *sg_modification_arr;

	static const int string_length = 200;

	char sg_text_arr_0[string_length];
	char sg_text_arr_1[string_length];
	char sg_text_arr_2[string_length];
	char sg_text_arr_3[string_length];
	char sg_text_arr_4[string_length];
	char sg_text_arr_5[string_length];
	char sg_text_arr_6[string_length];
	char sg_text_arr_7[string_length];
	char sg_text_arr_8[string_length];
	char sg_text_arr_9[string_length];

	IntrfSubGroup_Pointers *sub_group_arr;
	IntrfGroup_to_Subgroup_Init_Parameters subgroup_param_of_group;
	IntrfGroup_Init_Parameters group_init_param;

	IntrfGroup group;

};
#endif