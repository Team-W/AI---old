#include "Obstacle.h"

Obstacle::Obstacle(double x, double y)
{
    this->position(x, y);
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
