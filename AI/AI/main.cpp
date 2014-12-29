#include "Headers.h"

#include "Zombie.h"

int main(int argc, char **argv)
{
	Zombie z(2, 1);
	Zombie z2(1,1);
	z = z2;
	cout << z << endl;

	system("pause");
}