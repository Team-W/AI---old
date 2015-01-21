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

	// ---------- WANDER INIT ---------- //
	wander_radius	= 2.0;
	wander_distance	= 3.0;
	wander_jitter	= 1.0;

	float alpha = (float)(rand()%360) * PI/180.0f;
	target_wander(wander_radius*cos(alpha), wander_radius*sin(alpha));
	//cout << target_wander;
	srand(time(NULL));
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
	//Seek(Vector2D(10,20));
	//Flee(Vector2D(1, -1));

	result_steering_force = force_wander;

	return this->result_steering_force;
}

void SteeringBehaviour::CalculateSteeringForce(void)
{

}

void SteeringBehaviour::Seek(Vector2D &v)
{
	Vector2D desired_velocity = v - owner->GetPosition();
	desired_velocity.Normalize();
	desired_velocity = desired_velocity * ZOMBIE_MAX_SPEED;	
	
	force_wander = desired_velocity - owner->GetVelocity();
}

void SteeringBehaviour::Flee(Vector2D &v)
{
	Vector2D desired_velocity = owner->GetPosition(); 

	if (owner->GetPosition().DistanceSqrt(v) < 100){
		desired_velocity = desired_velocity - v;
		desired_velocity.Normalize();
		desired_velocity = desired_velocity * ZOMBIE_MAX_SPEED;
		force_wander = desired_velocity - owner->GetVelocity();
	}else{
		force_wander = Vector2D(0, 0);
	}

	//cout << force_wander;
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

	Vector2D target_local = target_wander + Vector2D(0, wander_distance);
	
	// tutaj trzeba zrobiEwszystkie rotacje/translacje/skalowania aby uzyskaEpunkt we wspó³rzêdnych œwiata
	Vector2D target_world = target_local + owner->GetPosition();
	//cout << target_local;
	//system("pause");
	force_wander = target_world-owner->GetPosition();// -owner->GetPosition();
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
    return o;
}
