#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#define NULL 0
#include <Arduino.h>

struct Stack_Point{
	float value;
	Stack_Point* prev;
};

class Stack{
public:
	Stack()
	{
		size = 0;
		a = new Stack_Point;
		a->prev = NULL;
		push(0);
	}
	int getsize()
	{
		return size-1;
	}

	float top()
	{
		if (size != 0)
			return a->value;
		else return 0;
	}
	void pop()
	{
		if (size > 0)
		{
			Stack_Point *temp = a;
			a = a->prev;
			delete temp;
			size--;
		}
	}
	void push(float n)
	{
		if (size != 0)
		{
			Stack_Point *temp = a;
			a = new Stack_Point;
			a->value = n;
			a->prev = temp;
			size++;
		}
		else
		{
			a->value = n;
			size++;
		}
	}
	void drain()
	{
		for (int i = getsize(); i > 0; i--)
			pop();
	}
	float sum()
	{
		float _sum = 0;
		Stack_Point *_a = a;
		for (int i = getsize(); i > 0; i--)
		{
			_sum += _a->value;
			_a = _a->prev;
		}
		return _sum;
	}
	float average()
	{
		if (getsize()> 0)
			return sum() / getsize();
		else
			return 0;
	}
	float error()
	{
		float _error = 0;
		float _average = average();
		Stack_Point *_a = a;
		for (int i = getsize(); i > 0; i--)
		{
			if (_a->value>_average)
				_error += _a->value - _average;
			else
				_error += _average - _a->value;
			_a = _a->prev;
		}

		if (getsize() > 0)
			return _error / getsize();
		else
			return 0;
	}
private:
	Stack_Point *a;
	int size;

};
#endif