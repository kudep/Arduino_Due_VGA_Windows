
#ifndef INTRFGROUP_H_INCLUDED
#define INTRFGROUP_H_INCLUDED
#include "intrfsubgroup.h"

typedef bool Outline_State;
typedef bool Modification;
typedef float Proportion;
typedef char* text_t;
struct IntrfGroup_Sector
{
	IntrfSubGroup ISG;
	Modification *modification;
};
struct IntrfSubGroup_Pointers
{
	IntrfSubGroup_Pointers() {}
	IntrfSubGroup_Pointers(IntrfSubGroup_State *subgroup_state, const char* text, Modification *modification) :subgroup_state(subgroup_state), text(text), modification(modification){}
	IntrfSubGroup_State *subgroup_state;
	const char* text;
	Modification *modification;
};

struct IntrfGroup_to_Subgroup_Init_Parameters
{
	IntrfGroup_to_Subgroup_Init_Parameters(){};
	IntrfGroup_to_Subgroup_Init_Parameters(int subgroup_count, Proportion *proproportion_array, Color_Style *style_array, IntrfSubGroup_Pointers *sub_group_p_array) :subgroup_count(subgroup_count), proproportion_array(proproportion_array), style_array(style_array), sub_group_p_array(sub_group_p_array){};
	IntrfGroup_to_Subgroup_Init_Parameters(int subgroup_count, Proportion *proproportion_array, IntrfSubGroup_Pointers *sub_group_p_array) :subgroup_count(subgroup_count), proproportion_array(proproportion_array), sub_group_p_array(sub_group_p_array){};
	int subgroup_count;
	Proportion *proproportion_array;
	Color_Style *style_array;
	IntrfSubGroup_Pointers *sub_group_p_array;
};

struct IntrfGroup_Init_Parameters
{
	IntrfGroup_Init_Parameters(){};
	IntrfGroup_Init_Parameters(Metric_Parameters metric, Outline_State *outline_state, Outline_Color_Style outline_style, IntrfGroup_to_Subgroup_Init_Parameters subgroup_parameters) :metric(metric), outline_state(outline_state), outline_style(outline_style), subgroup_parameters(subgroup_parameters){};
	Metric_Parameters metric;
	Outline_State *outline_state;
	Outline_Color_Style outline_style;
	IntrfGroup_to_Subgroup_Init_Parameters subgroup_parameters;
};


class  IntrfGroup
{
public:
	IntrfGroup(IntrfGroup_Init_Parameters parameters) :outline_state(parameters.outline_state), outline_style(parameters.outline_style), subgroup_count(parameters.subgroup_parameters.subgroup_count)
	{
		visible = true;
		outline_metric.left = parameters.metric.left * 8 - 2;
		outline_metric.top = parameters.metric.top * 8 - 2;
		outline_metric.height = (parameters.metric.top + parameters.metric.height) * 8+1;
		outline_metric.width = (parameters.metric.left + parameters.metric.width) * 8+1;
		sector_array = new IntrfGroup_Sector[subgroup_count];
		content_metric_width = new int[subgroup_count];
		float metric_left_shift;
		float metric_width_shift;
		int width = parameters.metric.width - subgroup_count+1;
		Metric_Parameters subgroup_metric;
		for (int i = 0; i <subgroup_count; i++)
		{
			metric_left_shift = 0;
			for (int j = 0; j < i; j++)
			{
				metric_left_shift += parameters.subgroup_parameters.proproportion_array[j];
			}
			metric_width_shift = parameters.subgroup_parameters.proproportion_array[i];
			subgroup_metric=Metric_Parameters(parameters.metric.left + (uint16_t)(width*metric_left_shift + 0.5) + i, parameters.metric.top, (uint16_t)(width*metric_width_shift + 0.5), parameters.metric.height);
			content_metric_width[i] = subgroup_metric.width;
			sector_array[i].ISG = IntrfSubGroup(IntrfSubGroup_Init_Parameters(parameters.subgroup_parameters.style_array[i], subgroup_metric, parameters.subgroup_parameters.sub_group_p_array[i].subgroup_state, parameters.subgroup_parameters.sub_group_p_array[i].text));
			sector_array[i].modification = parameters.subgroup_parameters.sub_group_p_array[i].modification;

		}
	}
	IntrfGroup();
	~IntrfGroup();
	void update();
	void refresh();
	int get_width(int num);

public:
	Metric_Parameters outline_metric;
	Outline_State *outline_state;
	Outline_Color_Style  outline_style;
	int subgroup_count;
	IntrfGroup_Sector *sector_array;
	int *content_metric_width;
	bool visible;
};



#endif