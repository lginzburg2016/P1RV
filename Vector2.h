#pragma once

#include <iostream>
using namespace std;

class Vector2
{
private:
	int x;
	int y;

public:
	
	Vector2();
	Vector2(int x,int y);
	Vector2(const Vector2 & v);
   
	Vector2 & operator= (const Vector2 & v);

	bool operator== (const Vector2 & v) const;
   
	Vector2 & operator+= (const Vector2 & v);
	Vector2 operator+ (const Vector2 & v) const;
   
	Vector2 & operator-= (const Vector2 & v);
	Vector2 operator- (const Vector2 & v) const;
    
   
	// Setters/Getters
	void setX(int x);
	int getX() const;
   
	void setY(int y);
	int getY() const;
      
	double length()const;
	Vector2  normalized() const;
   
	friend ostream& operator<<(ostream& os, Vector2 const & v) {
		return os << "("<<v.getX()<<","<<v.getY()<<")" << endl;
	}
};

