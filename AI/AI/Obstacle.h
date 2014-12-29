#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "Headers.h"
#include "GameEntity.h"

class Obstacle: public GameEntity
{
    public:
        Obstacle(double x, double y);
        ~Obstacle(void);

        void Update(double delta_time);
        void Draw(double delta_time);

    private:

        friend ostream& operator<<(ostream &o, const Obstacle &ob);
};

ostream& operator<<(ostream &o, const Obstacle &ob);

#endif
