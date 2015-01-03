#include "Zombie.h"

Zombie::Zombie()
{

}

Zombie::Zombie(double x, double y)
{
	this->steering_behaviour = new SteeringBehaviour(this);
    this->position(x, y);
    this->velocity(0, 0);
    this->heading(0, 0);
    this->side(0, 0);
	this->rotation = 0;
}

Zombie::~Zombie(void)
{

}

void Zombie::Update(double delta_time)
{
	
	// system("cls"); cout << *this;
	Vector2D acceleration = steering_behaviour->GetSteeringForce();
	double a = 0.0, b=3.0;
	double ra = acceleration.GetX();
	double rb = acceleration.GetY();
	double counter = ra*a + rb*b;
	double denominator = sqrt((ra*ra + rb*rb))*sqrt((a*a) + (b*b));
	double angle = acos(counter / denominator);

	rotation += angle;
	velocity += acceleration * delta_time;
	velocity.Truncate(ZOMBIE_MAX_SPEED);
	velocity.Rotate(angle);
    position += velocity * delta_time;
	
	if(velocity.LengthSqrt() > 0.00000001)
	{
		heading = velocity;
		heading.Normalize();
		side = heading.GetPerpendicular();
	}
}

void Zombie::Draw(double delta_time)
{

}

void Zombie::InitDraw()
{
	float a, b;
	glEnable(GL_LINE_SMOOTH);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	glPushMatrix();		
		glTranslatef(position.GetX(), position.GetY(), 0.0);
		glRotatef(rotation, 0.0f, 0.0f, 1.0f);

		glBegin(GL_TRIANGLES);
			glColor3f(1.0f, 1.0f, 0.0f);
			glVertex3f(-0.03f,-0.05f, 0.f);
			glVertex3f( 0.03f,-0.05f, 0.f);
			glVertex3f( 0.00f, 0.05f, 0.f);
		glEnd();

		glBegin(GL_LINES);
			glColor3f(0.0f, 1.0f, 0.0f);

			a = (float)0.07 * cos(359 * PI / 180.0f);
			b = (float)0.07 * sin(359 * PI / 180.0f);
			for (int j = 0; j < 360; j++)
			{
				glVertex2f(a, b);
				a = (float)0.07 * cos(j * PI / 180.0f);
				b = (float)0.07 * sin(j * PI / 180.0f);
				glVertex2f(a, b);
			}
		glEnd();
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
