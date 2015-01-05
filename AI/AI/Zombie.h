#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "Headers.h"
#include "GameEntity.h"
#include "SteeringBehaviour.h"
#include "Point.h"

class SteeringBehaviour;

class Zombie: public GameEntity
{
    public:
		Zombie();
        Zombie(double x, double y);
        ~Zombie(void);

        void Update(double delta_time);
        void Draw(double delta_time);
		void InitDraw();

        inline const Vector2D& GetVelocity(void) const;

    private:
        Vector2D velocity;
		Point *p;
		double rotation;

        SteeringBehaviour *steering_behaviour;

        friend ostream& operator<<(ostream &o, const Zombie &z);
};

ostream& operator<<(ostream &o, const Zombie &z);

inline const Vector2D& Zombie::GetVelocity(void) const
{
	return this->velocity;
}

#endif
