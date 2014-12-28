#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "stdafx.h"
#include "GameEntity.h"
#include "SteeringBehaviour.h"

class Zombie: public GameEntity
{
    public:
        Zombie(double x, double y);
        ~Zombie(void);

        void Update(double delta_time);
        void Draw(double delta_time);

        inline Vector2D GetVelocity(void) const;

    private:
        Vector2D velocity;      // wektor predkosci

        //SteeringBehaviour steering_behaviour;

        friend ostream& operator<<(ostream &o, const Zombie &z);
};

inline ostream& operator<<(ostream &o, const Zombie &z);

#endif
