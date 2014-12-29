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

        inline double GetX(void) const;
        inline double GetY(void) const;

        inline double Length(void) const;
        inline double LengthSqrt(void) const;
        inline double Dot(const Vector2D &v) const;
        inline void Normalize(void);

        Vector2D& operator=(const Vector2D &v);
        Vector2D& operator+(const Vector2D &v);
        Vector2D& operator-(const Vector2D &v);
        Vector2D& operator+=(const Vector2D &v);
        Vector2D& operator-=(const Vector2D &v);
        Vector2D& operator*(const double &d);
        Vector2D& operator/(const double &d);
        void operator()(double x, double y);
        bool operator==(const Vector2D &v);
        bool operator!=(const Vector2D &v);

    private:
        double x;
        double y;

        friend ostream& operator<<(ostream &o, const Vector2D &v);
};

ostream& operator<<(ostream &o, const Vector2D &v);

#endif
