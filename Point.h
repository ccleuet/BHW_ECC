#pragma once
class Point {

private:
	int  x;
	int  y;
	int  z;

public:
	Point();
	Point(int x, int y, int z);
	~Point();

	int get_x();
	int get_y();
	int get_z();

	void set_x(int x);
	void set_y(int y);
	void set_z(int z);
	
	bool isEqual(Point p);
};