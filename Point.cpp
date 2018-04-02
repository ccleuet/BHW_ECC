#include "stdafx.h"
#include "Point.h"


Point::Point()
{
}

Point::~Point()
{
}


Point::Point(unsigned char *x, unsigned char *y) {
	set_x(x);
	set_y(y);
}

Point::Point(unsigned char *x, unsigned char *y, unsigned char *z) {
	set_x(x);
	set_y(y);
	set_z(z);
}


char Point::get_x()
{
	return *x;
}

char Point::get_y()
{
	return *y;
}

char Point::get_z()
{
	return *z;
}

void Point::set_x(unsigned char *x)
{
	this->x = x;
}

void Point::set_y(unsigned char *y)
{
	this->y = y;
}

void Point::set_z(unsigned char *z)
{
	this->z = z;
}

bool Point::isEqual(Point p)
{
	return (*x == p.get_x()) && (*y == p.get_y()) && (*z == p.get_z());
}
