#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H

#include "Headers.h"
#include "Vector2D.h"
#include "GameWorld.h"

class GameWorld;

class GameEntity
{
    public:
        GameEntity(void);
        virtual ~GameEntity(void);

		glm::mat4 model_matrix;
		glm::mat4 view_matrix;

        virtual void Update(double delta_time) = 0;
        virtual void Draw(double delta_time) = 0;
		virtual void InitDraw(void) = 0;

		void Rotate(float degrees, glm::vec3 axis);
		void Translate(glm::vec3 vector);
		void Scale(glm::vec3 vector);
		void getMatrix(GLfloat arr[16]);

		void AttachToGameWorld(GameWorld *gw);
		 

        int GetID(void) const;
        const Vector2D& GetPosition(void) const;
		const Vector2D& GetHeading(void) const;
		const Vector2D& GetSide(void) const;
        double GetCollisionRadius(void) const;
        void SetCollisionRadius(double d);

    protected:
        int id;
        static int next_id;

        GameWorld *game_world;

        Vector2D position;      // pozycja w swiecie gry
        Vector2D heading;       // wektor kierunku (orientacja)
        Vector2D side;          // wektor prostopadly do wektora kierunku

        double collision_radius;
};

inline int GameEntity::GetID(void) const
{
	return this->id;
}

inline const Vector2D& GameEntity::GetPosition(void) const
{
	return this->position;
}

inline const Vector2D& GameEntity::GetHeading(void) const
{
	return this->heading;
}

inline const Vector2D& GameEntity::GetSide(void) const
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

#endif
