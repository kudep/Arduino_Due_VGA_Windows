#include"VGA_windows.h"

Win_help::Win_help() : 
background(Color_Style(sg_f), Metric_Parameters(Left_shift1, Top_shift1, width_shift1, Height_shift1)," "),
title(Color_Style(sg_f), Metric_Parameters(17, Top_shift2, 6, 1), "HELP"),
text(Color_Style(sg_f), Metric_Parameters(Left_shift2, Top_shift3, width_shift2, Height_shift2))
{
	flag[0] = (char)187;
	flag[1] = (char)0;
	windows();
}

Win_help::~Win_help()
{
}


Win1::Win1() : data_time1(Color_Style(sg_f), Metric_Parameters(2, 1, 6, 1), "Data"),
data_time2(Color_Style(sg_f), Metric_Parameters(8, 1, 12, 1)),
data_time3(Color_Style(sg_f), Metric_Parameters(21, 1, 7, 1), "Time"),
data_time4(Color_Style(sg_f), Metric_Parameters(28, 1, 7, 1)),

full_name(Color_Style(sg_f), Metric_Parameters(12, 5, 16, 1), "Full Name"),
surname(Color_Style(sg_f), Metric_Parameters(1, 7, 13, 1), "Surname"),
surname1(Color_Style(sg_f), Metric_Parameters(15, 7, 24, 1)),
name(Color_Style(sg_f), Metric_Parameters(1, 9, 13, 1), "Name"),
name1(Color_Style(sg_f), Metric_Parameters(15, 9, 24, 1)),
middle_name(Color_Style(sg_f), Metric_Parameters(1, 11, 13, 1), "Middle Name"),
middle_name1(Color_Style(sg_f), Metric_Parameters(15, 11, 24, 1)),

eye_ametropia(Color_Style(sg_f), Metric_Parameters(12, 18, 16, 1), "Eye-Ametropia:"),
OD(Color_Style(sg_f), Metric_Parameters(8, 20, 4, 1), "OD"),
OD1(Color_Style(sg_f), Metric_Parameters(13, 20, 3, 1)),
OD2(Color_Style(sg_f), Metric_Parameters(17, 20, 6, 1)),
OD3(Color_Style(sg_f), Metric_Parameters(24, 20, 8, 1)),

OS(Color_Style(sg_f), Metric_Parameters(8, 22, 4, 1), "OS"),
OS1(Color_Style(sg_f), Metric_Parameters(13, 22, 3, 1)),
OS2(Color_Style(sg_f), Metric_Parameters(17, 22, 6, 1)),
OS3(Color_Style(sg_f), Metric_Parameters(24, 22, 8, 1)),

extern_button0(Color_Style(sg_f), Metric_Parameters(1, 28, 8, 1), "F1"),
extern_button1(Color_Style(sg_f), Metric_Parameters(8, 28, 8, 1), "F2"),
extern_button2(Color_Style(sg_f), Metric_Parameters(16, 28, 8, 1), "F3"),
extern_button3(Color_Style(sg_f), Metric_Parameters(24, 28, 8, 1), "F4"),
extern_button4(Color_Style(sg_f), Metric_Parameters(32, 28, 7, 1), "F5"),

extern_button_description0(Color_Style(sg_f), Metric_Parameters(1, 29, 7, 1), "help"),
extern_button_description1(Color_Style(sg_f), Metric_Parameters(8, 29, 8, 1), "menu"),
extern_button_description2(Color_Style(sg_f), Metric_Parameters(16, 29, 8, 1), "exit"),
extern_button_description3(Color_Style(sg_f), Metric_Parameters(24, 29, 8, 1), "prev"),
extern_button_description4(Color_Style(sg_f), Metric_Parameters(32, 29, 7, 1), "next")
{
	flag[0] = (char)187;
	flag[1] = (char)0;
	windows();
}

Win1::~Win1()
{
}




Win2::Win2() :

measurement_mode(Color_Style(sg_f), Metric_Parameters(Left_shift0, Top_shift1, width_shift1, 1), "Measurement-Mode"),
measurement_mode1x1(Color_Style(sg_f), Metric_Parameters(Left_shift1, Top_shift1 + 2, width_shift2, 1), "Hand"),
measurement_mode_field1x1(Color_Style(sg_f), Metric_Parameters(Left_shift2, Top_shift1 + 2, width_shift3, 1)),
measurement_mode2x1(Color_Style(sg_f), Metric_Parameters(Left_shift3, Top_shift1 + 2, width_shift2, 1), "Mode cycles"),
measurement_mode_field2x1(Color_Style(sg_f), Metric_Parameters(Left_shift4, Top_shift1 + 2, width_shift3, 1)),
measurement_mode1x2(Color_Style(sg_f), Metric_Parameters(Left_shift1, Top_shift1 + 4, width_shift2, 1), "Cycles"),
measurement_mode_field1x2(Color_Style(sg_f), Metric_Parameters(Left_shift2, Top_shift1 + 4, width_shift3, 1)),
measurement_mode2x2(Color_Style(sg_f), Metric_Parameters(Left_shift3, Top_shift1 + 4, width_shift2, 1), "Fixation"),
measurement_mode_field2x2(Color_Style(sg_f), Metric_Parameters(Left_shift4, Top_shift1 + 4, width_shift3, 1)),

training_mode(Color_Style(sg_f), Metric_Parameters(Left_shift0, Top_shift2, width_shift1, 1), "Training-Mode"),
training_mode1x1(Color_Style(sg_f), Metric_Parameters(Left_shift1, Top_shift2+2, width_shift2, 1), "Session, min"),
training_mode_field1x1(Color_Style(sg_f), Metric_Parameters(Left_shift2, Top_shift2 + 2, width_shift4, 1)),
training_mode1x2(Color_Style(sg_f), Metric_Parameters(Left_shift1, Top_shift2 + 4, width_shift2, 1), "Hand"),
training_mode_field1x2(Color_Style(sg_f), Metric_Parameters(Left_shift2, Top_shift2 + 4, width_shift3, 1)),
training_mode2x2(Color_Style(sg_f), Metric_Parameters(Left_shift3, Top_shift2 + 4, width_shift2, 1), "Mode cycles"),
training_mode_field2x2(Color_Style(sg_f), Metric_Parameters(Left_shift4, Top_shift2 + 4, width_shift3, 1)),
training_mode1x3(Color_Style(sg_f), Metric_Parameters(Left_shift1, Top_shift2 + 6, width_shift2, 1), "Cycles"),
training_mode_field1x3(Color_Style(sg_f), Metric_Parameters(Left_shift2, Top_shift2 + 6, width_shift3, 1)),
training_mode2x3(Color_Style(sg_f), Metric_Parameters(Left_shift3, Top_shift2 + 6, width_shift2, 1), "Fixation"),
training_mode_field2x3(Color_Style(sg_f), Metric_Parameters(Left_shift4, Top_shift2 + 6, width_shift3, 1)),

start_finish1x1(Color_Style(sg_f), Metric_Parameters(Left_shift1, Top_shift3, width_shift2, 1), "Start"),
start_finish_field1x1(Color_Style(sg_f), Metric_Parameters(Left_shift2, Top_shift3, width_shift4, 1)),
start_finish2x1(Color_Style(sg_f), Metric_Parameters(Left_shift1, Top_shift3 + 2, width_shift2, 1), "Finish"),
start_finish_field2x1(Color_Style(sg_f), Metric_Parameters(Left_shift2, Top_shift3 + 2, width_shift4, 1)),

extern_button0(Color_Style(sg_f), Metric_Parameters(1, 28, 8, 1), "F1"),
extern_button1(Color_Style(sg_f), Metric_Parameters(8, 28, 8, 1), "F2"),
extern_button2(Color_Style(sg_f), Metric_Parameters(16, 28, 8, 1), "F3"),
extern_button3(Color_Style(sg_f), Metric_Parameters(24, 28, 8, 1), "F4"),
extern_button4(Color_Style(sg_f), Metric_Parameters(32, 28, 7, 1), "F5"),

extern_button_description0(Color_Style(sg_f), Metric_Parameters(1, 29, 7, 1), "help"),
extern_button_description1(Color_Style(sg_f), Metric_Parameters(8, 29, 8, 1), "menu"),
extern_button_description2(Color_Style(sg_f), Metric_Parameters(16, 29, 8, 1), "exit"),
extern_button_description3(Color_Style(sg_f), Metric_Parameters(24, 29, 8, 1), "prev"),
extern_button_description4(Color_Style(sg_f), Metric_Parameters(32, 29, 7, 1), "next")
{
	flag[0] = (char)187;
	flag[1] = (char)0;
	windows();
}

Win2::~Win2()
{
}
