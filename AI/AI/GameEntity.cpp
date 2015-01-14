#include "GameEntity.h"

int GameEntity::next_id = 0;

GameEntity::GameEntity(void):
    id(next_id++),
    game_world(0),
    collision_radius(0)
{
	view_matrix = glm::lookAt(glm::vec3(0.f, 0.f, 1.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 1.f, 0.f));
	model_matrix = glm::mat4(1.0f);
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

void GameEntity::Rotate(float degrees, glm::vec3 axis)
{
	model_matrix = glm::rotate(model_matrix, degrees, axis);
}

void GameEntity::Translate(glm::vec3 vector)
{
	model_matrix = glm::translate(model_matrix, vector);
}

void GameEntity::Scale(glm::vec3 vector)
{
	model_matrix = glm::scale(model_matrix, vector);
}
void GameEntity::getMatrix(GLfloat(&arr)[16])
{
	glm::mat4 modelview = view_matrix * model_matrix;
	for (int i = 0; i < 4; i++){
		arr[i] = modelview[i][0];
		arr[i+1] = modelview[i][1];
		arr[i+2] = modelview[i][2];
		arr[i+3] = modelview[i][3];
	}
}