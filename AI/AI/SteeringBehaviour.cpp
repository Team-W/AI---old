#include "SteeringBehaviour.h"

SteeringBehaviour::SteeringBehaviour(Zombie *z)
{
	owner = z;

	seek_on		= false;
	flee_on		= false;
	arrive_on	= false;

	result_seek(0, 0);
	result_flee(0, 0);
	result_arrive(0, 0);
	result_wander(0, 0);

	result_steering_force(0, 0);
	result_heading(0, 0);
	result_side(0, 0);
}

SteeringBehaviour::~SteeringBehaviour(void)
{
	result_steering_force = result_wander;
}

void SteeringBehaviour::Attach(Zombie *z)
{
	owner = z;
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

void SteeringBehaviour::Wander()
{
	int sign1 = (((float)rand()/RAND_MAX - 0.5)>0) ? 1:-1;
	int sign2 = (((float)rand()/RAND_MAX - 0.5)>0) ? 1:-1;
	
	Vector2D wander_target = owner->GetPosition();





	result_wander += Vector2D(sign1 * wander_circle_jitter, sign2 * wander_circle_jitter);
	result_wander.Normalize();
	result_wander *= wander_circle_radius;
	result_wander += Vector2D(wander_circle_distance, 0);








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
