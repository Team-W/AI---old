#include "Player.h"

Player::Player(double x, double y)
{
    this->position(x, y);
    this->velocity(0, 0);
    this->heading(0, 0);
    this->side(0, 0);
}

Player::~Player(void)
{

}

void Player::Update(double delta_time)
{
    position += velocity * delta_time;
}

void Player::Draw(double delta_time)
{
    Update(delta_time);
}

inline Vector2D Player::GetVelocity(void) const
{
    return this->velocity;
}

ostream& operator<<(ostream &o, const Player &p)
{
    o << "--------------- PLAYER ---------------" << "\n";
    o << "Object ID:\t" << p.id         << "\n";
    o << "Position:\t"  << p.position   << "\n";
    o << "Velocity:\t"  << p.velocity   << "\n";
    o << "Heading:\t"   << p.heading    << "\n";
    o << "Side:\t\t"    << p.side       << "\n";
    o << "--------------------------------------" << endl;
    return o;
}
