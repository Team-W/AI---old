#ifndef VECTOR2D_H
#define VECTOR2D_H

#include "stdafx.h"

class Vector2D
{
    public:
        Vector2D(void);
        Vector2D(double a, double b);
        Vector2D(const Vector2D &v);
        ~Vector2D(void);

        inline double GetX(void) const;
        inline double GetY(void) const;

        inline double Length(void) const;
        inline double LengthSqrt(void) const;
        inline double Dot(const Vector2D &v) const;
        inline void Normalize(void);

        inline Vector2D& operator=(const Vector2D &v);
        inline Vector2D& operator+(const Vector2D &v);
        inline Vector2D& operator-(const Vector2D &v);
        inline Vector2D& operator+=(const Vector2D &v);
        inline Vector2D& operator-=(const Vector2D &v);
        inline Vector2D& operator*(const double &d);
        inline Vector2D& operator/(const double &d);
        inline void operator()(double x, double y);
        inline bool operator==(const Vector2D &v);
        inline bool operator!=(const Vector2D &v);

    private:
        double x;
        double y;

        friend ostream& operator<<(ostream &o, const Vector2D &v);
};

inline ostream& operator<<(ostream &o, const Vector2D &v);

#endif
