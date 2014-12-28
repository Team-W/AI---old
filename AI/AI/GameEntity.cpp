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

inline int GameEntity::GetID(void) const
{
    return this->id;
}

inline Vector2D GameEntity::GetPosition(void) const
{
    return this->position;
}

inline Vector2D GameEntity::GetHeading(void) const
{
    return this->heading;
}

inline Vector2D GameEntity::GetSide(void) const
{
    return this->side;
}

inline double GameEntity::GetCollisionRadius(void) const
{
    return this->collision_radius;
}

inline void GameEntity::SetCollisionRadius(double d)
{
    if(d > 0) this->collision_radius = d;
}
