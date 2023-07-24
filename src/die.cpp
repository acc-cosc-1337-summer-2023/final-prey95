#include "die.h"

void Die::roll(){

    std::random_device engine; 
    std::uniform_int_distribution<int> distrib(1, 6);

    roll_value = distrib(engine);
}