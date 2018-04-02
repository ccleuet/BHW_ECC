#include "stdafx.h"
#include "Maths_helper.h"

Maths_helper::Maths_helper()
{
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

//void Maths_helper::addition(unsigned char *out, unsigned char *in1, unsigned int n) {
//	unsigned int temp = 0;
//	for (int i = 0; i < 10; i++) {
//		temp = in1[9 - i] + in2[9 - i] + temp;
//		if (temp > 255)
//		{
//			out[9 - i] = temp - 256;
//			temp = 1;
//		}
//		else {
//			out[9 - i] = temp;
//			temp = 0;
//		}
//	}
//}

//void Maths_helper::multiplication(unsigned char *out, unsigned char *in1, unsigned char *in2) {
//	unsigned char temp_double[10] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 , 0x00, 0x00, 0x00, 0x00 };
//	unsigned char temp_add[10] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 , 0x00, 0x00, 0x00, 0x00 };
//	for (int i = 0; i < 10; i++) {
//		multiplication(temp_double, in1, 2);
//		addition(temp_add, temp_double, in2[9 - i]);
//		if (temp > 255)
//		{
//			out[9 - i] = temp % 256;
//			temp = (int)temp / 256;
//		}
//		else {
//			out[9 - i] = temp;
//			temp = 0;
//		}
//	}
//}

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