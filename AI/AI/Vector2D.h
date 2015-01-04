#ifndef VECTOR2D_H
#define VECTOR2D_H

#include "Headers.h"

class Vector2D
{
    public:
        Vector2D(void);
        Vector2D(double a, double b);
        Vector2D(const Vector2D &v);
        ~Vector2D(void);

        double GetX(void) const;
        double GetY(void) const;

        double Length(void) const;
        double LengthSqrt(void) const;
		double Distance(const Vector2D &v) const;
		double DistanceSqrt(const Vector2D &v) const;
        double Dot(const Vector2D &v) const;
		void Rotate(double rot);
        void Normalize(void);
		void Truncate(double d);
		void SwapXY(void);
		int GetSign(const Vector2D &v) const;

		Vector2D GetReversed(void) const;
		Vector2D GetPerpendicular(void) const;

        Vector2D& operator=(const Vector2D &v);
        Vector2D  operator+(const Vector2D &v);
        Vector2D  operator-(const Vector2D &v);
        Vector2D& operator+=(const Vector2D &v);
        Vector2D& operator-=(const Vector2D &v);
        Vector2D  operator*(const double &d);
        Vector2D  operator/(const double &d);
		Vector2D& operator*=(const double &d);
		Vector2D& operator/=(const double &d);
        void operator()(double x, double y);
        bool operator==(const Vector2D &v);
        bool operator!=(const Vector2D &v);

    private:
        double x;
        double y;

        friend ostream& operator<<(ostream &o, const Vector2D &v);
};

ostream& operator<<(ostream &o, const Vector2D &v);

inline double Vector2D::GetX(void) const
{
	return this->x;
}

inline double Vector2D::GetY(void) const
{
	return this->y;
}

inline double Vector2D::Length(void) const
{
	return sqrt(x*x + y*y);
}

inline double Vector2D::LengthSqrt(void) const
{
	return (x*x + y*y);
}

inline double Vector2D::Distance(const Vector2D &v) const
{
	double xd = v.x - this->x;
	double yd = v.y - this->y;

	return sqrt(xd*xd + yd*yd);
}

inline double Vector2D::DistanceSqrt(const Vector2D &v) const
{
	double xd = v.x - this->x;
	double yd = v.y - this->y;

	return (xd*xd + yd*yd);
}

inline double Vector2D::Dot(const Vector2D &v) const
{
	return (this->x*v.x + this->y*v.y);
}

inline void Vector2D::Rotate(double rot)
{
	double xp = x, yp = y;
	this->x = xp*cos(rot) - yp*sin(rot);
	this->y = xp*sin(rot) + yp*cos(rot);
}

inline void Vector2D::Normalize(void)
{
	double l = this->Length();
	this->x /= l;
	this->y /= l;
}

inline void Vector2D::Truncate(double d)
{
	if(this->Length() > d)
	{
		this->Normalize();
		this->x *= d;
		this->y *= d;
	}
}

inline void Vector2D::SwapXY(void)
{
	double tmp = x;
	x = y;
	y = tmp;
}

inline int Vector2D::GetSign(const Vector2D &v) const
{
	if(this->y*v.x > this->x*v.y)
		return -1;
	else
		return 1;
}

inline Vector2D Vector2D::GetReversed(void) const
{
	return Vector2D(-this->x, -this->y);
}

inline Vector2D Vector2D::GetPerpendicular(void) const
{
	return Vector2D(-this->y, this->y);
}

#endif
