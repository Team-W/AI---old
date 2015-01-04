#include "Vector2D.h"

Vector2D::Vector2D(void):x(0), y(0)
{
    //cout << "+Vector2D (default)" << endl;
}

Vector2D::Vector2D(double a, double b):x(a), y(b)
{
    //cout << "+Vector2D (param)" << endl;
}

Vector2D::Vector2D(const Vector2D &v)
{
    //cout << "+Vector2D (copy)" << endl;
    this->x = v.x;
    this->y = v.y;
}

Vector2D::~Vector2D(void)
{
    //cout << "-Vector2D" << endl;
}

Vector2D& Vector2D::operator=(const Vector2D &v)
{
    this->x = v.x;
    this->y = v.y;
    return *this;
}

Vector2D Vector2D::operator+(const Vector2D &v)
{
	return Vector2D(this->x + v.x, this->y + v.y);
}

Vector2D Vector2D::operator-(const Vector2D &v)
{
	return Vector2D(this->x - v.x, this->y - v.y);
}

Vector2D& Vector2D::operator+=(const Vector2D &v)
{
    this->x += v.x;
    this->y += v.y;
    return *this;
}

Vector2D& Vector2D::operator-=(const Vector2D &v)
{
    this->x -= v.x;
    this->y -= v.y;
    return *this;
}

Vector2D Vector2D::operator*(const double &d)
{
	return Vector2D(this->x * d, this->y * d);
}

Vector2D Vector2D::operator/(const double &d)
{
	return Vector2D(this->x / d, this->y / d);
}

Vector2D& Vector2D::operator*=(const double &d)
{
	this->x *= d;
	this->y *= d;
	return *this;
}

Vector2D& Vector2D::operator/=(const double &d)
{
	this->x /= d;
	this->y /= d;
	return *this;
}

void Vector2D::operator()(double x, double y)
{
    this->x = x;
    this->y = y;
}

bool Vector2D::operator==(const Vector2D &v)
{
    return (this->x == v.x && this->y == v.y);
}

bool Vector2D::operator!=(const Vector2D &v)
{
    return (this->x != v.x && this->y != v.y);
}

ostream& operator<<(ostream &o, const Vector2D &v)
{
    o.setf(ios::fixed, ios::floatfield);
    o.precision(4);
    o << "[" << v.x << ", " << v.y << "]\n";
    o.unsetf(ios::floatfield);
    return o;
}
