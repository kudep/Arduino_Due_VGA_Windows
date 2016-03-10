#include <VGA.h>
#include"VGA_windows_reduce.h"


//CntrlSubGroup counter(Color_Style(sg_f), Metric_Parameters(35, 1, 4, 1));

Win_Data* win1;
Win2* win2;
Win_help* win_help;
int count = 0;
void setup()
{
	Serial.begin(9600);
	VGA.begin(320, 240, VGA_COLOUR);
	win1 = new Win_Data;
	win2 = new Win2;
	win_help = new Win_help;
	(*win1).refresh();
	//(*win2).refresh();
	//(*win_help).refresh();
	//(*win_help).refresh();
	
}
void help_function_1()
{

	Serial.println("Good start 1");
	(*win1).refresh();
	count++;
	(*win1).data_time1.state_switch();
	//(*win1).set_time(count);
	(*win1).name1.strcpy_center_text("Denis");
	(*win1).update();
	delay(500);
	(*win1).name1.strcpy_center_text("Deni");
	(*win1).update();
	delay(500);
	(*win1).name1.strcpy_center_text("Den");
	(*win1).update();
	delay(500);
	(*win1).name1.strcpy_center_text("De");
	(*win1).update();
	delay(500);
	(*win1).name1.strcpy_center_text("D");
	(*win1).update();
	delay(500);
	(*win1).name1.strcpy_center_text("");
	(*win1).update();
	delay(500);
	Serial.println("Good end 1");
}
void help_function_2()
{
	Serial.println("Good start 2");
	(*win2).refresh();
	count++;
	//(*win2).data_time1.state_switch();
	//(*win2).set_time(count);
	//(*win2).name1.strcpy_center_text("Denis");
	//(*win2).update();
	//delay(500);
	//(*win2).name1.strcpy_center_text("Deni");
	//(*win2).update();
	//delay(500);
	//(*win2).name1.strcpy_center_text("Den");
	//(*win2).update();
	//delay(500);
	//(*win2).name1.strcpy_center_text("De");
	//(*win2).update();
	//delay(500);
	//(*win2).name1.strcpy_center_text("D");
	//(*win2).update();
	//delay(500);
	//(*win2).name1.strcpy_center_text("");
	//(*win2).update();
	//delay(500);
	delay(2500);
	Serial.println("Good end 2");
}
void loop()
{
	//(*win_help).refresh();
	//help_function_1();
	//help_function_2();
	
}
