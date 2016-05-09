#ifndef DATABASE_STRUCTURE_H_INCLUDED
#define DATABASE_STRUCTURE_H_INCLUDED

#include "stack.h"

#define DATA_STRING_LENGTH 20

struct	Eye_Meas_Parameters
{
	Stack seq;
	char viz[3];
	void reset()
	{
		seq.drain();
		viz[0] = 0;
	}

};

struct	Eye_Meas
{
	bool od=false;
	Eye_Meas_Parameters od_n;//ближнии параметры глаза
	Eye_Meas_Parameters od_f;//дальнии параметры глаза
	bool os = false;
	Eye_Meas_Parameters os_n;//ближнии параметры глаза
	Eye_Meas_Parameters os_f;//дальнии параметры глаза
	void reset()
	{
		od = false;
		od_n.reset();
		od_f.reset();
		os = false;
		os_n.reset();
		os_f.reset();
	}
};


struct	Eye_Train_Parameters
{
	float setup_value = 0;
	float value = 0;
	Stack seq;
	char viz[3];
	void reset()
	{
		seq.drain();
		viz[0] = 0;
	}
};

struct	Eye_Train
{
	int setup_time_od = 0;
	int time_spend_od = 0;
	Eye_Train_Parameters od_n;//ближнии параметры глаза
	Eye_Train_Parameters od_f;//дальнии параметры глаза
	int setup_time_os = 0;
	int time_spend_os = 0;
	Eye_Train_Parameters os_n;//ближнии параметры глаза
	Eye_Train_Parameters os_f;//дальнии параметры глаза
	int time = 0;
	void reset()
	{
		setup_time_od = 0;
		time_spend_od = 0;
		od_n.reset();
		od_f.reset();
		setup_time_os = 0;
		time_spend_os = 0;
		os_n.reset();
		os_f.reset();
		time = 0;
	}
};

struct	Temporary_Data
{
	char data[DATA_STRING_LENGTH];
	char time[DATA_STRING_LENGTH];
	char surname[DATA_STRING_LENGTH];
	char name[DATA_STRING_LENGTH];
	char middle_name[DATA_STRING_LENGTH];
	char book_numb[DATA_STRING_LENGTH];
	bool measurement = false;
	Eye_Meas m_eye;
	bool training = false;
	Eye_Train t_eye;
	void reset()
	{
		data[0] = 0;
		time[0] = 0;
		surname[0] = 0;
		name[0] = 0;
		middle_name[0] = 0;
		book_numb[0] = 0; 
		measurement = false;
		m_eye.reset();
		training = false;
		t_eye.reset();
	}
	Temporary_Data()
	{
		reset();
	}
	Eye_Meas_Parameters* access_meas_p(bool eye, bool focus)
	{

		if (eye&&m_eye.os&&m_eye.od)
		{
			if (focus)
			{
				return &(m_eye.os_n);
			}
			else
			{
				return &(m_eye.os_f);
			}
		}
		else
		{
			if (focus)
			{
				return &(m_eye.od_n);
			}
			else
			{
				return &(m_eye.od_f);
			}
		}
	}
};

#endif