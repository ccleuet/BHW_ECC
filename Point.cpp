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
	unsigned char z[10] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 , 0x00, 0x00, 0x00, 0x01 };
	set_z(z);
}

Point::Point(unsigned char *x, unsigned char *y, unsigned char *z) {
	set_x(x);
	set_y(y);
	set_z(z);
}


unsigned char * Point::get_x()
{
	return x;
}

unsigned char * Point::get_y()
{
	return y;
}

unsigned char * Point::get_z()
{
	return z;
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
	return (x == p.get_x()) && (y == p.get_y()) && (z == p.get_z());
}