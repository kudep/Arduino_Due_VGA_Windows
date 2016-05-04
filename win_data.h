
#ifndef WIN_DATA_H_INCLUDED
#define WIN_DATA_H_INCLUDED
#include <VGA.h>
#include"VGA_base_windows.h"
#include"keyboard_handler.h"

class Win_Data :Win
{
public:
	Win_Data();
	~Win_Data();
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
	CntrlSubGroup data0;
	CntrlSubGroup data1;

	//2 string
	CntrlSubGroup time0;
	CntrlSubGroup time1;

	//3 string
	CntrlSubGroup surname0;
	CntrlSubGroup surname1;

	//4 string
	CntrlSubGroup name0;
	CntrlSubGroup name1;

	//5 string
	CntrlSubGroup middle_name0;
	CntrlSubGroup middle_name1;

	//6 string
	CntrlSubGroup book_numb0;
	CntrlSubGroup book_numb1;

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
		char str_data0[OFFSET_FOR_INFORMATION_ON_DISPLEY] = { 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 49, 46, 196, 224, 242, 224, 0 };//1.Дата
		data0.strcpy_text(str_data0);
		data1.strcpy_center_text("");
		char str_time0[OFFSET_FOR_INFORMATION_ON_DISPLEY] = { 32, 32, 32, 32, 32, 32, 32, 32, 32, 50, 46, 194, 240, 229, 236, 255, 0 };//2.Время
		time0.strcpy_text(str_time0);
		time1.strcpy_center_text("");


		char str_surname0[OFFSET_FOR_INFORMATION_ON_DISPLEY] = { 32, 32, 32, 32, 32, 32, 32, 51, 46, 212, 224, 236, 232, 235, 232, 255, 0 };//3.Фамилия
		surname0.strcpy_text(str_surname0);
		surname1.strcpy_center_text("");

		char str_name0[OFFSET_FOR_INFORMATION_ON_DISPLEY] = { 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 52, 46, 200, 236, 255, 0 };//4.Имя
		name0.strcpy_text(str_name0);
		name1.strcpy_center_text("");

		char str_middle_name0[OFFSET_FOR_INFORMATION_ON_DISPLEY] = { 32, 32, 32, 32, 32, 32, 52, 46, 206, 242, 247, 229, 241, 242, 226, 238, 0 };//4.Отчество
		middle_name0.strcpy_text(str_middle_name0);
		middle_name1.strcpy_center_text("");

		char str_book_numb0[OFFSET_FOR_INFORMATION_ON_DISPLEY] = { 32, 32, 32, 53, 46, 205, 238, 236, 229, 240, 32, 234, 224, 240, 242, 251, 0 };//5.Номер карты
		book_numb0.strcpy_text(str_book_numb0);
		book_numb1.strcpy_center_text("");


		char str_extend_button_description0[8] = { 207, 238, 236, 238, 249, 252, 0 };//Помощь
		extend_button_description0.strcpy_center_text(str_extend_button_description0);

		char str_extend_button_description1[8] = { 209, 225, 240, 238, 241, 0 };//Сброс
		extend_button_description1.strcpy_center_text(str_extend_button_description1);

		char str_extend_button_description2[8] = { 196, 224, 235, 229, 229, 0 };//Далее
		extend_button_description2.strcpy_center_text(str_extend_button_description2);


	}

	CntrlSubGroup* parr[22] = 
	{ 
		&data0, &data1, &time0, &time1, &surname0,
		&surname1, &name0, &name1, &middle_name0, 
		&middle_name1, &book_numb0, &book_numb1, 
		&extend_button0, &extend_button1, &extend_button2,
		&extend_button3, &extend_button4, &extend_button_description0, 
		&extend_button_description1, &extend_button_description2,
		&extend_button_description3, &extend_button_description4 
	};


};

class Win_Data_Handler : public Keyboard_Handler
{
public:
	Win_Data_Handler(Temporary_Data* _Temp_D, Data_Manager& _Data_Mngr) : Temp_D(_Temp_D)//, Keyboard_Handler(Data_Mngr)
	{

		Data_Mngr = &_Data_Mngr;
		win = new Win_Data;
	};
	~Win_Data_Handler()
	{
		delete win;
	};

	void init()
	{
		Keyboard_Handler::init();

		action_button1();
		(*win).data1.strcpy_center_text((*Temp_D).data);
		(*win).time1.strcpy_center_text((*Temp_D).time);
		(*win).surname1.strcpy_center_text((*Temp_D).surname);
		(*win).name1.strcpy_center_text((*Temp_D).name);
		(*win).middle_name1.strcpy_center_text((*Temp_D).middle_name);
		(*win).book_numb1.strcpy_center_text((*Temp_D).book_numb);
		(*win).refresh();
	}

	void set_word(const char word)
	{
		char _word[2] = { 0, 0 };
		_word[0] = word;
		switch (set_point)
		{
		case 1:
			if (strlen((*Temp_D).data)<DATA_STRING_LENGTH - 1)
				strcat((*Temp_D).data, _word);
			(*win).data1.strcpy_center_text((*Temp_D).data);
			break;
		case 2:
			if (strlen((*Temp_D).time)<DATA_STRING_LENGTH - 1)
				strcat((*Temp_D).time, _word);
			(*win).time1.strcpy_center_text((*Temp_D).time);
			break;
		case 3:
			if (strlen((*Temp_D).surname)<DATA_STRING_LENGTH - 1)
				strcat((*Temp_D).surname, _word);
			(*win).surname1.strcpy_center_text((*Temp_D).surname);
			break;
		case 4:
			if (strlen((*Temp_D).name)<DATA_STRING_LENGTH - 1)
				strcat((*Temp_D).name, _word);
			(*win).name1.strcpy_center_text((*Temp_D).name);
			break;
		case 5:
			if (strlen((*Temp_D).middle_name)<DATA_STRING_LENGTH - 1)
				strcat((*Temp_D).middle_name, _word);
			(*win).middle_name1.strcpy_center_text((*Temp_D).middle_name);
			break;
		case 6:
			if (strlen((*Temp_D).book_numb)<DATA_STRING_LENGTH - 1)
				strcat((*Temp_D).book_numb, _word);
			(*win).book_numb1.strcpy_center_text((*Temp_D).book_numb);
			break;
		default:
			break;
		}
		(*win).update();

	}

	void action_button1()
	{
		disable_buttons();

		set_point = 1;
		(*win).data1.enable();
		(*win).update();

	};

	void action_button2()
	{
		disable_buttons();

		set_point = 2;
		(*win).time1.enable();
		(*win).update();

	};

	void action_button3()
	{
		disable_buttons();

		set_point = 3;
		(*win).surname1.enable();
		(*win).update();

	};

	void action_button4()
	{
		disable_buttons();

		set_point = 4;
		(*win).name1.enable();
		(*win).update();

	};

	void action_button5()
	{
		disable_buttons();

		set_point = 5;
		(*win).middle_name1.enable();
		(*win).update();

	};

	void action_button6()
	{
		disable_buttons();

		set_point = 6;
		(*win).book_numb1.enable();
		(*win).update();

	};

	void action_buttonF1()
	{
		set_jump(id_wind_help);
	};
	void action_buttonF2()
	{
		reset_point();
	};
	void action_buttonF3()
	{
		set_jump(id_wind_option);
	};

private:
	Win_Data* win;
	Temporary_Data* Temp_D;
	int set_point = 1; 

	void reset_point()
	{
		switch (set_point)
		{
		case 1:
			if (strlen((*Temp_D).data)<DATA_STRING_LENGTH - 1)
				strcpy((*Temp_D).data, '\0');
			(*win).data1.strcpy_center_text((*Temp_D).data);
			break;
		case 2:
			if (strlen((*Temp_D).time)<DATA_STRING_LENGTH - 1)
				strcpy((*Temp_D).time, '\0');
			(*win).time1.strcpy_center_text((*Temp_D).time);
			break;
		case 3:
			if (strlen((*Temp_D).surname)<DATA_STRING_LENGTH - 1)
				strcpy((*Temp_D).surname, '\0');
			(*win).surname1.strcpy_center_text((*Temp_D).surname);
			break;
		case 4:
			if (strlen((*Temp_D).name)<DATA_STRING_LENGTH - 1)
				strcpy((*Temp_D).name, '\0');
			(*win).name1.strcpy_center_text((*Temp_D).name);
			break;
		case 5:
			if (strlen((*Temp_D).middle_name)<DATA_STRING_LENGTH - 1)
				strcpy((*Temp_D).middle_name, '\0');
			(*win).middle_name1.strcpy_center_text((*Temp_D).middle_name);
			break;
		case 6:
			if (strlen((*Temp_D).book_numb)<DATA_STRING_LENGTH - 1)
				strcpy((*Temp_D).book_numb, '\0');
			(*win).book_numb1.strcpy_center_text((*Temp_D).book_numb);
			break;
		default:
			break;
		}
		(*win).update();

	}

	void disable_buttons()
	{
		(*win).data1.disable();
		(*win).time1.disable();
		(*win).surname1.disable();
		(*win).name1.disable();
		(*win).middle_name1.disable();
		(*win).book_numb1.disable();
	}

};


#endif