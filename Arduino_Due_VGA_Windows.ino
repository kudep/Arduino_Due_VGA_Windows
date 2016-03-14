#include <VGA.h>
#include"win_data.h"
#include"win_help.h"
#include"win_operation.h"
#include"win_result.h"
#include"win_mess.h"
#include"longtime.h"


int count = 0;
Keyboard_Handler* pw;
Keyboard_Handler* pwh;
Keyboard_Handler* pwd;
Win_Oper_Handler* pwo;
Keyboard_Handler* pwr;
Keyboard_Handler* pwm;
Temporary_Data Temp_D;
CLongTimer TMR1(1000);//таймер для часов
Win_Result*wd;
void change_wind()
{
	static id_wind handler_num = id_wind_undifine;
	Serial.println((*pw).get_handler());
	if ((*pw).get_jump())
	{
		(*pw).finit();
		switch ((*pw).get_handler())
		{
		case id_wind_help:
			Serial.println("Go to help");
			pw = pwh;
			if (handler_num != id_wind_undifine) 
				(*pw).set_back_handler(handler_num);
			else
				(*pw).set_back_handler(id_wind_data);
			break;
		case id_wind_data:
			Serial.println("Go to data");
			pw = pwd;
			break;
		case id_wind_oper:
			Serial.println("Go to oper");
			pw = pwo;
			break;
		case id_wind_result:
			Serial.println("Go to result");
			pw = pwr;
			break;

		case id_wind_end:
			Serial.println("Go to mess of the end");
			pw = pwm;
			(*pw).set_back_handler(id_wind_data);
			(*pw).push_message(id_wind_end);
			break;
		default:
			Serial.println("Ooops!"); 
			break;
		}
		handler_num = (*pw).get_handler();
		(*pw).init();
	}
}


void refresh_timer()
{
	(*pwo).refresh_timer();
}
void setup()
{
	Serial.begin(9600);
	VGA.begin(320, 240, VGA_COLOUR);

	pwh = new Win_Help_Handler(&Temp_D);
	pwd = new Win_Data_Handler(&Temp_D);
	pwo = new Win_Oper_Handler(&Temp_D);
	pwr = new Win_Result_Handler(&Temp_D);
	pwm = new Win_Mess_Handler(&Temp_D);

	TMR1.event(refresh_timer);
	TMR1.start();

	pw = pwd;
	(*pw).init();
}
const int deley_t = 100;
void perebor()
{
	Serial.println("Variation");
	(*pw).action_button1();
	(*pw).action_button_left_point();
	delay(deley_t);
	TMR1.tick();
	(*pw).set_word(255);
	(*pw).action_button_left_point();
	delay(deley_t);
	TMR1.tick();
	(*pw).action_button2();
	delay(deley_t);
	TMR1.tick();
	(*pw).set_word(255);
	(*pw).action_button_rigth_point();
	delay(deley_t);
	TMR1.tick();
	(*pw).action_button3();
	(*pw).action_button_rigth_point();
	delay(deley_t);
	TMR1.tick();
	(*pw).set_word(255);
	(*pw).action_button_rigth_point();
	delay(deley_t);
	TMR1.tick();
	(*pw).action_button4();
	delay(deley_t);
	TMR1.tick();
	(*pw).set_word(255);
	(*pw).action_button_rigth_point();
	delay(deley_t);
	TMR1.tick();
	(*pw).action_button5();
	delay(deley_t);
	TMR1.tick();
	(*pw).set_word(255);
	(*pw).action_button_rigth_point();
	delay(deley_t);
	TMR1.tick();
	(*pw).action_button6();
	delay(deley_t);
	TMR1.tick();
	(*pw).set_word(255);
	(*pw).action_button_rigth_point();
	delay(deley_t);
	TMR1.tick();
	(*pw).action_button6();
	delay(deley_t);
	TMR1.tick();
	(*pw).set_word(255);
	(*pw).action_button_rigth_point();
	delay(deley_t);
	TMR1.tick();

	(*pw).action_button7();
	delay(deley_t);
	TMR1.tick();
	(*pw).set_word(255);
	delay(deley_t);

	TMR1.tick();
	(*pw).action_button8();
	delay(deley_t);
	TMR1.tick();
	(*pw).set_word(255);
	delay(deley_t);
	TMR1.tick();
	(*pw).action_button9();
	delay(deley_t);
	TMR1.tick();
	(*pw).set_word(255);
	delay(deley_t);
	TMR1.tick();
}
int i_Loop = 0;
void loop()
{

	TMR1.tick();
	perebor();
	(*pw).action_buttonF1();
	change_wind();
	perebor();
	(*pw).action_buttonF1();
	change_wind();
	perebor();
	(*pw).action_buttonF3();
	change_wind();
	perebor();
	(*pw).action_buttonF2();
	change_wind();
	perebor();
	(*pw).action_buttonF3();
	change_wind();
	perebor();
	(*pw).action_buttonF1();
	change_wind();
	perebor();
	(*pw).action_buttonF1();
	change_wind();
	(*pw).action_buttonF2();
	change_wind();
	perebor();
	(*pw).action_buttonF3();
	change_wind();
	perebor();
	(*pw).action_buttonF3();
	change_wind();
	perebor();
	(*pw).action_buttonF3();
	change_wind();
	perebor();
	Serial.print("NUm loop "); 
	Serial.println(i_Loop);
	i_Loop++;
	
}
