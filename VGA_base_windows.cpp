#include"VGA_base_windows.h"

Win::Win()
{
}

Win::~Win()
{
}




Win2::Win2() :

measurement_mode(Color_Style(text), Metric_Parameters(Left_shift0, Top_shift1, width_shift1, 1), "Measurement-Mode"),
measurement_mode1x1(Color_Style(text), Metric_Parameters(Left_shift1, Top_shift1 + 2, width_shift2, 1), "Hand"),
measurement_mode_field1x1(Color_Style(text), Metric_Parameters(Left_shift2, Top_shift1 + 2, width_shift3, 1)),
measurement_mode2x1(Color_Style(text), Metric_Parameters(Left_shift3, Top_shift1 + 2, width_shift2, 1), "Mode cycles"),
measurement_mode_field2x1(Color_Style(text), Metric_Parameters(Left_shift4, Top_shift1 + 2, width_shift3, 1)),
measurement_mode1x2(Color_Style(text), Metric_Parameters(Left_shift1, Top_shift1 + 4, width_shift2, 1), "Cycles"),
measurement_mode_field1x2(Color_Style(text), Metric_Parameters(Left_shift2, Top_shift1 + 4, width_shift3, 1)),
measurement_mode2x2(Color_Style(text), Metric_Parameters(Left_shift3, Top_shift1 + 4, width_shift2, 1), "Fixation"),
measurement_mode_field2x2(Color_Style(text), Metric_Parameters(Left_shift4, Top_shift1 + 4, width_shift3, 1)),

training_mode(Color_Style(text), Metric_Parameters(Left_shift0, Top_shift2, width_shift1, 1), "Training-Mode"),
training_mode1x1(Color_Style(text), Metric_Parameters(Left_shift1, Top_shift2+2, width_shift2, 1), "Session, min"),
training_mode_field1x1(Color_Style(text), Metric_Parameters(Left_shift2, Top_shift2 + 2, width_shift4, 1)),
training_mode1x2(Color_Style(text), Metric_Parameters(Left_shift1, Top_shift2 + 4, width_shift2, 1), "Hand"),
training_mode_field1x2(Color_Style(text), Metric_Parameters(Left_shift2, Top_shift2 + 4, width_shift3, 1)),
training_mode2x2(Color_Style(text), Metric_Parameters(Left_shift3, Top_shift2 + 4, width_shift2, 1), "Mode cycles"),
training_mode_field2x2(Color_Style(text), Metric_Parameters(Left_shift4, Top_shift2 + 4, width_shift3, 1)),
training_mode1x3(Color_Style(text), Metric_Parameters(Left_shift1, Top_shift2 + 6, width_shift2, 1), "Cycles"),
training_mode_field1x3(Color_Style(text), Metric_Parameters(Left_shift2, Top_shift2 + 6, width_shift3, 1)),
training_mode2x3(Color_Style(text), Metric_Parameters(Left_shift3, Top_shift2 + 6, width_shift2, 1), "Fixation"),
training_mode_field2x3(Color_Style(text), Metric_Parameters(Left_shift4, Top_shift2 + 6, width_shift3, 1)),

start_finish1x1(Color_Style(text), Metric_Parameters(Left_shift1, Top_shift3, width_shift2, 1), "Start"),
start_finish_field1x1(Color_Style(text), Metric_Parameters(Left_shift2, Top_shift3, width_shift4, 1)),
start_finish2x1(Color_Style(text), Metric_Parameters(Left_shift1, Top_shift3 + 2, width_shift2, 1), "Finish"),
start_finish_field2x1(Color_Style(text), Metric_Parameters(Left_shift2, Top_shift3 + 2, width_shift4, 1)),

extend_button0(Color_Style(text), Metric_Parameters(1, 28, 8, 1), "F1"),
extend_button1(Color_Style(text), Metric_Parameters(8, 28, 8, 1), "F2"),
extend_button2(Color_Style(text), Metric_Parameters(16, 28, 8, 1), "F3"),
extend_button3(Color_Style(text), Metric_Parameters(24, 28, 8, 1), "F4"),
extend_button4(Color_Style(text), Metric_Parameters(32, 28, 7, 1), "F5"),

extend_button_description0(Color_Style(text), Metric_Parameters(1, 29, 7, 1), "help"),
extend_button_description1(Color_Style(text), Metric_Parameters(8, 29, 8, 1), "menu"),
extend_button_description2(Color_Style(text), Metric_Parameters(16, 29, 8, 1), "exit"),
extend_button_description3(Color_Style(text), Metric_Parameters(24, 29, 8, 1), "prev"),
extend_button_description4(Color_Style(text), Metric_Parameters(32, 29, 7, 1), "next")
{
	flag[0] = (char)187;
	flag[1] = (char)0;
	windows();
}

Win2::~Win2()
{
}
