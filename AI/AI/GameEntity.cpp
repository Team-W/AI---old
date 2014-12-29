#include "GameEntity.h"

int GameEntity::next_id = 0;

GameEntity::GameEntity(void):
    id(next_id++),
    game_world(0),
    collision_radius(0)
{

}

GameEntity::~GameEntity(void)
{

}

void GameEntity::AttachToGameWorld(GameWorld *gw)
{
    if(game_world != 0)
    {
        game_world->RemoveObject(this);
    }

    game_world = gw;

    if(gw != 0)
    {
        game_world->AddObject(this);
    }
}