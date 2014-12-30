#ifndef SCENE_H
#define SCENE_H

#include "Headers.h"
#include "GameEntity.h"

class GameEntity;

class Scene
{
public:
	Scene(void);
	~Scene(void);

	void Draw(double delta_time);
	void InitDraw(void);
	void AddObject(GameEntity *entity);
	void RemoveObject(GameEntity *entity);

private:
	vector<GameEntity*> objects;
	friend ostream& operator<<(ostream &o, const GameWorld &gw);
};

ostream& operator<<(ostream &o, const GameWorld &gw);

#endif
