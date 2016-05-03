
#ifndef WIN_OPERATION_H_INCLUDED
#define WIN_OPERATION_H_INCLUDED
#include <VGA.h>
#include"VGA_base_windows.h"
#include"keyboard_handler.h"

class Win_Oper :Win
{
public:
	Win_Oper();
	~Win_Oper();
	void update()
	{
		for (size_t i = 0; i < sizeof(parr) / 4; i++)
		{
			(*parr[i]).update();
		}
	}
	void refresh()
	{
		for (size_t i = 0; i < sizeof(parr) / 4; i++)
		{
			(*parr[i]).refresh();
		}
	}

	//1 string
	CntrlSubGroup start_position0;
	CntrlSubGroup start_position1;

	//2 string
	CntrlSubGroup test_obj_mode0;
	CntrlSubGroup test_obj_mode1;

	//3 string
	CntrlSubGroup patient_controller0;
	CntrlSubGroup patient_controller1;

	//4 string
	CntrlSubGroup eye_mode0;
	CntrlSubGroup eye_mode1;

	//5 string
	CntrlSubGroup focus_point0;
	CntrlSubGroup focus_point1;

	//6 string
	CntrlSubGroup record_position0;
	CntrlSubGroup record_position1;

	//7 string
	CntrlSubGroup remove_record0;
	CntrlSubGroup remove_record1;

	//8 string
	CntrlSubGroup chang_test_obj0;
	CntrlSubGroup chang_test_obj1;

	//9 string
	CntrlSubGroup timer0;
	CntrlSubGroup timer1;



	//Extend button
	CntrlSubGroup extend_button0;
	CntrlSubGroup extend_button1;
	CntrlSubGroup extend_button2;
	CntrlSubGroup extend_button3;
	CntrlSubGroup extend_button4;

	CntrlSubGroup extend_button_description0;
	CntrlSubGroup extend_button_description1;
	CntrlSubGroup extend_button_description2;
	CntrlSubGroup extend_button_description3;
	CntrlSubGroup extend_button_description4;
private:
	void windows()
	{
		//1 string
		char str_start_position0[13] = { 32, 49, 46, 205, 224, 247, 46, 32, 239, 238, 231, 46, 0 };// 1.Нач. поз.
		start_position0.strcpy_text(str_start_position0);
		char str_start_position1[13] = { 207, 229, 240, 229, 233, 242, 232, 0 };//Перейти
		start_position1.strcpy_center_text(str_start_position1);
		

		//2 string
		char str_test_obj_mode0[13] = { 32, 50, 46, 210, 229, 241, 242, 32, 238, 225, 45, 242, 0 };// 2.Тест об-т
		test_obj_mode0.strcpy_text(str_test_obj_mode0);
		test_obj_mode1.strcpy_center_text("Kuznetsov");

		//3 string
		char str_patient_controller0[13] = { 51, 46, 202, 238, 237, 242, 240, 238, 235, 235, 229, 240, 0 };//3.Контроллер
		patient_controller0.strcpy_text(str_patient_controller0);
		patient_controller1.strcpy_center_text("Pavlovich");

		//4 string
		char str_eye_mode0[13] = { 32, 32, 32, 32, 32, 32, 52, 46, 195, 235, 224, 231, 0 };//      4.Глаз
		eye_mode0.strcpy_text(str_eye_mode0);
		eye_mode1.strcpy_center_text("Denis");

		//5 string
		char str_focus_point1[13] = { 32, 32, 32, 32, 32, 53, 46, 212, 238, 234, 243, 241, 0 };//     5.Фокус
		focus_point0.strcpy_text(str_focus_point1);
		focus_point1.strcpy_center_text("Pavlovich");

		//6 string
		char str_record_position0[13] = { 32, 32, 54, 46, 199, 224, 239, 232, 241, 224, 242, 252, 0 };//  6.Записать
		record_position0.strcpy_text(str_record_position0);
		record_position1.strcpy_center_text("1251");

		//7 string
		char str_remove_record0[13] = { 55, 46, 211, 228, 224, 235, 46, 32, 231, 224, 239, 46, 0 };//7.Удал. зап.
		remove_record0.strcpy_text(str_remove_record0);
		remove_record1.strcpy_center_text("10.03.16 0:0");

		//8 string
		char str_chang_test_obj0[13] = { 56, 46, 209, 236, 229, 237, 224, 32, 232, 231, 225, 46, 0 };//8.Смена изб.
		chang_test_obj0.strcpy_text(str_chang_test_obj0);
		chang_test_obj1.strcpy_center_text("Kuznetsov");

		//9 string
		char str_timer0[13] = { 32, 32, 32, 57, 46, 32, 210, 224, 233, 236, 229, 240, 0 };//   9. Таймер
		timer0.strcpy_text(str_timer0);
		timer1.strcpy_center_text("Kuznetsov");
		

		char str_extend_button_description0[8] = { 207, 238, 236, 238, 249, 252, 0 };//Помощь
		extend_button_description0.strcpy_center_text(str_extend_button_description0);

		char str_extend_button_description1[8] = { 205, 224, 231, 224, 228, 0 };//Назад
		extend_button_description1.strcpy_center_text(str_extend_button_description1);

		char str_extend_button_description2[8] = { 196, 224, 235, 229, 229, 0 };//Далее
		extend_button_description2.strcpy_center_text(str_extend_button_description2);
		

	}

	CntrlSubGroup* parr[28] = 
	{ 
	&start_position0, &start_position1, &test_obj_mode0,
	&test_obj_mode1, &patient_controller0, &patient_controller1, 
	&eye_mode0, &eye_mode1, &focus_point0, &focus_point1,
	&record_position0, &record_position1,	&remove_record0, 
	&remove_record1, &chang_test_obj0, &chang_test_obj1,
	&timer0, &timer1, &extend_button0, &extend_button1,
	&extend_button2, &extend_button3, &extend_button4,
	&extend_button_description0, &extend_button_description1,
	&extend_button_description2, &extend_button_description3,
	&extend_button_description4 
	};


};

struct Temp_Param_Win_Oper
{
	float start_position = 0;
	bool test_obj_mode = false;
	bool ptnt_controller = false;
	bool eye = false;
	bool focus_point = false;
	float record_position = 0;
	int image_num = 0;
	int timer_count = 0;
	bool timer_switch = false;

	void reset()
	{
		start_position = 0;
		test_obj_mode = false;
		ptnt_controller = false;
		eye = false;
		focus_point = false;
		record_position = 0;
		image_num = 0;
		int timer_count = 0;
		bool timer_switch = false;
	}
	void change_test_obj_mode()
	{
		test_obj_mode = !test_obj_mode;

	}
	const char* get_test_obj_mode()
	{
		char _true_str[6] = { 209, 235, 224, 233, 228, 0 };//Слайд
		char _false_str[8] = { 196, 232, 241, 239, 235, 229, 233, 0 };//Дисплей
		strcpy(true_str, _true_str);
		strcpy(false_str, _false_str);
		if (test_obj_mode)
			return true_str;
		else
			return false_str;

	}
	void change_ptnt_controller()
	{
		ptnt_controller = !ptnt_controller;

	}
	const char* get_ptnt_controller()
	{
		char _true_str[2] = { 187, 0 };//Флаг
		char _false_str[1] = { 0 };
		strcpy(true_str, _true_str);
		strcpy(false_str, _false_str);
		if (ptnt_controller)
			return true_str;
		else
			return false_str;

	}
	void change_eye()
	{
		eye = !eye;

	}
	const char* get_eye()
	{
		char _true_str[] = "OS";
		char _false_str[] = "OD";
		strcpy(true_str, _true_str);
		strcpy(false_str, _false_str);
		if (ptnt_controller)
			return true_str;
		else
			return false_str;

	}
	void change_focus_point()
	{
		focus_point = !focus_point;

	}
	const char* get_focus_point()
	{
		char _true_str[8] = { 193, 235, 232, 230, 237, 232, 233, 0 };//Ближний
		char _false_str[8] = { 196, 224, 235, 252, 237, 232, 233, 0 };//Дальний
		strcpy(true_str, _true_str);
		strcpy(false_str, _false_str);
		if (focus_point)
			return true_str;
		else
			return false_str;

	}
	void change_timer_switch()
	{
		timer_switch = !timer_switch;

	}
	void change_image_num()
	{
		if (image_num < 4)
			image_num++;
		else
			image_num = 0;

	}
private:
	char true_str[11];
	char false_str[11];
};

class Win_Oper_Handler : public Keyboard_Handler
{
public:
	Win_Oper_Handler(Temporary_Data* _Temp_D, Data_Manager& _Data_Mngr) :Temp_D(_Temp_D)//, Keyboard_Handler(Data_Mngr)
	{
		Data_Mngr = &_Data_Mngr;
		win = new Win_Oper;

		Temp_P.reset();
	};
	~Win_Oper_Handler()
	{
		delete win;
	};

	void init()
	{
		Keyboard_Handler::init();

		vision = true;
		(*win).test_obj_mode1.strcpy_center_text(Temp_P.get_test_obj_mode());
		(*win).patient_controller1.strcpy_center_text(Temp_P.get_ptnt_controller());
		(*win).eye_mode1.strcpy_center_text(Temp_P.get_eye());
		(*win).focus_point1.strcpy_center_text(Temp_P.get_focus_point());
		(*win).record_position1.strcpy_center_text(Temp_P.record_position, POINT_AFTER_COMMA);
		(*win).remove_record1.strcpy_center_text((*((*Temp_D).access_meas_p(Temp_P.eye, Temp_P.focus_point))).seq.top(), POINT_AFTER_COMMA);
		(*win).chang_test_obj1.strcpy_center_text(Temp_P.image_num);
		(*win).timer1.strcpy_center_text(get_time(Temp_P.timer_count));
		(*win).refresh();
	}

	void finit()
	{
		Keyboard_Handler::finit();

		vision = false;
		(*Temp_D).t_eye.time = Temp_P.timer_count;
	}
	void action_button1()
	{
		disable_buttons();

		(*win).start_position1.enable();
		(*win).update();

	};

	void action_button2()
	{
		disable_buttons();

		Temp_P.change_test_obj_mode();
		(*win).test_obj_mode1.strcpy_center_text(Temp_P.get_test_obj_mode());

		(*win).test_obj_mode1.enable();
		(*win).update();

	};

	void action_button3()
	{
		disable_buttons();

		Temp_P.change_ptnt_controller();
		(*win).patient_controller1.strcpy_center_text(Temp_P.get_ptnt_controller());

		(*win).patient_controller1.enable();
		(*win).update();

	};

	void action_button4()
	{
		disable_buttons();

		Temp_P.change_eye();
		(*win).eye_mode1.strcpy_center_text(Temp_P.get_eye());
		(*win).remove_record1.strcpy_center_text((*((*Temp_D).access_meas_p(Temp_P.eye, Temp_P.focus_point))).seq.top());

		(*win).eye_mode1.enable();
		(*win).update();

	};

	void action_button5()
	{
		disable_buttons();

		Temp_P.change_focus_point();
		(*win).focus_point1.strcpy_center_text(Temp_P.get_focus_point());
		(*win).remove_record1.strcpy_center_text((*((*Temp_D).access_meas_p(Temp_P.eye, Temp_P.focus_point))).seq.top(), POINT_AFTER_COMMA);

		(*win).focus_point1.enable();
		(*win).update();

	};

	void action_button6()
	{
		disable_buttons();
		(*((*Temp_D).access_meas_p(Temp_P.eye, Temp_P.focus_point))).seq.push(Temp_P.record_position);
		(*win).remove_record1.strcpy_center_text((*((*Temp_D).access_meas_p(Temp_P.eye, Temp_P.focus_point))).seq.top(), POINT_AFTER_COMMA);
		(*win).record_position1.enable();
		(*win).update();
	};

	void action_button7()
	{
		disable_buttons();

		(*((*Temp_D).access_meas_p(Temp_P.eye, Temp_P.focus_point))).seq.pop();
		(*win).remove_record1.strcpy_center_text((*((*Temp_D).access_meas_p(Temp_P.eye, Temp_P.focus_point))).seq.top(), POINT_AFTER_COMMA);
		(*win).remove_record1.enable();
		(*win).update();
	};

	void action_button8()
	{
		disable_buttons();
		Temp_P.change_image_num();
		(*win).chang_test_obj1.enable();
		(*win).update();

	};

	void action_button9()
	{
		disable_buttons();
		Temp_P.change_timer_switch();
		(*win).chang_test_obj1.strcpy_center_text(Temp_P.image_num);
		(*win).timer1.enable();
		(*win).update();

	};

	void action_buttonF1()
	{
		set_jump(id_wind_help);
	};

	void action_buttonF2()
	{
		set_jump(id_wind_option);
	};


	void action_buttonF3()
	{
		set_jump(id_wind_result);
	};

	void refresh_timer() 
	{
		Keyboard_Handler::refresh_timer();

		if (Temp_P.timer_switch)
		{
			Temp_P.timer_count++;
			(*win).timer1.strcpy_center_text(get_time(Temp_P.timer_count));
			if(vision)(*win).update();
		}
	};

	void action_button_left_point()
	{
		Temp_P.record_position-=10.7;
		(*win).record_position1.strcpy_center_text(Temp_P.record_position, POINT_AFTER_COMMA);
		(*win).update();
	};
	void action_button_rigth_point()
	{
		Temp_P.record_position+=9.3;
		(*win).record_position1.strcpy_center_text(Temp_P.record_position, POINT_AFTER_COMMA);
		(*win).update();
	};
private:
	Win_Oper* win;
	Temporary_Data* Temp_D;
	Temp_Param_Win_Oper Temp_P;
	bool vision = false;
	char s[7];
	void itoa(int n, char s[])
	{
		int i, sign;

		if ((sign = n) < 0)  /* записываем знак */
			n = -n;          /* делаем n положительным числом */
		i = 0;
		do {       /* генерируем цифры в обратном порядке */
			s[i++] = n % 10 + '0';   /* берем следующую цифру */
		} while ((n /= 10) > 0);     /* удаляем */
		if (sign < 0)
			s[i++] = '-';
		s[i] = '\0';
		reverse(s);
	}
	void reverse(char s[])
	{
		int i, j;
		char c;

		for (i = 0, j = strlen(s) - 1; i<j; i++, j--) {
			c = s[i];
			s[i] = s[j];
			s[j] = c;
		}
	}
	const char* get_time(int count)
	{
		s[0] = 0;
		char mm[3];
		char ss[3];
		int var1 = (count / 60) % 60;
		int var2 = count % 60;
		itoa(var1, mm);
		itoa(var2, ss);
		strcat(s, mm);
		strcat(s, ":");
		strcat(s, ss);
		return s;
	}

	void disable_buttons()
	{
		(*win).start_position1.disable();
		(*win).test_obj_mode1.disable();
		(*win).patient_controller1.disable();
		(*win).eye_mode1.disable();
		(*win).record_position1.disable();
		(*win).remove_record1.disable();
		(*win).focus_point1.disable();
		(*win).chang_test_obj1.disable();
		(*win).timer1.disable();
	}

};


#endif