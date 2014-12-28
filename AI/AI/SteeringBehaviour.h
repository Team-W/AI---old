#ifndef STEERING_BEHAVIOUR_H
#define STEERING_BEHAVIOUR_H

#include "stdafx.h"
#include "GameEntity.h"
#include "Zombie.h"
#include "GameWorld.h"


class SteeringBehaviour
{
    public:
        SteeringBehaviour(void);
        ~SteeringBehaviour(void);

    private:

        friend ostream& operator<<(ostream &o, const SteeringBehaviour &sb);
};

inline ostream& operator<<(ostream &o, const SteeringBehaviour &sb);

#endif
