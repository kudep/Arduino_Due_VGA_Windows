#ifndef KEYBOARD_HANDLER_H_INCLUDED
#define KEYBOARD_HANDLER_H_INCLUDED
#include"database_structure.h"
#include <VGA.h>

enum id_wind { id_wind_undifine, id_wind_help, id_wind_data, id_wind_oper, id_wind_result, id_wind_end };

class Keyboard_Handler
{
public:
	Keyboard_Handler();
	~Keyboard_Handler();
	virtual void init()
	{
		reset_jump();
		win_clear();
	};
	virtual void finit()
	{
		reset_jump();
	};
	virtual void action_button1(){};
	virtual void action_button2(){};
	virtual void action_button3(){};
	virtual void action_button4(){};
	virtual void action_button5(){};
	virtual void action_button6(){};
	virtual void action_button7(){};
	virtual void action_button8(){};
	virtual void action_button9(){};

	virtual void action_buttonF1(){};
	virtual void action_buttonF2(){};
	virtual void action_buttonF3(){};
	virtual void action_buttonF4(){};
	virtual void action_buttonF5(){};

	virtual void action_button_left_point(){};
	virtual void action_button_rigth_point(){};

	virtual void set_word(const char word){};

	virtual bool get_jump(){ return jump; };

	virtual id_wind get_handler(){ return handler_num; };

	virtual void push_message(id_wind m_t){};

	virtual void set_back_handler(id_wind  _back_handler){}
protected:
	bool jump = false;
	id_wind handler_num = id_wind_undifine;

	virtual id_wind get_back_handler(){ return id_wind_undifine; }

	virtual void win_clear()
	{
		VGA.clearPrintWindow();
	}
	virtual void set_jump(id_wind  _handler)
	{
		jump = true;
		handler_num = _handler;
	}
	virtual void reset_jump()
	{
		jump = false;
	}
};

#endif