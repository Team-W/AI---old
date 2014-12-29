#ifndef STEERING_BEHAVIOUR_H
#define STEERING_BEHAVIOUR_H

#include "Vector2D.h"
#include "GameWorld.h"

class SteeringBehaviour
{
public:
	SteeringBehaviour(void);
	~SteeringBehaviour(void);

	Vector2D GetSteeringForce(void);
	Vector2D GetHeading(void);
	Vector2D GetSide(void);

	void ActivateSeek(bool on);
	void ActivateFlee(bool on);
	void ActivateArrive(bool on);

private:
	bool seek_on;
	bool flee_on;
	bool arrive_on;

	Vector2D result_seek;
	Vector2D result_flee;
	Vector2D result_arrive;

	Vector2D result_steering_force;
	Vector2D result_heading;
	Vector2D result_side;

	void CalculateSteeringForce(void);
	void CalculateHeading(void);
	void CalculateSide(void);

	void Seek(Vector2D &v);
	void Flee(Vector2D &v);
	void Arrive(Vector2D &v);

	friend ostream& operator<<(ostream &o, const SteeringBehaviour &sb);
};

ostream& operator<<(ostream &o, const SteeringBehaviour &sb);

inline void SteeringBehaviour::ActivateSeek(bool on)
{

}

inline void SteeringBehaviour::ActivateFlee(bool on)
{

}

inline void SteeringBehaviour::ActivateArrive(bool on)
{

}

#endif
