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

EllipticCurve::EllipticCurve(unsigned char *p, unsigned char *a, unsigned char *b){
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

bool EllipticCurve::check_point(Point point) {

	unsigned char *xp = point.get_x();
	unsigned char *yp = point.get_y();

	unsigned char x[10] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 , 0x00, 0x00, 0x00, 0x00 };
	unsigned char y[10] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 , 0x00, 0x00, 0x00, 0x00 };

	for (int i = 0; i < 10; i++) {
		x[i] = xp[i];
		y[i] = yp[i];
	}

	unsigned char left[10] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 , 0x00, 0x00, 0x00, 0x00 };
	unsigned char right[10] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 , 0x00, 0x00, 0x00, 0x00 };

	equation(left, right, x, y);

	return (left == right);
}

//Point EllipticCurve::double_point(Point point) {
//	return add_point(point, point);
//}

//Point EllipticCurve::add_point(Point p1, Point p2) {
//	unsigned char lambda;
//	Point r = Point();
//	Maths_helper help = Maths_helper();
//
//	if (p1.isEqual(p2)) {
//		lambda = (galois_mult((galois_mult(0x3,p2.get_x()),p2.get_x()) ^ a)*help.mul_inv(2 * p2.get_y(),p)) % p;
//	}
//	else if(p1.get_x() == p2.get_x()) {
//		return Point(INT_MAX,INT_MAX,1);
//	}
//	else {
//		lambda = ((p1.get_y() - p2.get_y())*help.mul_inv(p1.get_x() - p2.get_x(),p));
//	}
//
//	unsigned char  xr = (lambda*lambda - p1.get_x() - p2.get_x());
//	unsigned char  yr = ((p2.get_x() - xr)*lambda - p2.get_y());
//
//	r.set_x(help.positive_modulo(xr,p));
//	r.set_y(help.positive_modulo(yr,p));
//	r.set_z(1);
//
//	return r;
//}

void EllipticCurve::calculate_points() {
}


void EllipticCurve::equation(unsigned char *left, unsigned char *right, unsigned char *x, unsigned char *y) {

	Maths_helper help = Maths_helper(p);
	//y^2
	help.multiplication(right, y, y);

	//x^3 + a * x + b;
	unsigned char x_2[10];
	help.multiplication(x_2, x, x);

	unsigned char x_3[10];
	help.multiplication(x_3, x_2, x);

	unsigned char a_x[10];
	help.multiplication(a_x, a, x);

	unsigned char a_x_b[10];
	help.addition(a_x_b, a_x, b);
	help.addition(left, a_x_b, x_3);
}

