#include"win_train.h"

Win_Train::Win_Train() :

//1 string
start_position0(Color_Style(information), Metric_Parameters(1, 3, OFFSET_FOR_INFORMATION_ON_DISPLEY, 1)),
start_position1(Color_Style(interactive), Metric_Parameters(OFFSET_FOR_INFORMATION_ON_DISPLEY + 2, 3, DATA_STRING_LENGTH, 1)),

//2 string
chang_test_obj0(Color_Style(information), Metric_Parameters(1, 5, OFFSET_FOR_INFORMATION_ON_DISPLEY, 1)),
chang_test_obj1(Color_Style(interactive), Metric_Parameters(OFFSET_FOR_INFORMATION_ON_DISPLEY + 2, 5, DATA_STRING_LENGTH, 1)),

//3 string
chang_viz0(Color_Style(information), Metric_Parameters(1, 7, OFFSET_FOR_INFORMATION_ON_DISPLEY, 1)),
chang_viz1(Color_Style(interactive), Metric_Parameters(OFFSET_FOR_INFORMATION_ON_DISPLEY + 2, 7, DATA_STRING_LENGTH, 1)),

//4 string
patient_controller0(Color_Style(information), Metric_Parameters(1, 9, OFFSET_FOR_INFORMATION_ON_DISPLEY, 1)),
patient_controller1(Color_Style(interactive), Metric_Parameters(OFFSET_FOR_INFORMATION_ON_DISPLEY + 2, 9, DATA_STRING_LENGTH, 1)),

//5 string
auto_mode0(Color_Style(information), Metric_Parameters(1, 11, OFFSET_FOR_INFORMATION_ON_DISPLEY, 1)),
auto_mode1(Color_Style(interactive), Metric_Parameters(OFFSET_FOR_INFORMATION_ON_DISPLEY + 2, 11, DATA_STRING_LENGTH, 1)),

//6 string
eye_mode0(Color_Style(information), Metric_Parameters(1, 13, OFFSET_FOR_INFORMATION_ON_DISPLEY, 1)),
eye_mode1(Color_Style(interactive), Metric_Parameters(OFFSET_FOR_INFORMATION_ON_DISPLEY + 2, 13, DATA_STRING_LENGTH, 1)),


//7 string
focus_n0(Color_Style(information), Metric_Parameters(1, 15, OFFSET_FOR_INFORMATION_ON_DISPLEY, 1)),
focus_n1(Color_Style(interactive), Metric_Parameters(OFFSET_FOR_INFORMATION_ON_DISPLEY + 2, 15, DATA_STRING_LENGTH, 1)),


//8 string
focus_f0(Color_Style(information), Metric_Parameters(1, 17, OFFSET_FOR_INFORMATION_ON_DISPLEY, 1)),
focus_f1(Color_Style(interactive), Metric_Parameters(OFFSET_FOR_INFORMATION_ON_DISPLEY + 2, 17, DATA_STRING_LENGTH, 1)),

//9 string
position0(Color_Style(information), Metric_Parameters(1, 19, OFFSET_FOR_INFORMATION_ON_DISPLEY, 1)),
position1(Color_Style(interactive), Metric_Parameters(OFFSET_FOR_INFORMATION_ON_DISPLEY + 2, 19, DATA_STRING_LENGTH, 1)),

//Timer
timer0(Color_Style(information), Metric_Parameters(1, 21, OFFSET_FOR_INFORMATION_ON_DISPLEY, 1)),
timer1(Color_Style(information), Metric_Parameters(OFFSET_FOR_INFORMATION_ON_DISPLEY + 2, 21, DATA_STRING_LENGTH, 1)),

//Extend button
extend_button0(Color_Style(interactive), Metric_Parameters(8, 28, 8, 1), "F1"),
extend_button1(Color_Style(interactive), Metric_Parameters(16, 28, 8, 1), "F2"),
extend_button2(Color_Style(interactive), Metric_Parameters(24, 28, 8, 1), "F3"),

extend_button_description0(Color_Style(interactive), Metric_Parameters(8, 29, 8, 1)),
extend_button_description1(Color_Style(interactive), Metric_Parameters(16, 29, 8, 1)),
extend_button_description2(Color_Style(interactive), Metric_Parameters(24, 29, 8, 1))
{
	flag[0] = (char)187;
	flag[1] = (char)0;
	/*data_time_name[0] = (char)196;
	data_time_name[1] = (char)224;
	data_time_name[2] = (char)242;
	data_time_name[3] = (char)224;
	data_time_name[4] = (char)0;*/
	windows();
}

Win_Train::~Win_Train()
{
}