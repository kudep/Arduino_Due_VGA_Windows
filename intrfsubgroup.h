
#ifndef INTRFSUBGROUP_H_INCLUDED
#define INTRFSUBGROUP_H_INCLUDED
#include <VGA.h>
#include "colorsourse.h"

//Parametrs of position and scale
struct Metric_Parameters
{
	Metric_Parameters() :left(0), top(0), width(0), height(0){};
	Metric_Parameters(uint16_t metric) :left(metric), top(metric), width(metric), height(metric){};
	Metric_Parameters(uint16_t left, uint16_t top, uint16_t width, uint16_t height) :left(left), top(top), width(width), height(height){};
	uint16_t left;
	uint16_t top;
	uint16_t width;
	uint16_t height;
};

//Color parametrs of position and scale
struct IntrfSubGroup_State
{
	IntrfSubGroup_State() :outline(false), background(false), text(false){};
	IntrfSubGroup_State(bool state) :outline(state), background(state), text(state){};
	IntrfSubGroup_State(bool outline, bool background, bool text) :outline(outline), background(background), text(text){};
	void enable()
	{
		outline = true;
		background = true;
		text = true;
	}
	void disable()
	{
		outline = false;
		background = false;
		text = false;
	}
	void reverse()
	{
		outline = !outline;
		background = !background;
		text = !text;
	}
	bool outline;
	bool background;
	bool text;
};
struct IntrfSubGroup_Init_Parameters
{
	IntrfSubGroup_Init_Parameters(Metric_Parameters content_metric, IntrfSubGroup_State *subgroup_state, const char* text) :style(), content_metric(content_metric), subgroup_state(subgroup_state), text(text){};
	IntrfSubGroup_Init_Parameters(Color_Style style, Metric_Parameters content_metric, IntrfSubGroup_State *subgroup_state, const char* text) :style(style), content_metric(content_metric), subgroup_state(subgroup_state), text(text){};
	Color_Style style;
	Metric_Parameters content_metric;
	IntrfSubGroup_State *subgroup_state;
	const char* text;
};

class IntrfSubGroup
{
public:
	IntrfSubGroup(IntrfSubGroup_Init_Parameters parameters) : style(parameters.style), content_metric(parameters.content_metric), subgroup_state(parameters.subgroup_state), text(parameters.text)
	{
		visible = true;
		outline_metric.left = content_metric.left * 8 - 1;
		outline_metric.top = content_metric.top * 8 - 1;
		outline_metric.height = (content_metric.top + content_metric.height) * 8;
		outline_metric.width = (content_metric.left + content_metric.width) * 8;
	};
	IntrfSubGroup();
	~IntrfSubGroup();
	void update();
	void refresh();
private:
	Color_Style style;
	Metric_Parameters content_metric;
	Metric_Parameters outline_metric;
	IntrfSubGroup_State *subgroup_state;
	const char*text;
	bool visible;
};

#endif