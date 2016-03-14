
#ifndef WIN_MESS_H_INCLUDED
#define WIN_MESS_H_INCLUDED
#include <VGA.h>
#include"VGA_base_windows.h"
#include"keyboard_handler.h"

class Win_Mess :Win
{
public:
	Win_Mess();
	~Win_Mess();
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
		char str_title[9] = { 194, 237, 232, 236, 224, 237, 232, 229, 0 };//Внимание
		title.strcpy_center_text(str_title);
		char str_content[1] = { 0 };
		content.strcpy_center_text(str_content);

		char str_extend_button_description0[8] = { 207, 240, 238, 228, 238, 235, 46, 0 };//Продол.
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

class Win_Mess_Handler : public Keyboard_Handler
{
public:
	Win_Mess_Handler(Temporary_Data* _Temp_D) : Temp_D(_Temp_D)
	{
		win = new Win_Mess;
	};
	~Win_Mess_Handler()
	{
		delete win;
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
	void push_message(id_wind m_t)
	{
		char str_mess_end[] = { 208, 229, 231, 243, 235, 252, 242,
			224, 242, 32, 241, 238, 245, 240, 224,
			237, 229, 237, 0 };//Результат сохранен

		switch (m_t)
		{
		case id_wind_end:
			(*win).content.strcpy_center_text(str_mess_end);
			break;
		default:
			(*win).content.strcpy_center_text(" ");
			break;
		}

		(*win).update();
	}
private:
	id_wind back_handler = id_wind_data;
	Win_Mess* win;
	Temporary_Data* Temp_D;

	id_wind get_back_handler()
	{
		return back_handler;
	}

};


#endif