#include"win_help.h"
Win_Help::Win_Help() :
background(Color_Style(interactive), Metric_Parameters(Left_shift1, Top_shift1, width_shift1, Height_shift1), " "),
title(Color_Style(interactive), Metric_Parameters(16, Top_shift2, 8, 1)),
content(Color_Style(interactive), Metric_Parameters(Left_shift2, Top_shift3, width_shift2, Height_shift2)),

//Extend button
extend_button0(Color_Style(interactive), Metric_Parameters(16, 28, 8, 1), "F1"),
extend_button_description0(Color_Style(interactive), Metric_Parameters(16, 29, 8, 1))
{
	flag[0] = (char)187;
	flag[1] = (char)0;
	windows();
}

Win_Help::~Win_Help()
{
}
