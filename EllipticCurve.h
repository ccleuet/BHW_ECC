#pragma once

#include "Point.h"

class EllipticCurve
{

private:
	unsigned char *p;
	unsigned char *a;
	unsigned char *b;

public:
	EllipticCurve();
	EllipticCurve(unsigned char *p, unsigned char *a, unsigned char *b);
	~EllipticCurve();

	unsigned char*  get_a();
	unsigned char*  get_b();
	unsigned char*  get_p();

	void set_p(unsigned char *p);
	void set_a(unsigned char *a);
	void set_b(unsigned char *b);

	//bool check_point(Point point);
	//Point get_inverse(Point point);
	//Point double_point(Point point);
	//Point add_point(Point p1, Point p2);
	void calculate_points();

};

