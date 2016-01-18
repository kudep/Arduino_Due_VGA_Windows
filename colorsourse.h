
#ifndef COLORSOURSE_H_INCLUDED
#define COLORSOURSE_H_INCLUDED
#include <VGA.h>
//0b11111111 = 255 = white    0b11110000 = 240 = orange
//0b11100000 = 224 = red      0b10010010 = 146 = grey
//0b00011100 = 28 = green	    0b10000011 = 227 = purple
//0b00000011 = 3 = blue       0b00000000 = 0 = black
enum subgroup_function { information, text, button, standard };
enum states {disable,enable};

typedef uint8_t VGA_INTF_Color;

struct VGA_INTF_Colors
{
	static const VGA_INTF_Color white = 255;
	static const VGA_INTF_Color red=224;
	static const VGA_INTF_Color orange=240;
	static const VGA_INTF_Color grey=146;
	static const VGA_INTF_Color purple=277;
	static const VGA_INTF_Color green=28;
	static const VGA_INTF_Color blue=3;
	static const VGA_INTF_Color black=0;
};


const VGA_INTF_Color standard_subgroup_colors[6] = { VGA_INTF_Colors::black, VGA_INTF_Colors::black, VGA_INTF_Colors::white, VGA_INTF_Colors::red, VGA_INTF_Colors::black, VGA_INTF_Colors::white };
const VGA_INTF_Color standard_subgroup_group_outline_colors[2] = { VGA_INTF_Colors::black, VGA_INTF_Colors::blue };


const VGA_INTF_Color standard_subgroup_information_colors[6] = { VGA_INTF_Colors::grey, VGA_INTF_Colors::green, VGA_INTF_Colors::blue, VGA_INTF_Colors::red, VGA_INTF_Colors::green, VGA_INTF_Colors::blue };
const VGA_INTF_Color standard_subgroup_text_colors[6] = { VGA_INTF_Colors::black, VGA_INTF_Colors::black, VGA_INTF_Colors::white, VGA_INTF_Colors::red, VGA_INTF_Colors::black, VGA_INTF_Colors::white };
const VGA_INTF_Color standard_subgroup_button_colors[6] = { VGA_INTF_Colors::black, VGA_INTF_Colors::white, VGA_INTF_Colors::blue, VGA_INTF_Colors::red, VGA_INTF_Colors::white, VGA_INTF_Colors::blue };

struct Color_Parameters
{
	Color_Parameters() :outline(*(standard_subgroup_colors)), background(*(standard_subgroup_colors + 1)), text(*(standard_subgroup_colors+2)){};
	Color_Parameters(VGA_INTF_Color  color) :outline(color), background(color), text(color){};
	Color_Parameters(VGA_INTF_Color  outline, VGA_INTF_Color background, VGA_INTF_Color text) :outline(outline), background(background), text(text){};
	Color_Parameters(const  VGA_INTF_Color * color) :outline(*(color + 0)), background(*(color + 1)), text(*(color + 2)){};
	VGA_INTF_Color  outline;
	VGA_INTF_Color  background;
	VGA_INTF_Color  text;
};


struct Color_Style
{
	Color_Style() :disable(standard_subgroup_colors + 0), enable(standard_subgroup_colors + 3){};
	Color_Style(Color_Parameters enable, Color_Parameters disable) :enable(enable), disable(disable){};
	Color_Style(VGA_INTF_Color * color) :disable(color), enable(color + 3){};
	Color_Style(subgroup_function fnc)
	{
		switch (fnc)
		{
		case text:
			disable = Color_Parameters(standard_subgroup_text_colors);
			enable = Color_Parameters(standard_subgroup_text_colors + 3);
			break;
		case information:
			disable = Color_Parameters(standard_subgroup_information_colors);
			enable = Color_Parameters(standard_subgroup_information_colors + 3);
			break;
		case button:
			disable = Color_Parameters(standard_subgroup_button_colors);
			enable = Color_Parameters(standard_subgroup_button_colors + 3);
			break;
		default:
			disable = Color_Parameters(standard_subgroup_colors);
			enable = Color_Parameters(standard_subgroup_colors + 3);
		}
	};
	Color_Parameters disable;
	Color_Parameters enable;
};


struct Outline_Color_Style
{
	Outline_Color_Style() :enable(*(standard_subgroup_group_outline_colors)), disable(*(standard_subgroup_group_outline_colors+1)){};
	Outline_Color_Style(VGA_INTF_Color  enable, VGA_INTF_Color disable) :enable(enable), disable(disable){};
	VGA_INTF_Color  enable;
	VGA_INTF_Color  disable;
};


#endif