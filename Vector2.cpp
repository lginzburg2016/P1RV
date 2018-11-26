#include "Vector3.h"
#include <cmath>

Vector2::Vector2()
{
    x = 0;
    y = 0;
}

Vector2::Vector2(double x,double y)
{
    this->x = x;
    this->y = y;
}

Vector2::Vector2(const Vector2 & v)
{
    setX(v.getX());
    setY(v.getY());
}


Vector2 & Vector2::operator= (const Vector2 & v)
{
    x = v.getX();
    y = v.getY();
    return *this;
}

bool Vector2::operator== (const Vector2 & v) const{
	return (v.getX() == x &&  v.getY() == y);
}

Vector2 & Vector2::operator+= (const Vector2 & v)
{
    x += v.getX();
    y += v.getY();
    return *this;
}

Vector2 Vector2::operator+ (const Vector2 & v) const
{
    Vector2 t = *this;
    t += v;
    return t;
}

Vector2 & Vector2::operator-= (const Vector2 & v)
{
    x -= v.getX();
    y -= v.getY();
    return *this;
}

Vector2 Vector2::operator- (const Vector2 & v) const
{
    Vector2 t = *this;
    t -= v;
    return t;
}

Vector2 & Vector2::operator*= (const double a)
{
    x *= a;
    y *= a;
    return *this;
}

Vector2 Vector2::operator* (const double a)const
{
    Vector2 t = *this;
    t *= a;
    return t;
}

Vector2 operator* (const double a,const Vector2 & v)
{
    return Vector3(v.getX()*a,v.getY()*a);
}

Vector2 & Vector2::operator/= (const double a)
{
    x /= a;
    y /= a;
    return *this;
}

Vector2 Vector2::operator/ (const double a)const
{
    Vector2 t = *this;
    t /= a;
    return t;
}

// Setters/Getters
void Vector2::setX(double x) {
   this->x = x;
}

double Vector2::getX() const {
   return x;
}

void Vector2::setY(double y) {
   this->y = y;
}

double Vector2::getY() const{
   return y;
}


double Vector2::length()const
{
    return sqrt( x*x + y*y );
}

Vector2  Vector2::normalized() const
{
    return (*this) / length();
  
}