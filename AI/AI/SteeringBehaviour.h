#ifndef STEERING_BEHAVIOUR_H
#define STEERING_BEHAVIOUR_H

#include "Vector2D.h"
#include "GameWorld.h"
#include "Zombie.h"

class Zombie;

class SteeringBehaviour
{
public:
	SteeringBehaviour(Zombie *z);
	~SteeringBehaviour(void);

	void Attach(Zombie *z);

	Vector2D GetSteeringForce(void);
	Vector2D GetHeading(void);
	Vector2D GetSide(void);

	void ActivateSeek(bool on);
	void ActivateFlee(bool on);
	void ActivateArrive(bool on);

private:
	Zombie *owner;

	double wander_circle_radius = 1.0;
	double wander_circle_distance = 1.0;
	double wander_circle_jitter = 1.0;

	bool seek_on;
	bool flee_on;
	bool arrive_on;

	Vector2D result_seek;
	Vector2D result_flee;
	Vector2D result_arrive;
	Vector2D result_wander;

	Vector2D result_steering_force;
	Vector2D result_heading;
	Vector2D result_side;

	void CalculateSteeringForce(void);
	void CalculateHeading(void);
	void CalculateSide(void);

	void Seek(Vector2D &v);
	void Flee(Vector2D &v);
	void Arrive(Vector2D &v);
	void Wander();

	friend ostream& operator<<(ostream &o, const SteeringBehaviour &sb);
};

ostream& operator<<(ostream &o, const SteeringBehaviour &sb);

inline void SteeringBehaviour::ActivateSeek(bool on)
{
	this->seek_on = on;
}

inline void SteeringBehaviour::ActivateFlee(bool on)
{
	this->flee_on = on;
}

inline void SteeringBehaviour::ActivateArrive(bool on)
{
	this->arrive_on = on;
}

#endif
