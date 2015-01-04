#include "SteeringBehaviour.h"

SteeringBehaviour::SteeringBehaviour(Zombie *z)
{
	owner = z;

	seek_on		= false;
	flee_on		= false;
	arrive_on	= false;
	wander_on	= false;

	target_seek(0, 0);
	target_flee(0, 0);
	target_arrive(0, 0);
	

	result_steering_force(0, 0);
	result_heading(0, 0);
	result_side(0, 0);

	// ---------- WANDER INIT ---------- //
	wander_radius	= 1.2;
	wander_distance	= 2.0;
	wander_jitter	= 0.80;

	float alpha = (float)(rand()%360) * PI/180.0f;
	target_wander(wander_radius*cos(alpha), wander_radius*sin(alpha));
	//cout << target_wander;
}

SteeringBehaviour::~SteeringBehaviour(void)
{
	
}

void SteeringBehaviour::Attach(Zombie *z)
{
	owner = z;
}

Vector2D SteeringBehaviour::GetSteeringForce(void)
{
	Wander();
	result_steering_force(force_wander.GetX(), force_wander.GetY());
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
	//cout << target_wander << ": " << sign1 << " , " << sign2 << "\n";

	target_wander += Vector2D((double)sign1 * wander_jitter, (double)sign2 * wander_jitter);
	target_wander.Normalize();
	target_wander *= wander_radius;
	//cout << target_wander;
	Vector2D target_local = target_wander + Vector2D(0, wander_distance);
	//Vector2D directon = Vector2D(0, wander_distance);
	
	//double angle = acos(target_local.Dot(directon) / (target_local.Length()*directon.Length()));
	// tutaj trzeba zrobiEwszystkie rotacje/translacje/skalowania aby uzyskaEpunkt we wspó³rzêdnych œwiata
	//Vector2D target_world = target_local;// + owner->GetPosition();
	cout << target_local;
	system("pause");

	force_wander = target_local;// -owner->GetPosition();
}

ostream& operator<<(ostream &o, const SteeringBehaviour &sb)
{
    o << " * STEERING BEHAVIOUR:" << "\n";
	o << "Seek\t\t["	<< (sb.seek_on		?	"on":"off")		<< "]\t" << sb.target_seek		<< "\n";
	o << "Flee\t\t["	<< (sb.flee_on		?	"on":"off")		<< "]\t" << sb.target_flee		<< "\n";
	o << "Arrive\t\t["	<< (sb.arrive_on	?	"on":"off")		<< "]\t" << sb.target_arrive	<< "\n";
	o << "Wander\t\t["	<< (sb.wander_on	?	"on":"off")		<< "]\t" << sb.force_wander		<< "\n";
	o << "\n";
	o << "Force\t\t"	<< sb.result_steering_force												<< "\n";
	o << "Heading\t\t"	<< sb.result_heading													<< "\n";
	o << "Side\t\t"		<< sb.result_side														<< "\n";
    return o;
}
