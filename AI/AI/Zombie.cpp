#include "Zombie.h"

Zombie::Zombie(double x, double y)
{
    this->position(x, y);
    this->velocity(0, 0);
    this->heading(0, 0);
    this->side(0, 0);

	cout << velocity.GetX();
}

Zombie::~Zombie(void)
{

}

void Zombie::Update(double delta_time)
{
	Vector2D acceleration = steering_behaviour.GetSteeringForce();
	velocity += acceleration * delta_time;
	velocity.Truncate(ZOMBIE_MAX_SPEED);
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
    Update(delta_time);
}

ostream& operator<<(ostream &o, const Zombie &z)
{
    o << "--------------- ZOMBIE ---------------" << "\n";
    o << "Object ID:\t" << z.id         << "\n";
    o << "Position:\t"  << z.position   << "\n";
    o << "Velocity:\t"  << z.velocity   << "\n";
    o << "Heading:\t"   << z.heading    << "\n";
    o << "Side:\t\t"    << z.side       << "\n";
	o << "\n"           << z.steering_behaviour;
    o << "--------------------------------------" << endl;
    return o;
}
