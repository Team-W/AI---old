#ifndef PLAYER_H
#define PLAYER_H

#include "Headers.h"
#include "GameEntity.h"

class Player: public GameEntity
{
    public:
        Player(double x, double y);
        ~Player(void);

        void Update(double delta_time);
        void Draw(double delta_time);
		void InitDraw();

        inline const Vector2D& GetVelocity(void) const;

    private:
        Vector2D velocity;

        friend ostream& operator<<(ostream &o, const Player &p);
};

ostream& operator<<(ostream &o, const Player &p);

inline const Vector2D& Player::GetVelocity(void) const
{
	return this->velocity;
}

#endif
