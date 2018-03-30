#include "stdafx.h"
#include "Point.h"


Point::Point()
{
}

Point::~Point()
{
}

Point::Point(int x, int y, int z) {
	set_x(x);
	set_y(y);
	set_z(z);
}


int Point::get_x()
{
	return x;
}

int Point::get_y()
{
	return y;
}

int Point::get_z()
{
	return z;
}

void Point::set_x(int x)
{
	this->x = x;
}

void Point::set_y(int y)
{
	this->y = y;
}

void Point::set_z(int z)
{
	this->z = z;
}

bool Point::isEqual(Point p)
{
	return (x == p.get_x()) && (y == p.get_y()) && (z == p.get_z());
}
