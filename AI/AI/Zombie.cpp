#include "Zombie.h"

Zombie::Zombie(double x, double y)
{
	this->steering_behaviour = new SteeringBehaviour(this);
    this->position(x, y);
    this->velocity(0, 5);
    this->heading(0, 0.5);
    this->side(0, 0);
	this->rotation = 0;
	p = new Point(0, 0, 0.3);
	Scale(glm::vec3(0.03f, 0.03f, 1.0f)); // skalowanie do modelview, oddzielne od maina
	Translate(glm::vec3(x, y, 0));
}

Zombie::~Zombie(void)
{

}

void Zombie::Update(double delta_time)
{
	Vector2D acceleration = steering_behaviour->GetSteeringForce();

	
	Vector2D tmp = acceleration;
	//p->Update(tmp);//wander target


	velocity += acceleration * delta_time;
	velocity.Truncate(ZOMBIE_MAX_SPEED);
		
	Vector2D move = velocity * delta_time;
	position += move;

	if (velocity.LengthSqrt() > 0.00000001)
	{
		heading = velocity;
		heading.Normalize();
		side = heading.GetPerpendicular();
	}

	
	angle = -atan2(move.GetX(), move.GetY()); 	
	rotation += angle * 180.f / PI;

	//Rotate(angle, glm::vec3(0,0,1));
	Translate(glm::vec3(move.GetX(), move.GetY(), 0));
	//cout << rotation << " " << "\n";
	
	move.Rotate(rotation * 180.f / PI);
		
}

void Zombie::InitDraw()
{
	float a, b;
	glEnable(GL_LINE_SMOOTH);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	glPushMatrix();
	GLfloat Matrix[16];
	getMatrix(Matrix);
	glLoadMatrixf(Matrix);
	//glTranslated(position.GetX(), position.GetY(), 0.0);
	//glRotated(rotation, 0.0f, 0.0f, 1.0f);
	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-0.50f, -0.60f, 0.f);
	glVertex3f(0.50f, -0.60f, 0.f);
	glVertex3f(0.00f, 0.75f, 0.f);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.5f, 0.0f, 0.0f);

	a = 1.0f * cos(359 * PI / 180.0f);
	b = 1.0f * sin(359 * PI / 180.0f);
	for (int j = 0; j < 360; j++)
	{
		glVertex2f(a, b);
		a = 1.0f * cos(j * PI / 180.0f);
		b = 1.0f * sin(j * PI / 180.0f);
		glVertex2f(a, b);
	}
	glEnd();
	p->InitDraw();
	glPopMatrix();
	glDisable(GL_LINE_SMOOTH);


}


ostream& operator<<(ostream &o, const Zombie &z)
{
    o << "--------------- ZOMBIE ---------------" << "\n";
    o << "Object ID:\t" << z.id         << "\n";
    o << "Position:\t"  << z.position   << "\n";
    o << "Velocity:\t"  << z.velocity   << "\n";
    o << "Heading:\t"   << z.heading    << "\n";
    o << "Side:\t\t"    << z.side       << "\n";
	o << "\n"           << *(z.steering_behaviour);
    o << "--------------------------------------" << endl;
    return o;
}
