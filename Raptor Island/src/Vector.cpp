#include "Vector.hpp"

Vector::Vector(void) : x(0), y(0)
{}

Vector::Vector(double x, double y) : x(x), y(y)
{}

double	Vector::getX(void) const
{
	return (x);
}

double	Vector::getY(void) const
{
	return (y);
}

void	Vector::setX(double x)
{
	this->x = x;
}

void	Vector::setY(double y)
{
	this->y = y;
}

double	Vector::getLength(void) const
{
	return (sqrt(x * x + y * y));
}
bool Vector::operator==(const Vector& other) const
{
	double epsilon = 1;  // Tolerance value
	return (std::abs(x - other.x) < epsilon) && (std::abs(y - other.y) < epsilon);
}
Vector Vector::operator+(const Vector& vec)
{
	return (Vector(x + vec.x, y + vec.y));
}

Vector	Vector::operator+(const double a)
{
	return (Vector(x + a, y + a));
}

Vector Vector::operator-(const Vector& vec)
{
	return (Vector(x - vec.x, y - vec.y));
}

Vector Vector::operator*(double scalar)
{
	return (Vector(x * scalar, y * scalar));
}

Vector Vector::operator/(double scalar)
{
	return (Vector(x / scalar, y / scalar));
}

void    Vector::normalize(void)
{
	float len = getLength();
	if (len > 0)
		*this *= 1 / len;
}

Vector& operator+=(Vector& vec1, const Vector& vec2)
{
	vec1.x += vec2.x;
	vec1.y += vec2.y;
	return (vec1);
}

Vector& operator-=(Vector& vec1, const Vector& vec2)
{
	vec1.x -= vec2.x;
	vec1.y -= vec2.y;
	return (vec1);
}

Vector& Vector::operator*=(double scalar)
{
	x *= scalar;
	y *= scalar;
	return (*this);
}

Vector& Vector::operator/=(double scalar)
{
	x /= scalar;
	y /= scalar;
	return (*this);
}