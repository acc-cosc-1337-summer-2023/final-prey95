#include "die.h"

int main() 
{
	Die die;
	int num;

	die.roll();
	num = die.rolled_value();
	cout << num << "\n";

	return 0;
}