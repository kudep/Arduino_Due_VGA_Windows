
#ifndef WIN_OPTINONS_H_INCLUDED
#define WIN_OPTINONS_H_INCLUDED
#include <VGA.h>
#include"VGA_base_windows.h"
#include"keyboard_handler.h"

#define EYE_DIV_VALUE_TIME 0.5
#define EYE_DIV_VALUE_METRIC 0.5
class Win_Option :Win
{
public:
	Win_Option();
	~Win_Option();
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

	//Meas. title
	CntrlSubGroup meas_title;

	//1 string
	CntrlSubGroup choose_m_os0;
	CntrlSubGroup choose_m_os1;

	//2 string
	CntrlSubGroup choose_m_od0;
	CntrlSubGroup choose_m_od1;

	//Train. title
	CntrlSubGroup train_title;

	//3 string
	CntrlSubGroup time_t_os0;
	CntrlSubGroup time_t_os1;

	//4 string
	CntrlSubGroup os_n0;
	CntrlSubGroup os_n1;

	//5 string
	CntrlSubGroup os_f0;
	CntrlSubGroup os_f1;

	//6 string
	CntrlSubGroup time_t_od0;
	CntrlSubGroup time_t_od1;

	//7 string
	CntrlSubGroup od_n0;
	CntrlSubGroup od_n1;

	//8 string
	CntrlSubGroup od_f0;
	CntrlSubGroup od_f1;




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
		//Meas. title
		char str_meas_title[13] = { 200, 199, 204, 197, 208, 197, 205, 200, 197, 0 };//ИЗМЕРЕНИЕ
		meas_title.strcpy_text(str_meas_title);

		//1 string
		char str_choose_m_os0[13] = { 32, 32, 32, 32, 32, 32, 32, 32, 49, 46, 79, 83, 0 };//        1.OS
		choose_m_os0.strcpy_text(str_choose_m_os0);
		choose_m_os1.strcpy_center_text("");


		//2 string
		char str_choose_m_od0[13] = { 32, 32, 32, 32, 32, 32, 32, 32, 50, 46, 79, 68, 0 };//        2.OD
		choose_m_od0.strcpy_text(str_choose_m_od0);
		choose_m_od1.strcpy_center_text("");

		//Train. title
		char str_train_title[13] = { 210, 208, 197, 205, 200, 208, 206, 194, 202, 192, 0 };//ТРЕНИРОВКА
		train_title.strcpy_text(str_train_title);

		//3 string
		char str_time_t_os0[13] = { 32, 32, 51, 46, 194, 240, 229, 236, 255, 32, 79, 83, 0 };//  3.Время OS
		time_t_os0.strcpy_text(str_time_t_os0);
		time_t_os1.strcpy_center_text("0");

		//4 string
		char str_os_n0[13] = { 32, 32, 32, 52, 46, 32, 193, 235, 232, 230, 237, 46, 0 };//   4. Ближн.
		os_n0.strcpy_text(str_os_n0);
		os_n1.strcpy_center_text("0");

		//5 string
		char str_os_f0[13] = { 32, 32, 32, 32, 53, 46, 196, 224, 235, 252, 237, 46, 0 };//    5.Дальн.
		os_f0.strcpy_text(str_os_f0);
		os_f1.strcpy_center_text("0");

		//6 string
		char str_time_t_od0[13] = { 32, 32, 54, 46, 194, 240, 229, 236, 255, 32, 79, 68, 0 };//  6.Время OD
		time_t_od0.strcpy_text(str_time_t_od0);
		time_t_od1.strcpy_center_text("0");

		//7 string
		char str_od_n0[13] = { 32, 32, 32, 55, 46, 32, 193, 235, 232, 230, 237, 46, 0 };//   7. Ближн.
		od_n0.strcpy_text(str_od_n0);
		od_n1.strcpy_center_text("0");

		//8 string
		char str_od_f0[13] = { 32, 32, 32, 32, 56, 46, 196, 224, 235, 252, 237, 46, 0 };//    8.Дальн.
		od_f0.strcpy_text(str_od_f0);
		od_f1.strcpy_center_text("0");



		char str_extend_button_description0[8] = { 207, 238, 236, 238, 249, 252, 0 };//Помощь
		extend_button_description0.strcpy_center_text(str_extend_button_description0);

		char str_extend_button_description1[8] = { 205, 224, 231, 224, 228, 0 };//Назад
		extend_button_description1.strcpy_center_text(str_extend_button_description1);

		char str_extend_button_description2[8] = { 196, 224, 235, 229, 229, 0 };//Далее
		extend_button_description2.strcpy_center_text(str_extend_button_description2);


	}

	CntrlSubGroup* parr[28] =
	{
		&meas_title, &choose_m_os0, &choose_m_os1,
		&choose_m_od0, &choose_m_od1, &train_title,
		&time_t_os0, &time_t_os1, &os_n0, &os_n1,
		&os_f0, &os_f1, &time_t_od0,
		&time_t_od1, &od_n0, &od_n1,
		&od_f0, &od_f1, &extend_button0, &extend_button1,
		&extend_button2, &extend_button3, &extend_button4,
		&extend_button_description0, &extend_button_description1,
		&extend_button_description2, &extend_button_description3,
		&extend_button_description4
	};


};

struct Temp_Param_Win_Option
{
	bool choose_m_os = false;
	bool choose_m_od = false;
	float time_t_os = 0;
	float os_n = 0;
	float os_f = 0;
	float time_t_od = 0;
	float od_n = 0;
	float od_f = 0;

	void reset()
	{
		choose_m_os = false;
		choose_m_od = false;
		time_t_os = 0;
		os_n = 0;
		os_f = 0;
		time_t_od = 0;
		od_n = 0;
		od_f = 0;
	}
	void change_choose_m_os()
	{
		choose_m_os = !choose_m_os;

	}
	const char* get_choose_m_os()
	{
		char _true_str[2] = { 187, 0 };//Флаг
		char _false_str[1] = { 0 };
		strcpy(true_str, _true_str);
		strcpy(false_str, _false_str);
		if (choose_m_os)
			return true_str;
		else
			return false_str;

	}
	void change_choose_m_od()
	{
		choose_m_od = !choose_m_od;

	}
	const char* get_choose_m_od()
	{
		char _true_str[2] = { 187, 0 };//Флаг
		char _false_str[1] = { 0 };
		strcpy(true_str, _true_str);
		strcpy(false_str, _false_str);
		if (choose_m_od)
			return true_str;
		else
			return false_str;

	}
private:
	char true_str[11];
	char false_str[11];
};

class Win_Option_Handler : public Keyboard_Handler
{
public:
	Win_Option_Handler(Temporary_Data* _Temp_D, Data_Manager& _Data_Mngr) :Temp_D(_Temp_D)//, Keyboard_Handler(Data_Mngr)
	{
		Data_Mngr = &_Data_Mngr;
		win = new Win_Option;

		Temp_P.reset();
	};
	~Win_Option_Handler()
	{
		delete win;
	};

	void init()
	{
		Keyboard_Handler::init();

		vision = true;
		(*win).choose_m_os1.strcpy_center_text(Temp_P.get_choose_m_os());
		(*win).choose_m_od1.strcpy_center_text(Temp_P.get_choose_m_od());
		(*win).time_t_os1.strcpy_center_text(Temp_P.time_t_os);
		(*win).os_n1.strcpy_center_text(Temp_P.os_n, POINT_AFTER_COMMA);
		(*win).os_f1.strcpy_center_text(Temp_P.os_f, POINT_AFTER_COMMA);
		(*win).time_t_od1.strcpy_center_text(Temp_P.time_t_od);
		(*win).od_n1.strcpy_center_text(Temp_P.od_n, POINT_AFTER_COMMA);
		(*win).od_f1.strcpy_center_text(Temp_P.od_f, POINT_AFTER_COMMA);
		(*win).refresh();
	}

	void finit()
	{
		Keyboard_Handler::finit();

		vision = false;
	}
	void action_button1()
	{
		disable_buttons();

		Temp_P.change_choose_m_os();
		(*Temp_D).m_eye.os = Temp_P.choose_m_os;

		(*win).choose_m_os1.strcpy_center_text(Temp_P.get_choose_m_os());

		(*win).choose_m_os1.enable();
		(*win).update();

	};

	void action_button2()
	{
		disable_buttons();

		Temp_P.change_choose_m_od();
		(*Temp_D).m_eye.os = Temp_P.choose_m_od;

		(*win).choose_m_od1.strcpy_center_text(Temp_P.get_choose_m_od());

		(*win).choose_m_od1.enable();
		(*win).update();


	};

	void action_button3()
	{
		disable_buttons();
		set_point = 3;
		(*win).time_t_os1.enable();
		(*win).update();
	};

	void action_button4()
	{
		disable_buttons();
		set_point = 4;
		(*win).os_n1.enable();
		(*win).update();
	};

	void action_button5()
	{
		disable_buttons();
		set_point = 5;
		(*win).os_f1.enable();
		(*win).update();
	};

	void action_button6()
	{
		disable_buttons();
		set_point = 6;
		(*win).time_t_od1.enable();
		(*win).update();
	};

	void action_button7()
	{
		disable_buttons();
		set_point = 7;
		(*win).od_n1.enable();
		(*win).update();
	};

	void action_button8()
	{
		disable_buttons();
		set_point = 8;
		(*win).od_f1.enable();
		(*win).update();
	};

	void action_buttonF1()
	{
		set_jump(id_wind_help);
	};

	void action_buttonF2()
	{
		set_jump(id_wind_data);
	};


	void action_buttonF3()
	{
		set_jump(id_wind_oper);
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
private:
	Win_Option* win;
	Temporary_Data* Temp_D;
	Temp_Param_Win_Option Temp_P;
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
		(*win).choose_m_os1.disable();
		(*win).choose_m_od1.disable();
		(*win).time_t_os1.disable();
		(*win).os_n1.disable();
		(*win).os_f1.disable();
		(*win).time_t_od1.disable();
		(*win).od_n1.disable();
		(*win).od_f1.disable();
	}
	void change_value_in_point(int8_t sign)
	{
		switch (set_point)
		{
		case 3:
			Temp_P.time_t_os += sign*EYE_DIV_VALUE_TIME;
			(*Temp_D).t_eye.time_os = Temp_P.time_t_os;
			(*win).time_t_os1.strcpy_center_text(Temp_P.time_t_os, POINT_AFTER_COMMA);
			break;
		case 4:
			Temp_P.os_n += sign*EYE_DIV_VALUE_METRIC;
			(*Temp_D).t_eye.os_n.value = Temp_P.os_n;
			(*win).os_n1.strcpy_center_text(Temp_P.os_n, POINT_AFTER_COMMA);
			break;
		case 5:
			Temp_P.os_f += sign*EYE_DIV_VALUE_METRIC;
			(*Temp_D).t_eye.os_n.value = Temp_P.os_f;
			(*win).os_f1.strcpy_center_text(Temp_P.os_f, POINT_AFTER_COMMA);
			break;
		case 6:
			Temp_P.time_t_od += sign*EYE_DIV_VALUE_TIME;
			(*Temp_D).t_eye.time_od = Temp_P.time_t_od;
			(*win).time_t_od1.strcpy_center_text(Temp_P.time_t_od, POINT_AFTER_COMMA);
			break;
		case 7:
			Temp_P.od_n += sign*EYE_DIV_VALUE_METRIC;
			(*Temp_D).t_eye.od_n.value = Temp_P.od_n;
			(*win).od_n1.strcpy_center_text(Temp_P.od_n, POINT_AFTER_COMMA);
			break;
		case 8:
			Temp_P.od_f += sign*EYE_DIV_VALUE_METRIC;
			(*Temp_D).t_eye.od_n.value = Temp_P.od_f;
			(*win).od_f1.strcpy_center_text(Temp_P.od_f, POINT_AFTER_COMMA);
			break;
		default:
			break;
		}
		(*win).update();

	}

};


#endif