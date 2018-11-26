#pragma once

#include <iostream>
using namespace std;

class Vector2
{
private:
	double x;
	double y;

public:
	
	Vector2();
	Vector2(double x,double y);
	Vector2(const Vector2 & v);
   
	Vector2 & operator= (const Vector2 & v);

	bool operator== (const Vector2 & v) const;
   
	Vector2 & operator+= (const Vector2 & v);
	Vector2 operator+ (const Vector2 & v) const;
   
	Vector2 & operator-= (const Vector2 & v);
	Vector2 operator- (const Vector2 & v) const;
   
	Vector2 & operator*= (const double a);
	Vector2 operator* (const double a)const;
	friend Vector2 operator* (const double a,const Vector2 & v);
   
	Vector2 & operator/= (const double a);
	Vector2 operator/ (const double a)const;
   
	// Setters/Getters
	void setX(double x);
	double getX() const;
   
	void setY(double y);
	double getY() const;
      
	double length()const;
	Vector2  normalized() const;
   
	friend ostream& operator<<(ostream& os, Vector2 const & v) {
		return os << "("<<v.getX()<<","<<v.getY()<<")" << endl;
	}
};

