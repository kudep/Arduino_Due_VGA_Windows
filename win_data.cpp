#include"win_data.h"

#define OFFSET_FOR_DEBUG_DISPLEY 10
Win_Data::Win_Data() :

//1 string
data0(Color_Style(information), Metric_Parameters(1, 5, OFFSET_FOR_INFORMATION_ON_DISPLEY, 1)),
data1(Color_Style(interactive), Metric_Parameters(OFFSET_FOR_INFORMATION_ON_DISPLEY+2, 5, DATA_STRING_LENGTH, 1)),
//1 string
time0(Color_Style(information), Metric_Parameters(1, 7, OFFSET_FOR_INFORMATION_ON_DISPLEY, 1)),
time1(Color_Style(interactive), Metric_Parameters(OFFSET_FOR_INFORMATION_ON_DISPLEY+2, 7, DATA_STRING_LENGTH, 1)),

//2 string
surname0(Color_Style(information), Metric_Parameters(1, 9, OFFSET_FOR_INFORMATION_ON_DISPLEY, 1)),
surname1(Color_Style(interactive), Metric_Parameters(OFFSET_FOR_INFORMATION_ON_DISPLEY+2, 9, DATA_STRING_LENGTH, 1)),

//3 string
name0(Color_Style(information), Metric_Parameters(1, 11, OFFSET_FOR_INFORMATION_ON_DISPLEY, 1)),
name1(Color_Style(interactive), Metric_Parameters(OFFSET_FOR_INFORMATION_ON_DISPLEY+2, 11, DATA_STRING_LENGTH, 1)),

//4 string
middle_name0(Color_Style(information), Metric_Parameters(1, 13, OFFSET_FOR_INFORMATION_ON_DISPLEY, 1)),
middle_name1(Color_Style(interactive), Metric_Parameters(OFFSET_FOR_INFORMATION_ON_DISPLEY+2, 13, DATA_STRING_LENGTH, 1)),


//5 string
book_numb0(Color_Style(information), Metric_Parameters(1, 15, OFFSET_FOR_INFORMATION_ON_DISPLEY, 1)),
book_numb1(Color_Style(interactive), Metric_Parameters(OFFSET_FOR_INFORMATION_ON_DISPLEY + 2, 15, DATA_STRING_LENGTH, 1)),

debug0(Color_Style(interactive), Metric_Parameters(1, 17, OFFSET_FOR_DEBUG_DISPLEY, 1)),
debug1(Color_Style(interactive), Metric_Parameters(OFFSET_FOR_DEBUG_DISPLEY + 2, 17, OFFSET_FOR_DEBUG_DISPLEY, 1)),
debug2(Color_Style(interactive), Metric_Parameters(OFFSET_FOR_DEBUG_DISPLEY + 2 + OFFSET_FOR_DEBUG_DISPLEY + 2, 17, OFFSET_FOR_DEBUG_DISPLEY, 1)),

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

Win_Data::~Win_Data()
{
}
//
//Win_Data_Handler::Win_Data_Handler()
//{
////	//Serial.begin(9600);
//}
//
//Win_Data_Handler::~Win_Data_Handler()
//{
//
//}