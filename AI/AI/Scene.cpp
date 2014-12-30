#include "Scene.h"

Scene::Scene(void)
{

}

Scene::~Scene(void)
{

}

void Scene::Draw(double delta_time)
{
	for (int i = 0; i < objects.size(); i++)
	{
		objects[i]->Update(delta_time);
		objects[i]->Draw(delta_time);
	}
}

void Scene::InitDraw(void)
{
	for (int i = 0; i < objects.size(); i++)
	{
		objects[i]->InitDraw();
	}
}

void Scene::AddObject(GameEntity *entity)
{
	objects.push_back(entity);
}

void Scene::RemoveObject(GameEntity *entity)
{
	
}

ostream& operator<<(ostream &o, const Scene &gw)
{
	o << "---------------- SCENE ---------------" << "\n";

	o << "--------------------------------------" << endl;
	return o;
}
