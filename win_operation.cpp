#include"win_operation.h"

Win_Oper::Win_Oper() :

//1 string
start_position0(Color_Style(information), Metric_Parameters(1, 5, 13, 1)),
start_position1(Color_Style(interactive), Metric_Parameters(15, 5, DATA_STRING_LENGTH, 1)),

//2 string
test_obj_mode0(Color_Style(information), Metric_Parameters(1, 7, 13, 1)),
test_obj_mode1(Color_Style(interactive), Metric_Parameters(15, 7, DATA_STRING_LENGTH, 1)),

//3 string
patient_controller0(Color_Style(information), Metric_Parameters(1, 9, 13, 1)),
patient_controller1(Color_Style(interactive), Metric_Parameters(15, 9, DATA_STRING_LENGTH, 1)),

//4 string
eye_mode0(Color_Style(information), Metric_Parameters(1, 11, 13, 1)),
eye_mode1(Color_Style(interactive), Metric_Parameters(15, 11, DATA_STRING_LENGTH, 1)),


//5 string
focus_point0(Color_Style(information), Metric_Parameters(1, 13, 13, 1)),
focus_point1(Color_Style(interactive), Metric_Parameters(15, 13, DATA_STRING_LENGTH, 1)),

//6 string
record_position0(Color_Style(information), Metric_Parameters(1, 15, 13, 1)),
record_position1(Color_Style(interactive), Metric_Parameters(15, 15, DATA_STRING_LENGTH, 1)),

//7 string
remove_record0(Color_Style(information), Metric_Parameters(1, 17, 13, 1)),
remove_record1(Color_Style(interactive), Metric_Parameters(15, 17, DATA_STRING_LENGTH, 1)),

//8 string
chang_test_obj0(Color_Style(information), Metric_Parameters(1, 19, 13, 1)),
chang_test_obj1(Color_Style(interactive), Metric_Parameters(15, 19, DATA_STRING_LENGTH, 1)),

//9 string
timer0(Color_Style(information), Metric_Parameters(1, 21, 13, 1)),
timer1(Color_Style(interactive), Metric_Parameters(15, 21, DATA_STRING_LENGTH, 1)),

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

Win_Oper::~Win_Oper()
{
}