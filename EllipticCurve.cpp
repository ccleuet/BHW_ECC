#include "stdafx.h"
#include "EllipticCurve.h"
#include "Maths_helper.h"
#include "limits.h"

EllipticCurve::EllipticCurve()
{
}

EllipticCurve::~EllipticCurve()
{
}

EllipticCurve::EllipticCurve(unsigned char *p, unsigned char *a, unsigned char *b) {
	set_p(p);
	set_a(a);
	set_b(b);
}

unsigned char* EllipticCurve::get_a()
{
	return a;
}

unsigned char*  EllipticCurve::get_b()
{
	return b;
}

unsigned char*  EllipticCurve::get_p()
{
	return p;
}


void EllipticCurve::set_p(unsigned char *p)
{
	this->p = p;
}

void EllipticCurve::set_a(unsigned char *a)
{
	this->a = a;
}

void EllipticCurve::set_b(unsigned char *b)
{
	this->b = b;
}

void EllipticCurve::equation(unsigned char *left, unsigned char *right, unsigned char *x, unsigned char *y) {

	Maths_helper help = Maths_helper(p);

    //y^2
	help.multiplication(right, y, y);
	help.modulo_10(right);

	//x^3 + a * x + b;
	unsigned char x_2[10]; help.init(x_2, 10);
	help.multiplication(x_2, x, x);

	unsigned char x_3[10]; help.init(x_3, 10);
	help.multiplication(x_3, x_2, x);

	unsigned char a_x[10]; help.init(a_x, 10);
	help.multiplication(a_x, x, a);

	unsigned char a_x_b[10]; help.init(a_x_b, 10);
	help.addition(a_x_b, a_x, b);
	help.addition(left, a_x_b, x_3);

	//help.modulo_10(left);
}

bool EllipticCurve::check_point(Point point) {

	Maths_helper help = Maths_helper();

	unsigned char *xp = point.get_x();
	unsigned char *yp = point.get_y();

	unsigned char x[10]; help.init(x, 10);
	unsigned char y[10]; help.init(y, 10);

	for (int i = 0; i < 10; i++) {
		x[i] = xp[i];
		y[i] = yp[i];
	}

	unsigned char left[10] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 , 0x00, 0x00, 0x00, 0x00 };
	unsigned char right[10] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 , 0x00, 0x00, 0x00, 0x00 };
	equation(left, right, x, y);

	return help.isEqual(left, right);
}

Point EllipticCurve::double_point(Point point) {

	Maths_helper help = Maths_helper(p);

	unsigned char *xp = point.get_x();
	unsigned char *yp = point.get_y();
	unsigned char *zp = point.get_z();

	unsigned char temp_1[10]; help.init(temp_1, 10);
	unsigned char temp_2[10]; help.init(temp_2, 10);
	unsigned char temp_3[10]; help.init(temp_3, 10);

	unsigned char temp_4[10]; help.init(temp_4, 10);
	unsigned char temp_5[10]; help.init(temp_5, 10);

	unsigned char temp[10]; help.init(temp, 10);

	unsigned char temp_00[10]; help.init(temp_00, 10);
	//1-2-3
	for (int i = 0; i < 10; i++) {
		temp_1[i] = xp[i];
		temp_2[i] = yp[i];
		temp_3[i] = zp[i];
	}
	//4
	if (help.isNull(temp_2) || help.isNull(temp_3)) {
		help.init(temp_1, 10); help.init(temp_2, 10); help.init(temp_3, 10);
		temp_1[9] = 1; temp_2[9] = 1;
		return Point(temp_1, temp_2, temp_3);
	}

	unsigned char p_min_3[10]; help.init(p_min_3, 10);
	help.soustraction_10(p_min_3, p, 3);

	//5
	if (help.isEqual(a, p_min_3)) {
		help.multiplication(temp_4, temp_3, temp_3);
		if (help.is_Greater(temp_1, temp_4, 10)) {
			help.soustraction_10(temp_5, temp_1, temp_4);
		}
		else {
			help.soustraction_10(temp_5, temp_1, temp_4);
			help.soustraction_10(temp_5, p, temp_5);
		}
		help.addition(temp_4, temp_1, temp_4);
		help.multiplication(temp_5, temp_4, temp_5);
		help.multiplication(temp_4, temp_5, 3);
	}
	else {
		help.addition(temp_4, temp_00, a);
		help.multiplication(temp_5, temp_3, temp_3);
		help.multiplication(temp_5, temp_5, temp_5);
		help.multiplication(temp_5, temp_4, temp_5);
		help.multiplication(temp_4, temp_1, temp_1);
		help.multiplication(temp_4, temp_4, 3);
		help.addition(temp_4, temp_4, temp_5);
	}
	//6
	help.multiplication(temp_3, temp_2, temp_3);
	//7
	help.multiplication(temp_3, temp_3, 2);
	//8
	help.multiplication(temp_2, temp_2, temp_2);
	//9	
	help.multiplication(temp_5, temp_1, temp_2);
	//10
	help.multiplication(temp_5, temp_4, temp_5);
	//11
	help.multiplication(temp_1, temp_4, temp_4);
	//12
	help.multiplication(temp, temp_5, 2);
	if (help.is_Greater(temp_1, temp, 10)) {
		help.soustraction_10(temp_1, temp_1, temp);
	}
	else {
		help.soustraction_10(temp_1, temp_1, temp);
		help.soustraction_10(temp_1, p, temp_1);
	}
	//13
	help.multiplication(temp_2, temp_2, temp_2);
	//14
	help.multiplication(temp_2, temp_2, 8);
	//15
	if (help.is_Greater(temp_5, temp_1, 10)) {
		help.soustraction_10(temp_5, temp_5, temp_1);
	}
	else {
		help.soustraction_10(temp_5, temp_5, temp_1);
		help.soustraction_10(temp_5, p, temp_5);
	}
	//16
	help.multiplication(temp_5, temp_4, temp_5);
	//17
	if (help.is_Greater(temp_5, temp_2, 10)) {
		help.soustraction_10(temp_2, temp_5, temp_2);
	}
	else {
		help.soustraction_10(temp_2, temp_5, temp_2);
		help.soustraction_10(temp_2, p, temp_2);
	}
	//18 -19 -20
	return toAffine(temp_1, temp_2, temp_3);
}

Point EllipticCurve::add_point(Point p1, Point p2) {
	Maths_helper help = Maths_helper(p);

	unsigned char *x1 = p1.get_x();
	unsigned char *y1 = p1.get_y();
	unsigned char *z1 = p1.get_z();

	unsigned char *x2 = p2.get_x();
	unsigned char *y2 = p2.get_y();
	unsigned char *z2 = p2.get_z();

	unsigned char temp[10]; help.init(temp, 10);

	unsigned char temp_1[10]; help.init(temp_1, 10);
	unsigned char temp_2[10]; help.init(temp_2, 10);
	unsigned char temp_3[10]; help.init(temp_3, 10);
	unsigned char temp_4[10]; help.init(temp_4, 10);
	unsigned char temp_5[10]; help.init(temp_5, 10);

	unsigned char temp_6[10]; help.init(temp_6, 10);
	unsigned char temp_7[10]; help.init(temp_6, 10);
	//1-2-3-4-5
	for (int i = 0; i < 10; i++) {
		temp_1[i] = x1[i];
		temp_2[i] = y1[i];
		temp_3[i] = z1[i];
		temp_4[i] = x2[i];
		temp_5[i] = y2[i];
		temp_6[i] = z2[i];
	}
	//6
	unsigned char temp_00[10]; 	help.init(temp_00, 10);
	unsigned char temp_01[10] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 , 0x00, 0x00, 0x00, 0x01 };

	if (!help.isEqual(temp_6, temp_01)) {
		help.addition(temp_6, temp_1, temp_6);
		help.multiplication(temp_7, temp_6, temp_6);
		help.multiplication(temp_1, temp_1, temp_7);
		help.multiplication(temp_7, temp_6, temp_7);
		help.multiplication(temp_2, temp_2, temp_7);
	}
	//7
	help.multiplication(temp_7, temp_3, temp_3);
	//8
	help.multiplication(temp_4, temp_4, temp_7);
	//9
	help.multiplication(temp_7, temp_3, temp_7);
	//10
	help.multiplication(temp_5, temp_5, temp_7);
	//11
	if (help.is_Greater(temp_1, temp_4, 10)) {
		help.soustraction_10(temp_4, temp_1, temp_4);
	}
	else {
		help.soustraction_10(temp_4, temp_1, temp_4);
		help.soustraction_10(temp_4, p, temp_4);
	}
	//12
	if (help.is_Greater(temp_2, temp_5, 10)) {
		help.soustraction_10(temp_5, temp_2, temp_5);
	}
	else {
		help.soustraction_10(temp_5, temp_2, temp_5);
		help.soustraction_10(temp_5, p, temp_5);
	}
	//13
	if (help.isEqual(temp_4, temp_00)) {
		if (help.isEqual(temp_5, temp_00)) {
			return Point(temp_00, temp_00, temp_00);
		}
		else {
			return Point(temp_01, temp_01, temp_00);
		}
	}
	//14
	help.multiplication(temp, temp_1, 2);
	if (help.is_Greater(temp, temp_4, 10)) {
		help.soustraction_10(temp_1, temp, temp_4);
	}
	else {
		help.soustraction_10(temp_1, temp, temp_4);
		help.soustraction_10(temp_1, p, temp_1);
	}
	//15
	help.multiplication(temp, temp_2, 2);
	if (help.is_Greater(temp, temp_5, 10)) {
		help.soustraction_10(temp_2, temp, temp_5);
	}
	else {
		help.soustraction_10(temp_2, temp, temp_5);
		help.soustraction_10(temp_2, p, temp_2);
	}
    //16
	for (int i = 0; i < 10; i++) {
		temp[i] = z1[i];
	}
	if (!help.isEqual(temp, temp_01)) {
		help.multiplication(temp_3, temp_3, temp_6);
	}
	//17
	help.multiplication(temp_3, temp_3, temp_4);
	//18
	help.multiplication(temp_7, temp_4, temp_4);
	//19
	help.multiplication(temp_4, temp_4, temp_7);
	//20
	help.multiplication(temp_7, temp_1, temp_7);
	//21
	help.multiplication(temp_1, temp_5, temp_5);
	//22
	if (help.is_Greater(temp_1, temp_7, 10)) {
		help.soustraction_10(temp_1, temp_1, temp_7);
	}
	else {
		help.soustraction_10(temp_1, temp_1, temp_7);
		help.soustraction_10(temp_1, p, temp_1);
	}
	//23
	help.multiplication(temp, temp_1, 2);
	if (help.is_Greater(temp_7, temp, 10)) {
		help.soustraction_10(temp_7, temp_7, temp);
	}
	else {
		help.soustraction_10(temp_7, temp_7, temp);
		help.soustraction_10(temp_7, p, temp_7);
	}
	//24
	help.multiplication(temp_5, temp_5, temp_7);
	//25
	help.multiplication(temp_4, temp_2, temp_4);
	//26
	if (help.is_Greater(temp_5, temp_4, 10)) {
		help.soustraction_10(temp_2, temp_5, temp_4);
	}
	else {
		help.soustraction_10(temp_2, temp_5, temp_4);
		help.soustraction_10(temp_2, p, temp_2);
	}
	//27
	help.modular_division(temp_2, temp_2, 2);
	//28-29-30
	return toAffine(temp_1, temp_2, temp_3);
}

Point EllipticCurve::toAffine(unsigned char *x, unsigned char *y, unsigned char *z) {

	Maths_helper help = Maths_helper(p);

	unsigned char temp_x[10]; help.init(temp_x, 10);
	unsigned char temp_y[10]; help.init(temp_y, 10);
	unsigned char temp_z[10] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 , 0x00, 0x00, 0x00, 0x01 };

	unsigned char temp_z2[10]; help.init(temp_z2, 10);
	unsigned char temp_z3[10]; help.init(temp_z3, 10);

	help.multiplication(temp_z2, z, z);
	help.multiplication(temp_z3, temp_z2, z);

	help.modular_division(temp_x, x, temp_z2);
	help.modular_division(temp_y, y, temp_z3);
	
	return Point(temp_x, temp_y, temp_z);
}

void EllipticCurve::calculate_points() {
}