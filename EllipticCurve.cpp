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

Point EllipticCurve::get_inverse(Point point) {
	Point point_inverse = Point();
	point_inverse.set_x(point.get_x());
	point_inverse.set_y(-point.get_y());
	point_inverse.set_z(point.get_z());
	return point_inverse;
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
	else if(p1.get_x() == p2.get_x()) {
		return Point(INT_MAX,INT_MAX,1);
	}
	else {
		lambda = ((p1.get_y() - p2.get_y())*help.mul_inv(p1.get_x() - p2.get_x(),p))%p;
	}

	if (lambda < 0) { lambda = help.positive_modulo(lambda, p); };

	int xr = (int)(lambda*lambda - p1.get_x() - p2.get_x()) % p;
	int yr =(int) ((p2.get_x() - xr)*lambda - p2.get_y()) % p;

	r.set_x(help.positive_modulo(xr,p));
	r.set_y(help.positive_modulo(yr,p));
	r.set_z(1);

	return r;
}

void EllipticCurve::calculate_points() {
}

