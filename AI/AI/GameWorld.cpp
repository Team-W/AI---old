#include "GameWorld.h"

GameWorld::GameWorld(void)
{

}

GameWorld::~GameWorld(void)
{

}

void GameWorld::Update(double delta_time)
{

}

void GameWorld::AddObject(GameEntity *entity)
{

}

void GameWorld::RemoveObject(GameEntity *entity)
{

}

inline ostream& operator<<(ostream &o, const GameWorld &gw)
{
    o << "------------- GAME WORLD -------------" << "\n";

    o << "--------------------------------------" << endl;
    return o;
}
