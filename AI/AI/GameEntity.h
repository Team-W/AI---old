#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H

#include "stdafx.h"
#include "Vector2D.h"
#include "GameWorld.h"

class GameWorld;

class GameEntity
{
    public:
        GameEntity(void);
        virtual ~GameEntity(void);

        virtual void Update(double delta_time) = 0;
        virtual void Draw(double delta_time) = 0;

        void AttachToGameWorld(GameWorld *gw);

        inline int GetID(void) const;
        inline Vector2D GetPosition(void) const;
        inline Vector2D GetHeading(void) const;
        inline Vector2D GetSide(void) const;
        inline double GetCollisionRadius(void) const;
        inline void SetCollisionRadius(double d);

    protected:
        const int id;
        static int next_id;

        GameWorld *game_world;

        Vector2D position;      // pozycja w swiecie gry
        Vector2D heading;       // wektor kierunku (orientacja)
        Vector2D side;          // wektor prostopadly do wektora kierunku

        double collision_radius;
};

#endif
