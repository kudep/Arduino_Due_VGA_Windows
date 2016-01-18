#include"VGA_windows.h"

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




Win2::Win2() : data_time1(Color_Style(sg_f), Metric_Parameters(2, 1, 6, 1), "asdf"),
data_time2(Color_Style(sg_f), Metric_Parameters(8, 1, 12, 1)),
data_time3(Color_Style(sg_f), Metric_Parameters(21, 1, 7, 1), "zxcv"),
data_time4(Color_Style(sg_f), Metric_Parameters(28, 1, 7, 1)),

full_name(Color_Style(sg_f), Metric_Parameters(12, 5, 16, 1), "zxcv"),
surname(Color_Style(sg_f), Metric_Parameters(1, 7, 13, 1), "asdf"),
surname1(Color_Style(sg_f), Metric_Parameters(15, 7, 24, 1)),
name(Color_Style(sg_f), Metric_Parameters(1, 9, 13, 1), "ZXC"),
name1(Color_Style(sg_f), Metric_Parameters(15, 9, 24, 1)),
middle_name(Color_Style(sg_f), Metric_Parameters(1, 11, 13, 1), "sdfh Name"),
middle_name1(Color_Style(sg_f), Metric_Parameters(15, 11, 24, 1)),

eye_ametropia(Color_Style(sg_f), Metric_Parameters(12, 18, 16, 1), "Eye-sdfg:"),
OD(Color_Style(sg_f), Metric_Parameters(8, 20, 4, 1), "sdfg"),
OD1(Color_Style(sg_f), Metric_Parameters(13, 20, 3, 1)),
OD2(Color_Style(sg_f), Metric_Parameters(17, 20, 6, 1)),
OD3(Color_Style(sg_f), Metric_Parameters(24, 20, 8, 1)),

OS(Color_Style(sg_f), Metric_Parameters(8, 22, 4, 1), "sdfg"),
OS1(Color_Style(sg_f), Metric_Parameters(13, 22, 3, 1)),
OS2(Color_Style(sg_f), Metric_Parameters(17, 22, 6, 1)),
OS3(Color_Style(sg_f), Metric_Parameters(24, 22, 8, 1)),

extern_button0(Color_Style(sg_f), Metric_Parameters(1, 28, 8, 1), "sdg"),
extern_button1(Color_Style(sg_f), Metric_Parameters(8, 28, 8, 1), "F"),
extern_button2(Color_Style(sg_f), Metric_Parameters(16, 28, 8, 1), "F3"),
extern_button3(Color_Style(sg_f), Metric_Parameters(24, 28, 8, 1), "F4"),
extern_button4(Color_Style(sg_f), Metric_Parameters(32, 28, 7, 1), "F5"),

extern_button_description0(Color_Style(sg_f), Metric_Parameters(1, 29, 7, 1), "tyu"),
extern_button_description1(Color_Style(sg_f), Metric_Parameters(8, 29, 8, 1), "asdf"),
extern_button_description2(Color_Style(sg_f), Metric_Parameters(16, 29, 8, 1), "fjh"),
extern_button_description3(Color_Style(sg_f), Metric_Parameters(24, 29, 8, 1), "fj"),
extern_button_description4(Color_Style(sg_f), Metric_Parameters(32, 29, 7, 1), "dfg")
{
	flag[0] = (char)187;
	flag[1] = (char)0;
	windows();
}

Win2::~Win2()
{
}
