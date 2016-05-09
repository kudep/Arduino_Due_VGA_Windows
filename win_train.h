
#ifndef WIN_TRAIN_H_INCLUDED
#define WIN_TRAIN_H_INCLUDED
#include <VGA.h>
#include"VGA_base_windows.h"
#include"keyboard_handler.h"

#define EYE_DIV_VALUE_METRIC 0.5

class Win_Train :Win
{
public:
	Win_Train();
	~Win_Train();
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
	CntrlSubGroup chang_test_obj0;
	CntrlSubGroup chang_test_obj1;

	//3 string
	CntrlSubGroup chang_viz0;
	CntrlSubGroup chang_viz1;

	//4 string
	CntrlSubGroup patient_controller0;
	CntrlSubGroup patient_controller1;

	//5 string
	CntrlSubGroup auto_mode0;
	CntrlSubGroup auto_mode1;

	//6 string
	CntrlSubGroup eye_mode0;
	CntrlSubGroup eye_mode1;

	//7 string
	CntrlSubGroup focus_n0;
	CntrlSubGroup focus_n1;

	//8 string
	CntrlSubGroup focus_f0;
	CntrlSubGroup focus_f1;

	//9 string
	CntrlSubGroup position0;
	CntrlSubGroup position1;

	//Timer
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
		char str_start_position0[OFFSET_FOR_INFORMATION_ON_DISPLEY] = { 32, 49, 46, 209, 236, 229, 237, 232, 242, 252, 32, 241, 235, 224, 233, 228, 0 };//1.Сменить слайд
		start_position0.strcpy_text(str_start_position0);
		char str_start_position1[DATA_STRING_LENGTH] = { 209, 236, 229, 237, 232, 242, 252, 0 };//Сменить
		start_position1.strcpy_center_text(str_start_position1);
		
		//2 string
		char str_chang_test_obj0[OFFSET_FOR_INFORMATION_ON_DISPLEY] = { 32, 50, 46, 209, 236, 229, 237, 46, 32, 238, 239, 242, 238, 242, 232, 239, 0 };//2.Смен. оптотип
		chang_test_obj0.strcpy_text(str_chang_test_obj0);
		char str_chang_test_obj1[DATA_STRING_LENGTH] = { 209, 236, 229, 237, 232, 242, 252, 0 };//Сменить
		chang_test_obj1.strcpy_center_text(str_chang_test_obj1);

		//3 string
		char str_chang_viz0[OFFSET_FOR_INFORMATION_ON_DISPLEY] = { 32, 32, 51, 46, 200, 231, 236, 229, 237, 232, 242, 252, 32, 86, 73, 90, 0 };//3.Изменить VIZ
		chang_viz0.strcpy_text(str_chang_viz0);
		chang_viz1.strcpy_center_text("0.3");


		//4 string
		char str_patient_controller0[OFFSET_FOR_INFORMATION_ON_DISPLEY] = { 32, 52, 46, 211, 239, 240, 46, 32, 239, 224, 246, 232, 229, 237, 242, 224, 0 };//4.Упр. пациента
		patient_controller0.strcpy_text(str_patient_controller0);
		patient_controller1.strcpy_center_text("");

		//5 string
		char str_auto_mode0[OFFSET_FOR_INFORMATION_ON_DISPLEY] = { 53, 46, 192, 226, 242, 238, 236, 224, 242, 46, 32, 240, 229, 230, 232, 236, 0 };//5.Автомат. режим
		auto_mode0.strcpy_text(str_auto_mode0);
		auto_mode1.strcpy_center_text("");

		//6 string
		char str_eye_mode0[OFFSET_FOR_INFORMATION_ON_DISPLEY] = { 32, 32, 54, 46, 209, 236, 229, 237, 232, 242, 252, 32, 227, 235, 224, 231, 0 };//6.Сменить глаз
		eye_mode0.strcpy_text(str_eye_mode0);
		eye_mode1.strcpy_center_text("OS");

		//7 string
		char str_focus_n0[OFFSET_FOR_INFORMATION_ON_DISPLEY] = { 32, 55, 46, 193, 235, 232, 230, 237, 255, 255, 32, 227, 240, 224, 237, 252, 0 };//7.Ближняя грань
		focus_n0.strcpy_text(str_focus_n0);
		focus_n1.strcpy_center_text("0.0");

		//8 string

		char str_focus_f0[OFFSET_FOR_INFORMATION_ON_DISPLEY] = { 32, 56, 46, 196, 224, 235, 252, 237, 255, 255, 32, 227, 240, 224, 237, 252, 0 };//8.Дальняя грань
		focus_f0.strcpy_text(str_focus_f0);
		focus_f1.strcpy_center_text("0.0");

		//9 string
		char str_position0[OFFSET_FOR_INFORMATION_ON_DISPLEY] = { 57, 46, 32, 210, 229, 234, 243, 249, 229, 229, 32, 239, 238, 235, 238, 230, 0 };//9. Текущее полож
		position0.strcpy_text(str_position0);
		position1.strcpy_center_text("0.0");

		//Timer
		char str_timer0[OFFSET_FOR_INFORMATION_ON_DISPLEY] = { 206, 241, 242, 224, 226, 248, 229, 229, 241, 255, 32, 226, 240, 229, 236, 255, 0 };//Оставшееся время
		timer0.strcpy_text(str_timer0);
		timer1.strcpy_center_text("0");

		char str_extend_button_description0[8] = { 207, 238, 236, 238, 249, 252, 0 };//Помощь
		extend_button_description0.strcpy_center_text(str_extend_button_description0);

		char str_extend_button_description1[8] = { 205, 224, 231, 224, 228, 0 };//Назад
		extend_button_description1.strcpy_center_text(str_extend_button_description1);

		char str_extend_button_description2[8] = { 196, 224, 235, 229, 229, 0 };//Далее
		extend_button_description2.strcpy_center_text(str_extend_button_description2);


	}

	CntrlSubGroup* parr[32] =
	{
		&start_position0, &start_position1, &chang_test_obj0, &chang_test_obj1,
		&chang_viz0, &chang_viz1, &patient_controller0, &patient_controller1,
		&auto_mode0, &auto_mode1, &eye_mode0,
		&eye_mode1, &focus_n0, &focus_n1,
		&focus_f0, &focus_f1,
		&position0, &position1,
		&timer0, &timer1, &extend_button0, &extend_button1,
		&extend_button2, &extend_button3, &extend_button4,
		&extend_button_description0, &extend_button_description1,
		&extend_button_description2, &extend_button_description3,
		&extend_button_description4
	};


};

struct Temp_Param_Win_Train
{
	const bool const_eye_os = true;
	const bool const_eye_od = false;
	float start_position = 0;
	bool os = false;
	bool od = false;
	bool viz = false;
	bool ptnt_controller = false;
	bool auto_mode = false;
	bool eye = false;
	float focus_n = 0;
	float focus_f = 0;
	float position = 0;
	int timer_count = 0;

	void reset()
	{
		start_position = 0;
		os = false;
		od = false;
		viz = false;
		ptnt_controller = false;
		auto_mode = false;
		eye = false;
		focus_n = 0;
		focus_f = 0;
		position = 0;
		timer_count = 0;
	}


	void change_viz()
	{
		viz = !viz;

	}
	const char* get_viz()
	{
		char _true_str[6] = { 48, 46, 51, 0 };//0.3
		char _false_str[8] = { 48, 46, 55, 0 };//0.7
		strcpy(true_str, _true_str);
		strcpy(false_str, _false_str);
		if (viz)
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

	void change_auto_mode()
	{
		auto_mode = !auto_mode;

	}
	const char* get_auto_mode()
	{
		char _true_str[2] = { 187, 0 };//Флаг
		char _false_str[1] = { 0 };
		strcpy(true_str, _true_str);
		strcpy(false_str, _false_str);
		if (auto_mode)
			return true_str;
		else
			return false_str;

	}
	void change_eye()
	{
		if (os&&od)
			eye = !eye;
		else
			eye = os;

	}
	const char* get_eye()
	{
		char _true_str[] = "OS";
		char _false_str[] = "OD";
		strcpy(true_str, _true_str);
		strcpy(false_str, _false_str);
		if (eye)
			return true_str;
		else
			return false_str;

	}
private:
	char true_str[11];
	char false_str[11];
};

class Win_Train_Handler : public Keyboard_Handler
{
public:
	Win_Train_Handler(Temporary_Data* _Temp_D, Data_Manager& _Data_Mngr) :Temp_D(_Temp_D)//, Keyboard_Handler(Data_Mngr)
	{
		Data_Mngr = &_Data_Mngr;
		win = new Win_Train;

		Temp_P.reset();
	};
	~Win_Train_Handler()
	{
		delete win;
	};

	void init()
	{
		Keyboard_Handler::init();

		(*Temp_D).t_eye.time_spend_od = (*Temp_D).t_eye.setup_time_od;
		(*Temp_D).t_eye.time_spend_os = (*Temp_D).t_eye.setup_time_os;

		Temp_P.os = ((*Temp_D).t_eye.setup_time_os!=0);
		Temp_P.od = ((*Temp_D).t_eye.setup_time_od != 0);
		Temp_P.change_eye();
		vision = true;
		load();
		(*win).chang_viz1.strcpy_center_text(Temp_P.get_viz());
		(*win).patient_controller1.strcpy_center_text(Temp_P.get_ptnt_controller());
		(*win).auto_mode1.strcpy_center_text(Temp_P.get_auto_mode());
		(*win).eye_mode1.strcpy_center_text(Temp_P.get_eye());
		(*win).focus_n1.strcpy_center_text(Temp_P.focus_n, POINT_AFTER_COMMA);
		(*win).focus_f1.strcpy_center_text(Temp_P.focus_f, POINT_AFTER_COMMA);
		(*win).position1.strcpy_center_text(Temp_P.position, POINT_AFTER_COMMA);
		(*win).timer1.strcpy_center_text(get_time(Temp_P.timer_count));
		(*win).refresh();
	}

	void finit()
	{
		Keyboard_Handler::finit();
		save();
		set_point = 0;
		vision = false;
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
		(*win).chang_test_obj1.enable();
		(*win).update();

	};

	void action_button3()
	{
		disable_buttons();

		Temp_P.change_viz();
		(*win).chang_viz1.strcpy_center_text(Temp_P.get_viz());

		(*win).chang_viz1.enable();
		(*win).update();

	};

	void action_button4()
	{
		disable_buttons();

		Temp_P.change_ptnt_controller();
		(*win).patient_controller1.strcpy_center_text(Temp_P.get_ptnt_controller());

		(*win).patient_controller1.enable();
		(*win).update();

	};

	void action_button5()
	{
		disable_buttons();

		Temp_P.change_auto_mode();
		(*win).auto_mode1.strcpy_center_text(Temp_P.get_auto_mode());

		(*win).auto_mode1.enable();
		(*win).update();

	};

	void action_button6()
	{
		disable_buttons();


		save();
		Temp_P.change_eye();
		load();

		(*win).eye_mode1.strcpy_center_text(Temp_P.get_eye());
		(*win).focus_n1.strcpy_center_text(Temp_P.focus_n, POINT_AFTER_COMMA);
		(*win).focus_f1.strcpy_center_text(Temp_P.focus_f, POINT_AFTER_COMMA);
		(*win).timer1.strcpy_center_text(get_time(Temp_P.timer_count));

		(*win).eye_mode1.enable();

		(*win).update();

	};
	void action_button7()
	{
		disable_buttons();
		set_point = 7;

		(*win).focus_n1.enable();

		(*win).update();
	};

	void action_button8()
	{
		disable_buttons();
		set_point = 8;

		(*win).focus_f1.enable();

		(*win).update();
	};

	void action_button9()
	{
		disable_buttons();
		set_point = 9;

		(*win).focus_f1.enable();

		(*win).update();
	};

	void action_buttonF1()
	{
		set_jump(id_wind_help);
	};

	void action_buttonF2()
	{
		if ((*Temp_D).m_eye.os || (*Temp_D).m_eye.od)
			set_jump(id_wind_oper);
		else
			set_jump(id_wind_option);
	};


	void action_buttonF3()
	{
		set_jump(id_wind_result);
	};


	void action_button_left_point()
	{
		change_value_in_point(-1);
		(*win).update();
	};
	void action_button_rigth_point()
	{
		change_value_in_point(1);
		(*win).update();
	};
	void refresh_timer()
	{
		Keyboard_Handler::refresh_timer();
		if (Temp_P.timer_count >= 0)
			Temp_P.timer_count--;
		else
			Temp_P.timer_count = 0;

			(*win).timer1.strcpy_center_text(get_time(Temp_P.timer_count));
			if (vision)(*win).update();
	};
private:
	Win_Train* win;
	Temporary_Data* Temp_D;
	Temp_Param_Win_Train Temp_P;
	bool vision = false;
	char s[7];
	int set_point = 0;
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
		(*win).chang_test_obj1.disable();
		(*win).chang_viz1.disable();
		(*win).patient_controller1.disable();
		(*win).auto_mode1.disable();
		(*win).eye_mode1.disable();
		(*win).focus_n1.disable();
		(*win).focus_f1.disable();
		(*win).position1.disable();
	}

	void change_value_in_point(int8_t sign)
	{
		switch (set_point)
		{
		case 7:
			Temp_P.focus_n += sign*EYE_DIV_VALUE_METRIC;
			(*Temp_D).t_eye.od_n.value = Temp_P.focus_n;
			(*win).focus_n1.strcpy_center_text(Temp_P.focus_n, POINT_AFTER_COMMA);
			break;
		case 8:
			Temp_P.focus_f += sign*EYE_DIV_VALUE_METRIC;
			(*Temp_D).t_eye.od_f.value = Temp_P.focus_f;
			(*win).focus_f1.strcpy_center_text(Temp_P.focus_f, POINT_AFTER_COMMA);
			break;
		case 9:
			Temp_P.position += sign*EYE_DIV_VALUE_METRIC;
			(*win).position1.strcpy_center_text(Temp_P.position, POINT_AFTER_COMMA);
			break;
		default:
			break;
		}
		(*win).update();

	}
	void save()
	{
		if (Temp_P.eye == Temp_P.const_eye_os)
		{
			(*Temp_D).t_eye.od_n.value = Temp_P.focus_n;
			(*Temp_D).t_eye.od_f.value = Temp_P.focus_f;
			(*Temp_D).t_eye.time_spend_os = Temp_P.timer_count;

		}
		else
		{
			(*Temp_D).t_eye.os_n.value = Temp_P.focus_n;
			(*Temp_D).t_eye.os_f.value = Temp_P.focus_f;
			(*Temp_D).t_eye.time_spend_od = Temp_P.timer_count;

		}
	}
	void load()
	{
		if (Temp_P.eye == Temp_P.const_eye_os)
		{
			Temp_P.focus_n = (*Temp_D).t_eye.os_n.value;
			Temp_P.focus_f = (*Temp_D).t_eye.os_f.value;
			Temp_P.timer_count = (*Temp_D).t_eye.time_spend_os;
		}
		else
		{
			Temp_P.focus_n = (*Temp_D).t_eye.od_n.value;
			Temp_P.focus_f = (*Temp_D).t_eye.od_f.value;
			Temp_P.timer_count = (*Temp_D).t_eye.time_spend_od;
		}
	}
};


#endif