#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "Headers.h"
#include "GameEntity.h"

class Obstacle: public GameEntity
{
    public:
		Obstacle();
        Obstacle(double x, double y, double rad);
        ~Obstacle(void);

        void Update(double delta_time);
        void Draw(double delta_time);
		void InitDraw(void);

    private:
		double radius;
        friend ostream& operator<<(ostream &o, const Obstacle &ob);
};

ostream& operator<<(ostream &o, const Obstacle &ob);

#endif
