#include "Point.h"

Point::Point(){};

Point::Point(double x, double y, double rad)
{
	this->position(x, y);
	this->radius = rad;
	this->heading(0, 0);
	this->side(0, 0);
}

Point::~Point(void)
{

}

void Point::Update(double delta_time)
{

}

void Point::Draw(double x, double y)
{
	this->position(x, y);
}

void Point::Draw(double delta_time)
{

}

void Point::Draw(const Vector2D &v)
{
	this->position = v;
}

void Point::InitDraw()
{
	float a, b;
	glPushMatrix();
	glTranslatef(position.GetX(), position.GetY(), 0.0);
	glBegin(GL_TRIANGLE_FAN);

	glColor3f(0.0f, 1.0f, 0.0f);

	a = (float)radius * cos(359 * PI / 180.0f);
	b = (float)radius * sin(359 * PI / 180.0f);
	for(int j = 0; j < 360; j++)
	{
		glVertex2f(a, b);
		a = (float)radius * cos(j * PI / 180.0f);
		b = (float)radius * sin(j * PI / 180.0f);
		glVertex2f(a, b);
	}

	glEnd();
	glPopMatrix();
}

ostream& operator<<(ostream &o, const Point &ob)
{
	o << "--------------- POINT ----------------" << "\n";
	o << "Object ID:\t" << ob.id         << "\n";
	o << "Position:\t"  << ob.position   << "\n";
	o << "Heading:\t"   << ob.heading    << "\n";
	o << "Side:\t\t"    << ob.side       << "\n";
	o << "--------------------------------------" << endl;
	return o;
}
