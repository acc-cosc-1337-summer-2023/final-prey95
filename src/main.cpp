#include "die.h"
#include "roll.h"

int main() 
{
	Roll myRoll;

	myRoll.roll_die();
	int num = myRoll.roll_value();

	cout << num << "\n";

	return 0;
}