
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


	//Info about testobject
	CntrlSubGroup test_obj_info0;
	CntrlSubGroup test_obj_info1;

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
	CntrlSubGroup focus_point0;
	CntrlSubGroup focus_point1;

	//8 string
	CntrlSubGroup record_position0;
	CntrlSubGroup record_position1;

	//Recodes count 
	CntrlSubGroup record_count0;
	CntrlSubGroup record_count1;

	//9 string
	CntrlSubGroup remove_record0;
	CntrlSubGroup remove_record1;



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

		//Info about testobject
		char str_test_obj_info0[OFFSET_FOR_INFORMATION_ON_DISPLEY] = { 200, 237, 244, 46, 32, 238, 225, 32, 238, 239, 242, 238, 242, 232, 239, 229, 0 };//Инф. об оптотипе
		test_obj_info0.strcpy_text(str_test_obj_info0);
		test_obj_info1.strcpy_center_text("");
		

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
		char str_focus_point1[OFFSET_FOR_INFORMATION_ON_DISPLEY] = { 32, 55, 46, 209, 236, 229, 237, 46, 32, 227, 240, 224, 237, 232, 246, 243, 0 };//7.Смен. границу
		focus_point0.strcpy_text(str_focus_point1);
		focus_point1.strcpy_center_text("");


		//Recodes count 
		char str_record_count0[OFFSET_FOR_INFORMATION_ON_DISPLEY] = { 32, 32, 32, 194, 241, 229, 227, 238, 32, 231, 224, 239, 232, 241, 229, 233, 0 };//Всего записей
		record_count0.strcpy_text(str_record_count0);
		record_count1.strcpy_center_text("");


		//8 string

		char str_record_position0[OFFSET_FOR_INFORMATION_ON_DISPLEY] = { 56, 46, 199, 224, 239, 232, 241, 46, 32, 239, 238, 231, 232, 246, 232, 254, 0 };//8.Запис. позицию
		record_position0.strcpy_text(str_record_position0);
		record_position1.strcpy_center_text("0");

		//9 string
		char str_remove_record0[OFFSET_FOR_INFORMATION_ON_DISPLEY] = { 32, 32, 57, 46, 211, 228, 224, 235, 46, 32, 231, 224, 239, 232, 241, 252, 0 };//9.Удал. запись
		remove_record0.strcpy_text(str_remove_record0);
		remove_record1.strcpy_center_text("0");
		

		char str_extend_button_description0[8] = { 207, 238, 236, 238, 249, 252, 0 };//Помощь
		extend_button_description0.strcpy_center_text(str_extend_button_description0);

		char str_extend_button_description1[8] = { 205, 224, 231, 224, 228, 0 };//Назад
		extend_button_description1.strcpy_center_text(str_extend_button_description1);

		char str_extend_button_description2[8] = { 196, 224, 235, 229, 229, 0 };//Далее
		extend_button_description2.strcpy_center_text(str_extend_button_description2);
		

	}

	CntrlSubGroup* parr[32] = 
	{ 
		&start_position0, &start_position1, &test_obj_info0,
		&test_obj_info1, &chang_test_obj0, &chang_test_obj1,
		&chang_viz0, &chang_viz1, &patient_controller0, &patient_controller1,
		&auto_mode0, &auto_mode1, &eye_mode0,
		&eye_mode1, &focus_point0, &focus_point1,
		&record_position0, &record_position1,
		&record_count0, &record_count1,
		&remove_record0, &remove_record1, &extend_button0, &extend_button1,
	&extend_button2, &extend_button3, &extend_button4,
	&extend_button_description0, &extend_button_description1,
	&extend_button_description2, &extend_button_description3,
	&extend_button_description4 
	};


};

struct Temp_Param_Win_Oper
{
	float start_position = 0;
	char test_obj_info1[DATA_STRING_LENGTH];
	bool os = false;
	bool od = false;
	bool viz = false;
	bool ptnt_controller = false;
	bool auto_mode = false;
	bool eye = false;
	bool focus_point = false;
	int record_count = 0;
	float record_position = 0;

	void reset()
	{
		char _test_obj_info1[DATA_STRING_LENGTH] = { 200, 237, 244, 238, 240, 236, 46, 32, 238, 225, 32, 238, 239, 242, 238, 242, 232, 239, 229, 0 };//Информ. об оптотипе
		strcpy(test_obj_info1, _test_obj_info1);
		start_position = 0;
		os = false;
		od = false;
		viz = false;
		ptnt_controller = false;
		auto_mode = false;
		eye = false;
		focus_point = false;
		record_count = 0;
		record_position = 0;
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
	void change_focus_point()
	{
		focus_point = !focus_point;

	}
	const char* get_focus_point()
	{
		char _true_str[8] = { 193, 235, 232, 230, 237, 255, 255, 0 };//Ближняя
		char _false_str[8] = { 196, 224, 235, 252, 237, 255, 255, 0 };//Дальняя
		strcpy(true_str, _true_str);
		strcpy(false_str, _false_str);
		if (focus_point)
			return true_str;
		else
			return false_str;

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

		//Иницилизация SD карты
		if ((*Data_Mngr).init())
		{

			Temp_P.os = (*Temp_D).m_eye.os;
			Temp_P.od = (*Temp_D).m_eye.od;
			Temp_P.change_eye();
			vision = true;
			(*win).test_obj_info1.strcpy_center_text(Temp_P.test_obj_info1);
			(*win).chang_viz1.strcpy_center_text(Temp_P.get_viz());
			(*win).patient_controller1.strcpy_center_text(Temp_P.get_ptnt_controller());
			(*win).auto_mode1.strcpy_center_text(Temp_P.get_auto_mode());
			(*win).eye_mode1.strcpy_center_text(Temp_P.get_eye());
			(*win).focus_point1.strcpy_center_text(Temp_P.get_focus_point());
			(*win).record_count1.strcpy_center_text((*((*Temp_D).access_meas_p(Temp_P.eye, Temp_P.focus_point))).seq.getsize());
			(*win).record_position1.strcpy_center_text(Temp_P.record_position, POINT_AFTER_COMMA);
			(*win).remove_record1.strcpy_center_text((*((*Temp_D).access_meas_p(Temp_P.eye, Temp_P.focus_point))).seq.top(), POINT_AFTER_COMMA);

			//Операция определения слайда
			(*Data_Mngr).LCD_Data.flag_pic = false;//Результат определения
			(*Data_Mngr).LCD_Data.slide.numb = 1;//Результат 

			load_pic();

			(*win).refresh();
		}
		else
		{
			set_jump(id_wind_error_init_SD_wind);
		}
	}

	void finit()
	{
		Keyboard_Handler::finit();

		vision = false;
	}
	void action_button1()
	{
		disable_buttons();
		//Операция определения слайда
		(*Data_Mngr).LCD_Data.flag_pic = false;//Результат определения
		(*Data_Mngr).LCD_Data.slide.numb = 1;//Результат определения

		(*win).start_position1.enable();
		(*win).update();

	};

	void action_button2()
	{
		disable_buttons();
		(*win).chang_test_obj1.enable();
		load_pic();
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

		Temp_P.change_eye();

		(*win).eye_mode1.strcpy_center_text(Temp_P.get_eye());
		(*win).remove_record1.strcpy_center_text((*((*Temp_D).access_meas_p(Temp_P.eye, Temp_P.focus_point))).seq.top(), POINT_AFTER_COMMA);
		(*win).record_count1.strcpy_center_text((*((*Temp_D).access_meas_p(Temp_P.eye, Temp_P.focus_point))).seq.getsize());

		(*win).eye_mode1.enable();
		(*win).update();

	};

	void action_button7()
	{
		disable_buttons();

		Temp_P.change_focus_point();

		(*win).focus_point1.strcpy_center_text(Temp_P.get_focus_point());
		(*win).remove_record1.strcpy_center_text((*((*Temp_D).access_meas_p(Temp_P.eye, Temp_P.focus_point))).seq.top(), POINT_AFTER_COMMA);
		(*win).record_count1.strcpy_center_text((*((*Temp_D).access_meas_p(Temp_P.eye, Temp_P.focus_point))).seq.getsize());

		(*win).focus_point1.enable();
		(*win).update();

	};

	void action_button8()
	{
		disable_buttons();
		(*((*Temp_D).access_meas_p(Temp_P.eye, Temp_P.focus_point))).seq.push(Temp_P.record_position);
		(*win).remove_record1.strcpy_center_text((*((*Temp_D).access_meas_p(Temp_P.eye, Temp_P.focus_point))).seq.top(), POINT_AFTER_COMMA);
		(*win).record_position1.enable();

		(*win).record_count1.strcpy_center_text((*((*Temp_D).access_meas_p(Temp_P.eye, Temp_P.focus_point))).seq.getsize());

		(*win).update();
	};

	void action_button9()
	{
		disable_buttons();

		(*((*Temp_D).access_meas_p(Temp_P.eye, Temp_P.focus_point))).seq.pop();
		(*win).remove_record1.strcpy_center_text((*((*Temp_D).access_meas_p(Temp_P.eye, Temp_P.focus_point))).seq.top(), POINT_AFTER_COMMA);
		(*win).remove_record1.enable();

		(*win).record_count1.strcpy_center_text((*((*Temp_D).access_meas_p(Temp_P.eye, Temp_P.focus_point))).seq.getsize());

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
		if ((*Temp_D).t_eye.setup_time_os != 0 || (*Temp_D).t_eye.setup_time_od != 0)
			set_jump(id_wind_train);
		else
			set_jump(id_wind_result);
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
		(*win).chang_test_obj1.disable();
		(*win).chang_viz1.disable();
		(*win).patient_controller1.disable();
		(*win).auto_mode1.disable();
		(*win).eye_mode1.disable();
		(*win).focus_point1.disable();
		(*win).record_position1.disable();
		(*win).remove_record1.disable();
	}
	void load_pic()
	{
		if ((*Data_Mngr).LCD_Data.flag_pic)
		{

		}
		else
		{
			(*Data_Mngr).LCD_Data.slide.VIZ = Temp_P.viz;
			(*Data_Mngr).LCD_Data.slide.load_slide(1);//Цифра ф-ции это IP_product
			(*win).test_obj_info1.strcpy_center_text((*Data_Mngr).LCD_Data.slide.test_obj.name);
		}
	}
};


#endif