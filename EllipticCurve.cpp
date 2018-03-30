#include "stdafx.h"
#include "EllipticCurve.h"
#include "Maths_helper.h"

EllipticCurve::EllipticCurve()
{
}

EllipticCurve::~EllipticCurve()
{
}

EllipticCurve::EllipticCurve(int p, int a, int b) {
	set_p(p);
	set_a(a);
	set_b(b);
}

int EllipticCurve::get_a()
{
	return a;
}

int EllipticCurve::get_b()
{
	return b;
}

int EllipticCurve::get_p()
{
	return p;
}


void EllipticCurve::set_p(int p)
{
	this->p = p;
}

void EllipticCurve::set_a(int a)
{
	this->a = a;
}

void EllipticCurve::set_b(int b)
{
	this->b = b;
}

bool EllipticCurve::check_point(Point point) {

	int x = point.get_x();
	int y = point.get_y();

	return (y*y) % p == (x*x*x + a * x + b) % p;
}


Point EllipticCurve::double_point(Point point) {
	return add_point(point, point);
}

Point EllipticCurve::add_point(Point p1, Point p2) {
	double lambda;
	Point r = Point();
	Maths_helper help = Maths_helper();

	if (p1.isEqual(p2)) {
		lambda = ((3 * p2.get_x()*p2.get_x() + a)*help.mul_inv(2 * p2.get_y(),p)) % p;
	}
	else {
		lambda = ((p1.get_y() - p2.get_y())*help.mul_inv(p1.get_x() - p2.get_x(),p))%p;
	}

	if (lambda < 0) { lambda = help.positive_modulo(lambda, p); };

	int xr = (int)(lambda*lambda - p1.get_x() - p2.get_x()) % p;
	int yr =(int) ((p2.get_x() - xr)*lambda - p2.get_y()) % p;

	r.set_x(xr);
	r.set_y(yr);
	return r;
}

void EllipticCurve::calculate_points() {
}

