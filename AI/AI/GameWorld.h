#ifndef GAME_WORLD_H
#define GAME_WORLD_H

#include "stdafx.h"
#include "GameEntity.h"

class GameEntity;

class GameWorld
{
    public:
        GameWorld(void);
        ~GameWorld(void);

        void Update(double delta_time);
        void AddObject(GameEntity *entity);
        void RemoveObject(GameEntity *entity);

    private:

        friend ostream& operator<<(ostream &o, const GameWorld &gw);
};

inline ostream& operator<<(ostream &o, const GameWorld &gw);

#endif
