#include "Obstacle.h"

Obstacle::Obstacle(){};

Obstacle::Obstacle(double x, double y, double rad)
{
    this->position(x, y);
	this->radius = rad;
    this->heading(0, 0);
    this->side(0, 0);
}

Obstacle::~Obstacle(void)
{

}

void Obstacle::Update(double delta_time)
{

}

void Obstacle::Draw(double delta_time)
{
    Update(delta_time);
}

void Obstacle::InitDraw()
{
	glEnable(GL_LINE_SMOOTH);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

	float a, b;
	glPushMatrix();
	glTranslatef(position.GetX(), position.GetY(), 0.0);
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.3f, 0.1f, 0.0f);

	a = (float)radius * cos(359 * PI / 180.0f);
	b = (float)radius * sin(359 * PI / 180.0f);
	for (int j = 0; j < 360; j++)
	{
		glVertex2f(a, b);
		a = (float)radius * cos(j * PI / 180.0f);
		b = (float)radius * sin(j * PI / 180.0f);
		glVertex2f(a, b);
	}

	glEnd();
	glPopMatrix();

	glDisable(GL_LINE_SMOOTH);
}

ostream& operator<<(ostream &o, const Obstacle &ob)
{
    o << "-------------- OBSTACLE --------------" << "\n";
    o << "Object ID:\t" << ob.id         << "\n";
    o << "Position:\t"  << ob.position   << "\n";
    o << "Heading:\t"   << ob.heading    << "\n";
    o << "Side:\t\t"    << ob.side       << "\n";
    o << "--------------------------------------" << endl;
    return o;
}
