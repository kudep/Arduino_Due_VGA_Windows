#include"win_result.h"


Win_Result::Win_Result() :

//1 string
os0(Color_Style(information), Metric_Parameters(2, 5, 8, 1)),
os1(Color_Style(information), Metric_Parameters(11, 5, 8, 1)),
os2(Color_Style(information), Metric_Parameters(20, 5, 8, 1)),
os3(Color_Style(information), Metric_Parameters(29, 5, 8, 1)),

//2 string
os_n0(Color_Style(information), Metric_Parameters(2, 7, 8, 1)),
os_n1(Color_Style(interactive), Metric_Parameters(11, 7, 8, 1),""),
os_n2(Color_Style(interactive), Metric_Parameters(20, 7, 8, 1),""),
os_n3(Color_Style(interactive), Metric_Parameters(29, 7, 8, 1),""),

//3 string
os_f0(Color_Style(information), Metric_Parameters(2, 9, 8, 1)),
os_f1(Color_Style(interactive), Metric_Parameters(11, 9, 8, 1),""),
os_f2(Color_Style(interactive), Metric_Parameters(20, 9, 8, 1),""),
os_f3(Color_Style(interactive), Metric_Parameters(29, 9, 8, 1),""),

//4 string
od0(Color_Style(information), Metric_Parameters(2, 11, 8, 1)),
od1(Color_Style(information), Metric_Parameters(11, 11, 8, 1)),
od2(Color_Style(information), Metric_Parameters(20, 11, 8, 1)),
od3(Color_Style(information), Metric_Parameters(29, 11, 8, 1)),

//5 string
od_n0(Color_Style(information), Metric_Parameters(2, 13, 8, 1)),
od_n1(Color_Style(interactive), Metric_Parameters(11, 13, 8, 1),""),
od_n2(Color_Style(interactive), Metric_Parameters(20, 13, 8, 1),""),
od_n3(Color_Style(interactive), Metric_Parameters(29, 13, 8, 1),""),

//6 string
od_f0(Color_Style(information), Metric_Parameters(2, 15, 8, 1)),
od_f1(Color_Style(interactive), Metric_Parameters(11, 15, 8, 1),""),
od_f2(Color_Style(interactive), Metric_Parameters(20, 15, 8, 1),""),
od_f3(Color_Style(interactive), Metric_Parameters(29, 15, 8, 1), ""),

//7 string
tr0(Color_Style(information), Metric_Parameters( 2, 17, 8, 1)),
tr1(Color_Style(information), Metric_Parameters(11, 17, 8, 1), ""),
tr2(Color_Style(information), Metric_Parameters(20, 17, 8, 1), ""),
tr3(Color_Style(information), Metric_Parameters(29, 17, 8, 1), ""),

//8 string
tr_os0(Color_Style(information), Metric_Parameters( 2, 19, 8, 1)),
tr_os1(Color_Style(interactive), Metric_Parameters(11, 19, 8, 1), ""),
tr_os2(Color_Style(interactive), Metric_Parameters(20, 19, 8, 1), ""),
tr_os3(Color_Style(interactive), Metric_Parameters(29, 19, 8, 1), ""),

//9 string
tr_od0(Color_Style(information), Metric_Parameters( 2, 21, 8, 1)),
tr_od1(Color_Style(interactive), Metric_Parameters(11, 21, 8, 1), ""),
tr_od2(Color_Style(interactive), Metric_Parameters(20, 21, 8, 1), ""),
tr_od3(Color_Style(interactive), Metric_Parameters(29, 21, 8, 1), ""),


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

Win_Result::~Win_Result()
{
}
//
//Win_Result_Handler::Win_Result_Handler()
//{
////	//Serial.begin(9600);
//}
//
//Win_Result_Handler::~Win_Result_Handler()
//{
//
//}