#ifndef POINT_H
#define POINT_H

#include "Headers.h"
#include "GameEntity.h"

class Point: public GameEntity
{
public:
	Point();
	Point(double x, double y, double rad);
	~Point(void);

	void Update(double delta_time);
	void Draw(double delta_time);
	void Draw(double x, double y);
	void Draw(const Vector2D &v);
	void InitDraw(void);

private:
	double radius;
	friend ostream& operator<<(ostream &o, const Point &ob);
};

ostream& operator<<(ostream &o, const Point &ob);

#endif
