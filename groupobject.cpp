#include"groupobject.h"

Group_Object::Group_Object() :mode(unsetup){};
Group_Object::~Group_Object()
{
	if (style_arr != NULL)
	{
		delete[]style_arr;
		delete[]proproportion_arr;
		delete[]sg_state_arr;
		delete[]sg_modification_arr;
		delete[]sub_group_arr;
	}
}

void Group_Object::setup()
{
	if (mode != unsetup)
	{
		outline_state = false;
		outline_style = Outline_Color_Style();
		style_arr = new Color_Style[subgroup_count];
		proproportion_arr = new float[subgroup_count];

		sg_state_arr = new IntrfSubGroup_State[subgroup_count];
		sg_modification_arr = new Modification[subgroup_count];

		sub_group_arr = new IntrfSubGroup_Pointers[subgroup_count];

		for (size_t i = 0; i < subgroup_count; i++)
		{
			switch (mode)
			{
			case Group_Object::default_mode:
				style_arr[i] = Color_Style(standard);
				break;
			case Group_Object::default_style:
				style_arr[i] = _style;
				break;
			case Group_Object::extendet_style:
				style_arr[i] = _style_arr[i];
				break;
			default:
				break;
			}
			if (_proproportion_arr == NULL) proproportion_arr[i] = 1.0 / subgroup_count;
			else proproportion_arr[i] = _proproportion_arr[i];
			sg_state_arr[i] = IntrfSubGroup_State();
			sg_modification_arr[i] = false;

			sub_group_arr[i] = IntrfSubGroup_Pointers(&sg_state_arr[i], return_text(i), &sg_modification_arr[i]);
		}
		group = IntrfGroup(IntrfGroup_Init_Parameters(metric_group, &outline_state, outline_style, IntrfGroup_to_Subgroup_Init_Parameters(subgroup_count, proproportion_arr, style_arr, sub_group_arr)));
		mode = setup_mode;
	}
}
void Group_Object::update()
{
	group.update();
}
void Group_Object::refresh()
{
	group.refresh();
}
int Group_Object::strlen_text(int num)
{
	switch (num)
	{
	case 0:
		return strlen(sg_text_arr_0);
		break;
	case 1:
		return strlen(sg_text_arr_1);
		break;
	case 2:
		return strlen(sg_text_arr_2);
		break;
	case 3:
		return strlen(sg_text_arr_3);
		break;
	case 4:
		return strlen(sg_text_arr_4);
		break;
	case 5:
		return strlen(sg_text_arr_5);
		break;
	case 6:
		return strlen(sg_text_arr_6);
		break;
	case 7:
		return strlen(sg_text_arr_7);
		break;
	case 8:
		return strlen(sg_text_arr_8);
		break;
	case 9:
		return strlen(sg_text_arr_9);
		break;
	default:
		break;
	}
}
const char* Group_Object::return_text(int num)
{
	switch (num)
	{
	case 0:
		return sg_text_arr_0;
		break;
	case 1:
		return sg_text_arr_1;
		break;
	case 2:
		return sg_text_arr_2;
		break;
	case 3:
		return sg_text_arr_3;
		break;
	case 4:
		return sg_text_arr_4;
		break;
	case 5:
		return sg_text_arr_5;
		break;
	case 6:
		return sg_text_arr_6;
		break;
	case 7:
		return sg_text_arr_7;
		break;
	case 8:
		return sg_text_arr_8;
		break;
	case 9:
		return sg_text_arr_9;
		break;
	default:
		break;
	}
}
void Group_Object::strcpy_text(int num, const char * text)
{
	if (mode != setup_mode) return;
	if (metric_group.height*group.get_width(num) > strlen(text))
	{
		sg_modification_arr[num] = true;
		switch (num)
		{
		case 0:
			strcpy(sg_text_arr_0, text);
			break;
		case 1:
			strcpy(sg_text_arr_1, text);
			break;
		case 2:
			strcpy(sg_text_arr_2, text);
			break;
		case 3:
			strcpy(sg_text_arr_3, text);
			break;
		case 4:
			strcpy(sg_text_arr_4, text);
			break;
		case 5:
			strcpy(sg_text_arr_5, text);
			break;
		case 6:
			strcpy(sg_text_arr_6, text);
			break;
		case 7:
			strcpy(sg_text_arr_7, text);
			break;
		case 8:
			strcpy(sg_text_arr_8, text);
			break;
		case 9:
			strcpy(sg_text_arr_9, text);
			break;
		default:
			break;
		}
	}
}
void Group_Object::strcpy_text(int num, int n_text)
{
	char text[string_length];
	itoa(n_text, text);
	if (mode != setup_mode) return;
	if (metric_group.height*group.get_width(num) > strlen(text))
	{
		sg_modification_arr[num] = true;
		switch (num)
		{
		case 0:
			strcpy(sg_text_arr_0, text);
			break;
		case 1:
			strcpy(sg_text_arr_1, text);
			break;
		case 2:
			strcpy(sg_text_arr_2, text);
			break;
		case 3:
			strcpy(sg_text_arr_3, text);
			break;
		case 4:
			strcpy(sg_text_arr_4, text);
			break;
		case 5:
			strcpy(sg_text_arr_5, text);
			break;
		case 6:
			strcpy(sg_text_arr_6, text);
			break;
		case 7:
			strcpy(sg_text_arr_7, text);
			break;
		case 8:
			strcpy(sg_text_arr_8, text);
			break;
		case 9:
			strcpy(sg_text_arr_9, text);
			break;
		default:
			break;
		}
	}
}
void Group_Object::enable()
{
	outline_state = true;
}
void Group_Object::disable()
{
	outline_state = false;
}
void Group_Object::state_switch()
{
	outline_state = !outline_state;
}
void Group_Object::enable_text(int num)
{
	if (mode != setup_mode) return;
	sg_modification_arr[num] = true;
	sg_state_arr[num].enable();
}
void Group_Object::disable_text(int num)
{
	if (mode != setup_mode) return;
	sg_modification_arr[num] = true;
	sg_state_arr[num].disable();
}
void Group_Object::state_switch_text(int num)
{
	if (mode != setup_mode) return;
	sg_modification_arr[num] = true;
	sg_state_arr[num].reverse();
}
void Group_Object::itoa(int n, char s[])
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
void Group_Object::reverse(char s[])
{
	int i, j;
	char c;

	for (i = 0, j = strlen(s) - 1; i<j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}