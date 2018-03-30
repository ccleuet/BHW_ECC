#pragma once

#include "Point.h"

class EllipticCurve
{

private:
	int p;
	int a;
	int b;

public:
	EllipticCurve();
	EllipticCurve(int p, int a, int b);
	~EllipticCurve();

	int get_a();
	int get_b();
	int get_p();

	void set_p(int p);
	void set_a(int a);
	void set_b(int b);

	bool check_point(Point point);
	Point double_point(Point point);
	Point add_point(Point p1, Point p2);
	void calculate_points();

};

