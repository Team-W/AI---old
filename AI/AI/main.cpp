#include <iostream>
using namespace std;

#include "Vector2D.cpp"
#include "GameEntity.cpp"
#include "Zombie.cpp"
#include "Obstacle.cpp"
#include "Player.cpp"
#include "GameWorld.cpp"
#include "SteeringBehaviour.cpp"

int main()
{
    Zombie z1(1, 2);
    Zombie z2(2, 2);
    Zombie z3(3, 2);
    cout << z3 << endl;
}

