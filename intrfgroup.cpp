#include "intrfgroup.h"

IntrfGroup::IntrfGroup()
{
	visible = false;
}

IntrfGroup::~IntrfGroup()
{

	if (visible)
	{
		delete[] sector_array;
	}
}

void IntrfGroup::update()
{
	if (visible)
	{

		// outline
		if (*outline_state == true)
			VGA.drawRect(outline_metric.left, outline_metric.top, outline_metric.width, outline_metric.height, outline_style.enable);
		else
			VGA.drawRect(outline_metric.left, outline_metric.top, outline_metric.width, outline_metric.height, outline_style.disable);

		for (int i = 0; i < subgroup_count; i++)
		{
			if (*(sector_array[i].modification) == true)
			{
				sector_array[i].ISG.update();
				VGA.unsetPrintWindow();
				//VGA.clearPrintWindow();
			}
			*(sector_array[i].modification) = false;
		}

	}
}

void IntrfGroup::refresh()
{
	if (visible)
	{

		// outline
		if (*outline_state == true)
			VGA.drawRect(outline_metric.left, outline_metric.top, outline_metric.width, outline_metric.height, outline_style.enable);
		else
			VGA.drawRect(outline_metric.left, outline_metric.top, outline_metric.width, outline_metric.height, outline_style.disable);

		for (int i = 0; i < subgroup_count; i++)
		{
			sector_array[i].ISG.refresh();
			VGA.unsetPrintWindow();
			//VGA.clearPrintWindow();
			*(sector_array[i].modification) = false;
		}

	}
}
int IntrfGroup::get_width(int num)
{
	if (visible)
	{

		return content_metric_width[num];
	}
	return 0;
}