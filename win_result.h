
#ifndef WIN_RESULT_H_INCLUDED
#define WIN_RESULT_H_INCLUDED
#include <VGA.h>
#include"VGA_base_windows.h"
#include"keyboard_handler.h"
class Win_Result :Win
{
public:
	Win_Result();
	~Win_Result();
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
	CntrlSubGroup os0;
	CntrlSubGroup os1;
	CntrlSubGroup os2;
	CntrlSubGroup os3;

	//2 string
	CntrlSubGroup os_n0;
	CntrlSubGroup os_n1;
	CntrlSubGroup os_n2;
	CntrlSubGroup os_n3;

	//3 string
	CntrlSubGroup os_f0;
	CntrlSubGroup os_f1;
	CntrlSubGroup os_f2;
	CntrlSubGroup os_f3;

	//4 string
	CntrlSubGroup od0;
	CntrlSubGroup od1;
	CntrlSubGroup od2;
	CntrlSubGroup od3;

	//5 string
	CntrlSubGroup od_n0;
	CntrlSubGroup od_n1;
	CntrlSubGroup od_n2;
	CntrlSubGroup od_n3;

	//6 string
	CntrlSubGroup od_f0;
	CntrlSubGroup od_f1;
	CntrlSubGroup od_f2;
	CntrlSubGroup od_f3;

	//8 string
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

		char str_os0[] = "OS";//OS
		os0.strcpy_text(str_os0);
		char str_o1[8] = { 209, 240, 229, 228, 237, 229, 229, 0 };//Среднее
		os1.strcpy_text(str_o1);
		char str_o2[8] = { 207, 238, 227, 240, 229, 248, 46, 0 };//Погреш.
		os2.strcpy_text(str_o2);
		char str_o3[8] = { 202, 238, 235, 45, 226, 238, 0 };//Кол-во
		os3.strcpy_text(str_o3);

		char str_n0[8] = { 193, 235, 232, 230, 237, 46, 0 };//Ближн.
		os_n0.strcpy_text(str_n0);

		char str_f0[8] = { 196, 224, 235, 252, 237, 46, 0 };//Дальн.
		os_f0.strcpy_text(str_f0);


		char str_od0[] = "OD";//OD
		od0.strcpy_text(str_od0);

		od1.strcpy_text(str_o1);
		od2.strcpy_text(str_o2);
		od3.strcpy_text(str_o3);

		od_n0.strcpy_text(str_n0);

		od_f0.strcpy_text(str_f0);

		//6 string
		char str_timer0[13] = { 194, 240, 229, 236, 255, 0 };//Время
		timer0.strcpy_text(str_timer0);

		char str_extend_button_description0[8] = { 207, 238, 236, 238, 249, 252, 0 };//Помощь
		extend_button_description0.strcpy_center_text(str_extend_button_description0);

		char str_extend_button_description1[8] = { 205, 224, 231, 224, 228, 0 };//Назад
		extend_button_description1.strcpy_center_text(str_extend_button_description1);

		char str_extend_button_description2[8] = { 209, 238, 245, 240, 224, 237, 46, 0 };//Сохран.
		extend_button_description2.strcpy_center_text(str_extend_button_description2);


	}

	CntrlSubGroup* parr[36] =
	{
		&os0, &os1, &os2, &os3,
		&os_n0, &os_n1, &os_n2, &os_n3,
		&os_f0, &os_f1, &os_f2, &os_f3,
		&od0, &od1, &od2, &od3,
		&od_n0, &od_n1, &od_n2, &od_n3,
		&od_f0, &od_f1, &od_f2, &od_f3,
		&timer0, &timer1,
		&extend_button0, &extend_button1, 
		&extend_button2,&extend_button3, 
		&extend_button4, 
		&extend_button_description0,
		&extend_button_description1, 
		&extend_button_description2,
		&extend_button_description3, 
		&extend_button_description4
	};


};

class Win_Result_Handler : public Keyboard_Handler
{
public:
	Win_Result_Handler(Temporary_Data* _Temp_D, Data_Manager& _Data_Mngr) : Temp_D(_Temp_D)//, Keyboard_Handler(Data_Mngr)
	{

		Data_Mngr = &_Data_Mngr;
		win = new Win_Result;
	};
	~Win_Result_Handler()
	{
		delete win;
	};

	void init()
	{
		Keyboard_Handler::init();

		(*win).os_n1.strcpy_center_text((*Temp_D).m_eye.os_n.seq.average(), POINT_AFTER_COMMA);
		(*win).os_n2.strcpy_center_text((*Temp_D).m_eye.os_n.seq.error(), POINT_AFTER_COMMA);
		(*win).os_n3.strcpy_center_text((*Temp_D).m_eye.os_n.seq.getsize());

		(*win).os_f1.strcpy_center_text((*Temp_D).m_eye.os_f.seq.average(), POINT_AFTER_COMMA);
		(*win).os_f2.strcpy_center_text((*Temp_D).m_eye.os_f.seq.error(), POINT_AFTER_COMMA);
		(*win).os_f3.strcpy_center_text((*Temp_D).m_eye.os_f.seq.getsize());


		(*win).od_n1.strcpy_center_text((*Temp_D).m_eye.od_n.seq.average(), POINT_AFTER_COMMA);
		(*win).od_n2.strcpy_center_text((*Temp_D).m_eye.od_n.seq.error(), POINT_AFTER_COMMA);
		(*win).od_n3.strcpy_center_text((*Temp_D).m_eye.od_n.seq.getsize());

		(*win).od_f1.strcpy_center_text((*Temp_D).m_eye.od_f.seq.average(), POINT_AFTER_COMMA);
		(*win).od_f2.strcpy_center_text((*Temp_D).m_eye.od_f.seq.error(), POINT_AFTER_COMMA);
		(*win).od_f3.strcpy_center_text((*Temp_D).m_eye.od_f.seq.getsize());
		(*win).timer1.strcpy_center_text(get_time((*Temp_D).t_eye.time));

		(*win).refresh();
	}


	void action_buttonF1()
	{
		set_jump(id_wind_help);
	};
	void action_buttonF2()
	{
		set_jump(id_wind_train);
	};
	void action_buttonF3()
	{
		(*Data_Mngr).save_result();
		set_jump(id_wind_end);
	};

private:
	Win_Result* win;
	Temporary_Data* Temp_D;


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
};


#endif