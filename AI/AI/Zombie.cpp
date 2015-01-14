#include "Zombie.h"

Zombie::Zombie(double x, double y)
{
	this->steering_behaviour = new SteeringBehaviour(this);
    this->position(x, y);
    this->velocity(0, 0);
    this->heading(0, 0.5);
    this->side(0, 0);
	this->rotation = 0;
	p = new Point(0, 0, 0.3);
	Scale(glm::vec3(0.03f, 0.03f, 1.0f));
	Translate(glm::vec3(x, y, 0));
}

Zombie::~Zombie(void)
{

}

void Zombie::Update(double delta_time)
{
	// system("cls"); cout << *this;
	Vector2D acceleration = steering_behaviour->GetSteeringForce();
	double angle = atan2(acceleration.GetX(), acceleration.GetY());
	Vector2D tmp = acceleration;
	//tmp.Rotate(angle);
	p->Draw(tmp);
	velocity += acceleration * delta_time;
	velocity.Truncate(ZOMBIE_MAX_SPEED);
	//cout << atan2(-2, 0) * 180 / PI << "\n";//funkcja do obliczania kata !!
	//system("pause");
	//double angle = acos(acceleration.Dot(heading) / (heading.Length()*acceleration.Length()));

	if(velocity.LengthSqrt() > 0.00000001)
	{
		heading = velocity;
		heading.Normalize();
		side = heading.GetPerpendicular();
		}
		/*/counting angle between 2 vectors
	Vector2D standard = Vector2D(0.0, 1.0);
	
	rotation += angle;
	cout << angle << "\n";
	//velocity.Rotate(rotation); //rotating velocity vector to move in the correct direction*/
	/*double angle = atan2(velocity.GetX(), velocity.GetY()) * 180 / PI;
	cout << velocity << angle << "\n";
	rotation = angle;
	velocity.Rotate(angle);*/
	//model_Matrix[12] = velocity.GetX()* delta_time;
	//model_Matrix[13] = velocity.GetY()* delta_time;
	
    position += velocity * delta_time;
	
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
	GLfloat Matrix[16];
	getMatrix(Matrix);
	glLoadMatrixf(Matrix);
		//glTranslated(position.GetX(), position.GetY(), 0.0);
		//glRotated(rotation, 0.0f, 0.0f, 1.0f);
	for (int i = 0; i < 4; i++){
		cout << "[ " << Matrix[i] << " " << Matrix[i + 1] << " " << Matrix[i + 2] << " " << Matrix[i + 3] << " ]\n";
	}
	system("pause");
		glBegin(GL_TRIANGLES);
			glColor3f(0.0f, 0.0f, 1.0f);
			glVertex3f(-0.50f,-0.60f, 0.f);
			glVertex3f( 0.50f,-0.60f, 0.f);
			glVertex3f( 0.00f, 0.75f, 0.f);
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
