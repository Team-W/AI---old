#ifndef PLAYER_H
#define PLAYER_H

#include "stdafx.h"
#include "GameEntity.h"

class Player: public GameEntity
{
    public:
        Player(double x, double y);
        ~Player(void);

        void Update(double delta_time);
        void Draw(double delta_time);

        inline Vector2D GetVelocity(void) const;

    private:
        Vector2D velocity;      // wektor predkosci

        friend ostream& operator<<(ostream &o, const Player &p);
};

inline ostream& operator<<(ostream &o, const Player &p);

#endif
