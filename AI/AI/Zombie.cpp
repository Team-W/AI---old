#include "Zombie.h"

Zombie::Zombie(double x, double y)
{
    this->position(x, y);
    this->velocity(0, 0);
    this->heading(0, 0);
    this->side(0, 0);
}

Zombie::~Zombie(void)
{

}

void Zombie::Update(double delta_time)
{
    position += velocity * delta_time;
}

void Zombie::Draw(double delta_time)
{
    Update(delta_time);
}

inline Vector2D Zombie::GetVelocity(void) const
{
    return this->velocity;
}

inline ostream& operator<<(ostream &o, const Zombie &z)
{
    o << "--------------- ZOMBIE ---------------" << "\n";
    o << "Object ID:\t" << z.id         << "\n";
    o << "Position:\t"  << z.position   << "\n";
    o << "Velocity:\t"  << z.velocity   << "\n";
    o << "Heading:\t"   << z.heading    << "\n";
    o << "Side:\t\t"    << z.side       << "\n";
//    o << "\n"           << z.steering_behaviour   << "\n";
    o << "--------------------------------------" << endl;
    return o;
}
