#include"win_options.h"

Win_Option::Win_Option() :

//Meas. title
meas_title(Color_Style(information), Metric_Parameters(1, 3, 38, 1)),
//1 string
choose_m_os0(Color_Style(information), Metric_Parameters(1, 5, OFFSET_FOR_INFORMATION_ON_DISPLEY, 1)),
choose_m_os1(Color_Style(interactive), Metric_Parameters(OFFSET_FOR_INFORMATION_ON_DISPLEY+2, 5, DATA_STRING_LENGTH, 1)),

//2 string
choose_m_od0(Color_Style(information), Metric_Parameters(1, 7, OFFSET_FOR_INFORMATION_ON_DISPLEY, 1)),
choose_m_od1(Color_Style(interactive), Metric_Parameters(OFFSET_FOR_INFORMATION_ON_DISPLEY+2, 7, DATA_STRING_LENGTH, 1)),

//Train. title
train_title(Color_Style(information), Metric_Parameters(1, 9, 38, 1)),

//3 string
time_t_os0(Color_Style(information), Metric_Parameters(1, 11, OFFSET_FOR_INFORMATION_ON_DISPLEY, 1)),
time_t_os1(Color_Style(interactive), Metric_Parameters(OFFSET_FOR_INFORMATION_ON_DISPLEY+2, 11, DATA_STRING_LENGTH, 1)),

//4 string
os_n0(Color_Style(information), Metric_Parameters(1, 13, OFFSET_FOR_INFORMATION_ON_DISPLEY, 1)),
os_n1(Color_Style(interactive), Metric_Parameters(OFFSET_FOR_INFORMATION_ON_DISPLEY+2, 13, DATA_STRING_LENGTH, 1)),


//5 string
os_f0(Color_Style(information), Metric_Parameters(1, 15, OFFSET_FOR_INFORMATION_ON_DISPLEY, 1)),
os_f1(Color_Style(interactive), Metric_Parameters(OFFSET_FOR_INFORMATION_ON_DISPLEY+2, 15, DATA_STRING_LENGTH, 1)),

//6 string
time_t_od0(Color_Style(information), Metric_Parameters(1, 17, OFFSET_FOR_INFORMATION_ON_DISPLEY, 1)),
time_t_od1(Color_Style(interactive), Metric_Parameters(OFFSET_FOR_INFORMATION_ON_DISPLEY+2, 17, DATA_STRING_LENGTH, 1)),

//7 string
od_n0(Color_Style(information), Metric_Parameters(1, 19, OFFSET_FOR_INFORMATION_ON_DISPLEY, 1)),
od_n1(Color_Style(interactive), Metric_Parameters(OFFSET_FOR_INFORMATION_ON_DISPLEY+2, 19, DATA_STRING_LENGTH, 1)),

//8 string
od_f0(Color_Style(information), Metric_Parameters(1, 21, OFFSET_FOR_INFORMATION_ON_DISPLEY, 1)),
od_f1(Color_Style(interactive), Metric_Parameters(OFFSET_FOR_INFORMATION_ON_DISPLEY+2, 21, DATA_STRING_LENGTH, 1)),


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

Win_Option::~Win_Option()
{
}