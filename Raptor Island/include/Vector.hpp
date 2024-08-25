#pragma once

#include <iostream>

class Vector
{
public:
	Vector(void);
	Vector(double, double);
	~Vector(void) {};
	double	getX(void) const;
	double	getY(void) const;
	void	setX(double);
	void	setY(double);
	double	getLength(void) const;
	bool	operator==(const Vector& other) const;
	Vector	operator+(const Vector&);
	Vector	operator+(const double);
	Vector	operator-(const Vector&);
	Vector	operator*(double);
	Vector	operator/(double);
	Vector& operator*=(double);
	Vector& operator/=(double);
	void	normalize(void);
	friend	Vector& operator+=(Vector& vec1, const Vector& vec2);
	friend	Vector& operator-=(Vector& vec1, const Vector& vec2);
private:
	double x;
	double y;
};