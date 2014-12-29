#include "SteeringBehaviour.h"

SteeringBehaviour::SteeringBehaviour(void)
{
	seek_on		= false;
	flee_on		= false;
	arrive_on	= false;

	result_seek(0, 0);
	result_flee(0, 0);
	result_arrive(0, 0);

	result_steering_force(0, 0);
	result_heading(0, 0);
	result_side(0, 0);
}

SteeringBehaviour::~SteeringBehaviour(void)
{

}

Vector2D SteeringBehaviour::GetSteeringForce(void)
{
	return this->result_steering_force;
}

Vector2D SteeringBehaviour::GetHeading(void)
{
	return this->result_heading;
}

Vector2D SteeringBehaviour::GetSide(void)
{
	return this->result_side;
}

inline void SteeringBehaviour::ActivateSeek(bool on)
{

}

inline void SteeringBehaviour::ActivateFlee(bool on)
{

}

inline void SteeringBehaviour::ActivateArrive(bool on)
{

}

void SteeringBehaviour::CalculateSteeringForce(void)
{

}

void SteeringBehaviour::CalculateHeading(void)
{

}

void SteeringBehaviour::CalculateSide(void)
{

}

void SteeringBehaviour::Seek(Vector2D &v)
{

}

void SteeringBehaviour::Flee(Vector2D &v)
{

}

void SteeringBehaviour::Arrive(Vector2D &v)
{

}

ostream& operator<<(ostream &o, const SteeringBehaviour &sb)
{
    o << " * STEERING BEHAVIOUR:" << "\n";
	o << "Seek\t\t["	<< (sb.seek_on		?	"on":"off")		<< "]\t" << sb.result_seek		<< "\n";
	o << "Flee\t\t["	<< (sb.flee_on		?	"on":"off")		<< "]\t" << sb.result_flee		<< "\n";
	o << "Arrive\t\t["	<< (sb.arrive_on	?	"on":"off")		<< "]\t" << sb.result_arrive	<< "\n";
	o << "\n";
	o << "Force\t\t"	<< sb.result_steering_force												<< "\n";
	o << "Heading\t\t"	<< sb.result_heading													<< "\n";
	o << "Side\t\t"		<< sb.result_side														<< "\n";
    return o;
}
