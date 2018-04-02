#pragma once
class Point {

private:
	unsigned char *x;
	unsigned char *y;
	unsigned char *z;

public:
	Point();
	~Point();
	Point(unsigned char *x, unsigned char *y);
	Point(unsigned char *x, unsigned char *y, unsigned char *z);

	char get_x();
	char get_y();
	char get_z();

	void set_x(unsigned char *x);
	void set_y(unsigned char *y);
	void set_z(unsigned char *z);
	
	bool isEqual(Point p);
};