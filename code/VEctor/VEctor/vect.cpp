#include <math.h>
#include <iostream>
#include "pch.h"
#include "vect.h"
using namespace std;
namespace VECTOR {
	
	const double Rad_to_deg = 45.0 / atan(1.0);
	void Vector::set_mag()
	{
		mag = sqrt(x*x + y * y);
	}
	void Vector::set_ang()
	{
		if (x == 0.0&& y == 0.0)
			ang = 0.0;
		else
			ang = atan2(y, x);
	}
	//set x from polar coordinate
	void Vector::set_x()
	{
		x = mag * cos(ang);
	}
	void Vector::set_y()
	{
		y = mag * sin(ang);
	}
	//public methods
	Vector::Vector()
	{
		x = y = mag = ang = 0.0;
		mode = RECT;
	}
	Vector::Vector(double n1, double n2, Mode form)
	{
		mode = form;
		if (form == RECT)
		{
			x = n1;
			y = n2;
			set_ang();
			set_mag();
		}
		else if (form == POL)
		{
			mag = n1;
			ang = n2;
			set_x();
			set_y();
		}
		else
		{
			cout << "wrong";
			cout << "vector set to 0\n";
			x = y = mag = ang = 0.0;
			mode = RECT;
		}
	}
	void Vector::reset(double n1, double n2, Mode form)
	{
		mode = form;
		if (form == RECT)
		{
			x = n1;
			y = n2;
			set_ang();
			set_mag();
		}
		else if (form == POL)
		{
			mag = n1;
			ang = n2;
			set_x();
			set_y();
		}
		else
		{
			cout << "wrong";
			cout << "vector set to 0\n";
			x = y = mag = ang = 0.0;
			mode = RECT;
		}
	}
	Vector::~Vector()
	{
	}
	void Vector::polar_mode()
	{
		mode = POL;
	}
	void Vector::rect_mode()
	{
		mode = RECT;
	}


	Vector Vector::operator+(const Vector & b) const //返回值不加& 原因是在函数运行后会释放空间，若加&，则其值会和函数内部变量一样被释放，
	{
		return Vector(x + b.x, y + b.y);//这里应该判断FORM一样
	}
	Vector Vector::operator-(const Vector & b) const
	{
		return Vector(x - b.x, y - b.y);
	}
	Vector Vector::operator-() const
	{
		return Vector(-x, -y);
	}
	Vector Vector::operator*(double n) const
	{
		return Vector(x*n, y*n);
	}
	//friend;
	//friend;
	 Vector operator*(double n, const Vector & b)
	{
		return b.operator*(n);//return a*n;
	}
	 std::ostream & operator<<(std::ostream & os, const Vector & v)
	{
		if (v.mode == Vector::RECT)
			os << "(x,y)=(" << v.x << "," << v.y << ")";
		else if (v.mode == Vector::POL)
		{
			os << "(m,a)=(" << v.mag << "," << v.ang*Rad_to_deg << ")";
		}
		else
			os << "Vector object mode is invalid";
		return os;
	}//不知为何 友元在别的地方定义还是不能访问PRIVATE，素以只能这样
}
