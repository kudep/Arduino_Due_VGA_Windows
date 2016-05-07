
#ifndef WIN_HELP_H_INCLUDED
#define WIN_HELP_H_INCLUDED
#include <VGA.h>
#include"VGA_base_windows.h"
#include"keyboard_handler.h"

class Win_Help :Win
{
public:
	Win_Help();
	~Win_Help();
	void update()
	{
		for (size_t i = 0; i < sizeof(parr) / 4; i++)
		{
			(*parr[i]).update();
		}
		content.update();
	}
	void refresh()
	{
		for (size_t i = 0; i < sizeof(parr) / 4; i++)
		{
			(*parr[i]).refresh();
		}
		content.refresh();
	}

	CntrlSubGroup background;
	CntrlSubGroup title;
	CntrlSubGroup_Extended_string content;
	//Extend button
	CntrlSubGroup extend_button0;
	CntrlSubGroup extend_button_description0;
private:
	void windows()
	{
		char str_title[7] = { 207, 238, 236, 238, 249, 252, 0 };//Помощь
		title.strcpy_center_text(str_title);
		char str_content[83] =
		{ 199, 228, 229, 241, 252, 32, 245, 240,
		224, 237, 232, 242, 252, 241, 255, 32,
		226, 241, 239, 238, 236, 238, 227, 224,
		242, 229, 235, 252, 237, 224, 255, 32, 232,
		237, 244, 238, 240, 236, 224, 246, 232, 255,
		44, 32, 239, 240, 232, 226, 229, 228, 232,
		237, 251, 32, 234, 238, 236, 225, 232,
		237, 224, 246, 232, 232, 32, 34, 227,
		238, 240, 255, 247, 232, 245, 32, 234,
		237, 238, 239, 238, 234, 34, 32, 0 };
		//Здесь храниться вспомогательная информация, приведины комбинации "горячих кнопок" 


		//{ 194, 241, 239, 238, 236, 238, 227,
		//224, 242, 229, 235, 252, 237, 224, 255,
		//32, 232, 237, 244, 238, 240, 236, 224,
		//246, 232, 255, 0 };//Вспомогательная информация

		//{ 199, 228, 229, 241, 252, 32, 225,
		//243, 228, 229, 242, 32, 240, 224, 231, 
		//236, 229, 249, 229, 237, 224, 32, 226,
		//241, 239, 238, 236, 238, 227, 224, 242,
		//229, 235, 252, 237, 224, 255, 32, 232, 
		//237, 244, 238, 240, 236, 224, 246, 232, 
		//255, 0 };//здесь будет размещена вспомогательная информация
		content.strcpy_center_text(str_content);

		char str_extend_button_description0[6] = { 205, 224, 231, 224, 228, 0 };//Назад
		extend_button_description0.strcpy_center_text(str_extend_button_description0);
	}

	static const int Top_shift1 = 4;
	static const int Top_shift2 = Top_shift1 + 1;
	static const int Top_shift3 = Top_shift2 + 2;

	static const int width_shift1 = 32;
	static const int width_shift2 = width_shift1 - 2;

	static const int Left_shift1 = 4;
	static const int Left_shift2 = Left_shift1 + 1;

	static const int Height_shift1 = 22;
	static const int Height_shift2 = Height_shift1 - 4;



	CntrlSubGroup* parr[4] =
	{
		&background,
		&title,
		&extend_button0,
		&extend_button_description0
	};
};

class Win_Help_Handler : public Keyboard_Handler
{
public:
	Win_Help_Handler(Temporary_Data* _Temp_D, Data_Manager& _Data_Mngr) : Temp_D(_Temp_D)//, Keyboard_Handler(Data_Mngr)
	{
		Data_Mngr = &_Data_Mngr;
		win = new Win_Help;
	};
	~Win_Help_Handler()
	{
		//Serial.println("Start kill Win_Help_Handler");
		delete win;
		//Serial.println("Finish kill Win_Help_Handler");
	};

	void init()
	{
		Keyboard_Handler::init();

		(*win).refresh();
	}

	void action_buttonF1()
	{
		set_jump(get_back_handler());
	};
	void set_back_handler(id_wind  _back_handler)
	{
		back_handler = _back_handler;
	}
private:
	id_wind back_handler = id_wind_data;
	Win_Help* win;
	Temporary_Data* Temp_D;

	id_wind get_back_handler()
	{
		return back_handler;
	}

};

#endif