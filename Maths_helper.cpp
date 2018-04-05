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

	unsigned char out_20[20]; init(out_20, 20);
	unsigned char in1_20[20]; tenTo_20hexa(in1_20, in1);
	unsigned char in2_20[20]; tenTo_20hexa(in2_20, in2);

	for (int i = 0; i < 20; i++) {
		temp = in1_20[(19 - i)] + in2_20[(19 - i)] + temp;
		if (temp > 255)
		{
			out_20[19 - i] = temp - 256;
			temp = 1;
		}
		else {
			out_20[19 - i] = temp;
			temp = 0;
		}
	}
	modulo_20(out_20);
	twentyTo_10hexa(out, out_20);
}

void Maths_helper::addition(unsigned char *out, unsigned char *in1, unsigned int n) {
	unsigned char n_hexa[10] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 , 0x00, 0x00, 0x00, 0x00 };
	intToHexa(n_hexa, n);
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

void Maths_helper::soustraction_20(unsigned char *out, unsigned char *in1, unsigned char *in2) {
	unsigned int temp = 0x00;
	for (int i = 0; i < 20; i++) {
		unsigned int result = in1[19 - i] - (in2[19 - i] + temp);
		if (in1[19 - i] >= (in2[19 - i] + temp)) {
			out[19 - i] = result;
			temp = 0x00;
		}
		else {
			out[19 - i] = result;
			temp = 0x01;
		}
	}
}

void Maths_helper::soustraction_10(unsigned char *out, unsigned char *in1, unsigned char *in2) {
	unsigned int temp = 0x00;
	for (int i = 0; i < 10; i++) {
		unsigned int result = in1[9 - i] - (in2[9 - i] + temp);
		if (in1[9 - i] >= (in2[9 - i] + temp)) {
			out[9 - i] = result;
			temp = 0x00;
		}
		else {
			out[9 - i] = result;
			temp = 0x01;
		}
	}
}
void Maths_helper::soustraction_10(unsigned char *out, unsigned char *in1, unsigned int n) {
	unsigned int temp = 0x00; 
	unsigned char n_hexa[10]; init(n_hexa, 10);
	intToHexa(n_hexa, n);
	for (int i = 0; i < 10; i++) {
		unsigned int result = in1[9 - i] - (n_hexa[9 - i] + temp);
		if (in1[9 - i] >= (n_hexa[9 - i] + temp)) {
			out[9 - i] = result;
			temp = 0x00;
		}
		else {
			out[9 - i] = result;
			temp = 0x01;
		}
	}
}

void Maths_helper::multiplication(unsigned char *out, unsigned char *in1, unsigned char *in2) {

	unsigned char temp[10] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 , 0x00, 0x00, 0x00, 0x00 };

	multiplication(out, in1, in2[9]);
	for (int i = 1; i < 10; i++) {
		multiplication(temp, in1, in2[9 - i]);
		shift_left(temp, i);
		addition(out, out, temp);
		init(temp, 10);
	}
}

void Maths_helper::multiplication(unsigned char *out, unsigned char *in, int n) {

	unsigned char out_20[20]; init(out_20, 20);
	unsigned char in_20[20]; tenTo_20hexa(in_20, in);

	for (int i = 0; i < n; i++) {
		unsigned int temp = 0;
		for (int j = 0; j < 20; j++) {
			temp = in_20[19 - j] * n + temp;
			if (temp > 255)
			{
				out_20[19 - j] = temp % 256;
				temp = (int)temp / 256;
			}
			else {
				out_20[19 - j] = temp;
				temp = 0;
			}
		}
	}
	modulo_20(out_20);
	twentyTo_10hexa(out, out_20);
}

void Maths_helper::intToHexa(unsigned char *out, unsigned int n)
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

bool Maths_helper::is_Greater(unsigned char *in1, unsigned char *in2, int n) {
	for (int i = 0; i < n; i++) {
		if (in1[i] > in2[i]) {
			return true;
		}
		else if (in1[i] < in2[i]) {
			return false;
		}
	}
	return false;
}

void Maths_helper::shift_left(unsigned char *in, unsigned int n)
{
	unsigned char temp[20] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 , 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 , 0x00, 0x00, 0x00, 0x00 };

	for (int i = 0; i + n < 10; i++) {
		temp[i] = in[i + n];
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

void Maths_helper::init(unsigned char *in, int n)
{
	for (int i = 0; i < n; i++) {
		in[i] = 0x00;
	}
}


void Maths_helper::tenTo_20hexa(unsigned char *out, unsigned char *in) {
	init(out, 20);
	for (int i = 0; i < 10; i++) {
		out[i + 10] = in[i];
	}
}

void Maths_helper::twentyTo_10hexa(unsigned char *out, unsigned char *in) {
	init(out, 10);
	for (int i = 0; i < 10; i++) {
		out[i] = in[i + 10];
	}
}

void Maths_helper::modulo_10(unsigned char *in) {

	unsigned char result[10]; init(result, 10);

	for (int i = 0; i < 10; i++) {
		result[i] = in[i];
	}

	while (is_Greater(result, this->get_p(), 10)) {
		soustraction_10(result, result, this->get_p());
	}
	for (int i = 0; i < 10; i++) {
		in[i] = result[i];
	}
}

void Maths_helper::modulo_20(unsigned char *in) {

	unsigned char result[20] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 , 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 , 0x00, 0x00, 0x00, 0x00 };
	unsigned char p_20[20]; tenTo_20hexa(p_20, this->get_p());

	for (int i = 0; i < 20; i++) {
		result[i] = in[i];
	}

	while (is_Greater(result, p_20, 20)) {
		soustraction_20(result, result, p_20);
	}
	for (int i = 0; i < 20; i++) {
		in[i] = result[i];
	}
}


bool Maths_helper::isEqual(unsigned char *in1, unsigned char *in2) {
	for (int i = 0; i < 10; i++) {
		if (in1[i] != in2[i]) {
			return false;
		}
	}
	return true;
}

bool Maths_helper::isNull(unsigned char *in) {
	for (int i = 0; i < 10; i++) {
		if (in[i] != 0x00) {
			return false;
		}
	}
	return true;
}

void Maths_helper::division(unsigned char *out, unsigned char *in, int n) {

	unsigned char n_hexa[10]; init(n_hexa, 10);
	intToHexa(n_hexa, n);

	unsigned char temp_01[10] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 , 0x00, 0x00, 0x00, 0x01 };

	unsigned char result[10]; init(result, 10);
	unsigned char r[10]; init(r, 10);

	for (int i = 0; i < 10; i++) {
		result[i] = in[i];
	}

	while (is_Greater(result, n_hexa,10)) {
		soustraction_10(result, result, n_hexa);
		addition(r, r, temp_01);
	}

	for (int i = 0; i < 10; i++) {
		out[i] = r[i];
	}
}