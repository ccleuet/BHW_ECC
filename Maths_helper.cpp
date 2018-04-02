#include "stdafx.h"
#include "Maths_helper.h"

Maths_helper::Maths_helper()
{
}

Maths_helper::Maths_helper(unsigned char *p)
{
	set_p(p);
}

unsigned char*  Maths_helper::get_p()
{
	return p;
}


void Maths_helper::set_p(unsigned char *p)
{
	this->p = p;
}


void Maths_helper::addition(unsigned char *out, unsigned char *in1, unsigned char *in2) {
	unsigned int temp = 0;
	for (int i = 0; i < 10; i++) {
		temp = in1[9-i] + in2[9-i] + temp;
		if (temp > 255)
		{
			out[9 - i] = temp-256;
			temp = 1;
		}
		else {
			out[9 - i] = temp;
			temp = 0;
		}
	}
}

void Maths_helper::addition(unsigned char *out, unsigned char *in1, unsigned int n) {
	unsigned char n_hexa[10]= { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 , 0x00, 0x00, 0x00, 0x00 };
	IntToHexa(n_hexa, n);
	unsigned int temp = 0;
	for (int i = 0; i < 10; i++) {
		temp = in1[9 - i] + n_hexa[9 - i] + temp;
		if (temp > 255)
		{
			out[9 - i] = temp - 256;
			temp = 1;
		}
		else {
			out[9 - i] = temp;
			temp = 0;
		}
	}
}

void Maths_helper::soustraction(unsigned char *out, unsigned char *in1, unsigned char *in2) {
	unsigned int temp = 0;
	for (int i = 0; i < 10; i++) {
		temp = in1[9 - i] - in2[9 - i] - temp;
		if (temp < 0)
		{
			out[9 - i] = temp + 16;
			temp = 1;
		}
		else {
			out[9 - i] = temp;
			temp = 0;
		}
	}
}

void Maths_helper::multiplication(unsigned char *out, unsigned char *in1, unsigned char *in2) {

	unsigned char temp[10] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 , 0x00, 0x00, 0x00, 0x00 };
	unsigned char result[10] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 , 0x00, 0x00, 0x00, 0x00 };

	multiplication(out, in1, in2[9]);
	for (int i = 1; i < 10; i++) {
	  multiplication(temp, in1, in2[9-i]);
	  Shift_left(temp, i);
	  addition(out, out, temp);
	  Init(temp);
	}
}

void Maths_helper::multiplication(unsigned char *out, unsigned char *in, unsigned int n) {
	unsigned char result[10];
	for (int i = 0; i < n; i++) {
		unsigned int temp = 0;
		for (int i = 0; i < 10; i++) {
			temp = in[9 - i]*n + temp;
			if (temp > 255)
			{
				out[9 - i] = temp%256;
				temp = (int)temp/256;
			}
			else {
				out[9 - i] = temp;
				temp = 0;
			}
		}
	}
}

void Maths_helper::IntToHexa(unsigned char *out, unsigned int n)
{
	unsigned int i = 0;
	unsigned int temp = n;
	while (i < 10) {
		if (temp > 255)
		{
			out[9 - i] = temp % 256;
			temp = (int)temp / 256;
		}
		else {
			out[9 - i] = temp;
			temp = 0;
			break;
		}
		i = i + 1;
	}
}

bool Maths_helper::Is_Greater(unsigned char *in1, unsigned char *in2) {
	bool result = false;
	for (int i = 0; i < 10; i++) {
		if (in1[i] > in2[i]) {
			return true;
		}
		else if (in1[i] < in2[i]) {
			return false;
		}
	}
}

void Maths_helper::Shift_left(unsigned char *in, unsigned int n)
{
	unsigned char temp[20] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 , 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 , 0x00, 0x00, 0x00, 0x00 };

	for (int i = 0; i+n < 10; i++) {
		temp[i] = in[i+n];
	}
	in[0] = temp[0];
	in[1] = temp[1];
	in[2] = temp[2];
	in[3] = temp[3];
	in[4] = temp[4];
	in[5] = temp[5];
	in[6] = temp[6];
	in[7] = temp[7];
	in[8] = temp[8];
	in[9] = temp[9];
}

void Maths_helper::Init(unsigned char *in)
{
	for (int i = 0; i <10; i++) {
		in[i] = 0x00;
	}
}