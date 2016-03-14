#ifndef DATABASE_STRUCTURE_H_INCLUDED
#define DATABASE_STRUCTURE_H_INCLUDED

#include "stack.h"

#define DATA_STRING_LENGTH 24

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
	float value=0;
	float post_value = 0;
	void reset()
	{
		value = 0;
		post_value = 0;
	}
};

struct	Eye_Train
{
	bool od = false;
	Eye_Train_Parameters od_n;//ближнии параметры глаза
	Eye_Train_Parameters od_f;//дальнии параметры глаза
	bool os = false;
	Eye_Train_Parameters os_n;//ближнии параметры глаза
	Eye_Train_Parameters os_f;//дальнии параметры глаза
	int time = 0;
	void reset()
	{
		od = false;
		od_n.reset();
		od_f.reset();
		os = false;
		os_n.reset();
		os_f.reset();
		time = 0;
	}
};

struct	Temporary_Data
{
	char data_time[DATA_STRING_LENGTH];
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
		data_time[0] = 0;
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
		if (eye)
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