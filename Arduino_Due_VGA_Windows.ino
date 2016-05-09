#include <VGA.h>
#include"win_help.h"
#include"win_data.h"
#include"win_options.h"
#include"win_operation.h"
#include"win_train.h"
#include"win_result.h"
#include"win_mess.h"
#include"longtime.h"

#include <SPI.h>
#include <SD.h>
//#include"data_manager.h"


// Require keyboard control library
#include <KeyboardController.h>
//
extern char cp1251_en_to_ru[];

// Initialize USB Controller
USBHost usb;

// Attach keyboard controller to USB
KeyboardController keyboard(usb);

Keyboard_Handler* pw;

Temporary_Data Temp_D;

Data_Manager Data_Mngr(Temp_D);

CLongTimer TMR1(1000);
int count = 1;

// This function intercepts key press
void keyPressed()
{
	Process();
}

// This function intercepts key release
void keyReleased()
{

}
void change_wind(void);

void Process() 
{

	// getModifiers() returns a bits field with the modifiers-keys
	int mod = keyboard.getModifiers();

	if ((mod & LeftCtrl) || (mod & RightCtrl))
	{
		switch (keyboard.getKey())
		{
		case	49:	//"1"
			(* pw).action_button1();
			break;

		case	50:	//"2"
			(* pw).action_button2();
			break;

		case	51:	//"3"
			(* pw).action_button3();
			break;

		case	52:	//"4"
			(* pw).action_button4();
			break;

		case	53:	//"5"
			(* pw).action_button5();
			break;

		case	54:	//"6"
			(* pw).action_button6();
			break;

		case	55:	//"7"
			(* pw).action_button7();
			break;

		case	56:	//"8"
			(* pw).action_button8();
			break;

		case	57:	//"9"
			(* pw).action_button9();
			break;

		default:
			break;
		}
	}
	else
	{
		switch (keyboard.getOemKey())
		{
		case	58:	//"F1"
			(* pw).action_buttonF1();
     Serial.println("F1");
			break;

		case	59:	//"F2"
			(* pw).action_buttonF2();
			break;

		case	60:	//"F3"
			(* pw).action_buttonF3();
			break;

		case	61:	//"F4"
			(* pw).action_buttonF4();
			break;

		case	62:	//"F5"
			(* pw).action_buttonF5();
			break;

		case	79:	//"Right point"
			(* pw).action_button_rigth_point();
			break;

		case	80:	//"Left point"
			(* pw).action_button_left_point();
			break;

		default:
			(* pw).set_word(cp1251_en_to_ru[keyboard.getKey()]);
			break;
		}

	}

	change_wind();

	// getKey() returns the ASCII translation of OEM key
	// combined with modifiers.cp1251_en_to_ru[keyboard.getKey()]);
}

void change_wind()
{
	static id_wind handler_num = id_wind_undifine;
	Serial.println((*pw).get_handler());
	if ((*pw).get_handler() != id_wind_help) handler_num = (*pw).get_handler();
	if ((*pw).get_jump())
	{
		(*pw).finit();
		switch ((*pw).get_handler())
		{
		case id_wind_help:
			Serial.println("Go to help");
			delete pw;
			pw = new Win_Help_Handler(&Temp_D, Data_Mngr);
			if (handler_num != id_wind_undifine) 
				(*pw).set_back_handler(handler_num);
			else
				(*pw).set_back_handler(id_wind_data);
			break;
		case id_wind_data:
			Serial.println("Go to data");
			delete pw;
			pw = new Win_Data_Handler(&Temp_D, Data_Mngr);
			break;
		case id_wind_option:
			Serial.println("Go to option");
			delete pw;
			pw = new Win_Option_Handler(&Temp_D, Data_Mngr);
			break;
		case id_wind_oper:
			Serial.println("Go to oper");
			delete pw;
			pw = new Win_Oper_Handler(&Temp_D, Data_Mngr);
			break;
		case id_wind_train:
			Serial.println("Go to train");
			delete pw;
			pw = new Win_Train_Handler(&Temp_D, Data_Mngr);
			break;
		case id_wind_result:
			Serial.println("Go to result");
			delete pw;
			pw = new Win_Result_Handler(&Temp_D, Data_Mngr);;
			break;

		case id_wind_end:
			Serial.println("Go to mess of the end");
			delete pw;
			pw = new Win_Mess_Handler(&Temp_D, Data_Mngr);
			(*pw).set_back_handler(id_wind_data);
			(*pw).push_message(id_wind_end);
			break;

		case id_wind_error_verif_data_mngr:
			Serial.println("Go to mess of the end");
			if (false)
			{
				(*pw).set_back_handler(handler_num);
			}
			(*pw).push_message(id_wind_error_verif_data_mngr);
			break;
		default:
			Serial.println("Ooops!"); 
			break;
		}
		(*pw).init();
	}
}


void refresh_timer()
{
	(*pw).refresh_timer();
}
void setup()
{
	Serial.begin(9600);
	VGA.begin(320, 240, VGA_COLOUR);

	TMR1.event(refresh_timer);
	TMR1.start();

	pw = new Win_Data_Handler(&Temp_D, Data_Mngr);//This window is first
	(*pw).init();
}
const int deley_t = 100;

int i_Loop = 0;
void loop()
{
	TMR1.tick();

	// Process USB tasks
	usb.Task();



	//count++;
	//Serial.println(count);
	////delay(100);
	//(*pw).finit();
	//delete pw;
	//pw = new Win_Help_Handler(&Temp_D, Data_Mngr);
	//(*pw).init();
	//(*pw).finit();
	//delete pw;
	//pw = new Win_Data_Handler(&Temp_D, Data_Mngr);
	//(*pw).init();
	//(*pw).finit();
	//delete pw;
	//pw = new Win_Option_Handler(&Temp_D, Data_Mngr);
	//(*pw).init();
	//(*pw).finit();
	//delete pw;
	//pw = new Win_Oper_Handler(&Temp_D, Data_Mngr);
	//(*pw).init();
	//(*pw).finit();
	//delete pw;
	//pw = new Win_Train_Handler(&Temp_D, Data_Mngr);
	//(*pw).init();
	//(*pw).finit();
	//delete pw;
	//pw = new Win_Result_Handler(&Temp_D, Data_Mngr);
	//(*pw).init();
	//(*pw).finit();
	//delete pw;
	//pw = new Win_Mess_Handler(&Temp_D, Data_Mngr);

	//(*pw).init();
}
