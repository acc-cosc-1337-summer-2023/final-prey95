#include "die.h"
#include "roll.h"
#include "shooter.h"
#include "phase.h"
#include "come_out_phase.h"
#include "point_phase.h"

int main() 
{
	Shooter shoot;
	Die die1(1), die2(2);
	shoot.throw_die(die1, die2);

	cout << shoot;

	Shooter shoot1;
	shoot1.throw_die(die1, die2);

	cout << shoot1;
	cout << "--------------------" << "\n";


	return 0;
}