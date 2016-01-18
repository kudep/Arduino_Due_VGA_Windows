#include "intrfsubgroup.h"

void IntrfSubGroup::update()
{
	if (visible)
	{
		//VGA.waitSync();
		VGA.setPrintWindow(content_metric.left, content_metric.top, content_metric.width, content_metric.height);
		VGA.clearPrintWindow();

		// text background colour
		if (subgroup_state->background)
			VGA.setPaper(style.enable.background);
		else
			VGA.setPaper(style.disable.background);

		// text colour
		if (subgroup_state->text)
			VGA.setInk(style.enable.text);
		else
			VGA.setInk(style.disable.text);

		//print text
		VGA.print(text);
		VGA.unsetPrintWindow();
		// outline
		//Serial.print("outline_metric.left ");
		////Serial.println(outline_metric.left);
		if (subgroup_state->outline)
			VGA.drawRect(outline_metric.left, outline_metric.top, outline_metric.width, outline_metric.height, style.enable.outline);
		else
			VGA.drawRect(outline_metric.left, outline_metric.top, outline_metric.width, outline_metric.height, style.disable.outline);
		//VGA.print(content_metric.width);

	}
}


void IntrfSubGroup::refresh()
{
	if (visible)
	{
		VGA.setPrintWindow(content_metric.left, content_metric.top, content_metric.width, content_metric.height);
		VGA.clearPrintWindow();

		// text background colour
		if (subgroup_state->background)
			VGA.setPaper(style.enable.background);
		else
			VGA.setPaper(style.disable.background);

		// text colour
		if (subgroup_state->text)
			VGA.setInk(style.enable.text);
		else
			VGA.setInk(style.disable.text);

		//print text
		VGA.print(text);
		VGA.unsetPrintWindow();
		// outline

		//Serial.print("refresh outline_metric.left ");
		//Serial.println(outline_metric.left);
		if (subgroup_state->outline)
			VGA.drawRect(outline_metric.left, outline_metric.top, outline_metric.width, outline_metric.height, style.enable.outline);
		else
			VGA.drawRect(outline_metric.left, outline_metric.top, outline_metric.width, outline_metric.height, style.disable.outline);
		//VGA.print(content_metric.width);
	}
}

IntrfSubGroup::IntrfSubGroup()
{
	visible = false;
}

IntrfSubGroup::~IntrfSubGroup()
{
}