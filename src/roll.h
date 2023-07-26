#include "die.h"

#ifndef ROLL_H
#define ROLL_H

class Roll{
public:
    Roll() : die1(1), die2(2) {;}
    void roll_die();
    int roll_value() const {return value;}
private:
    Die die1;
    Die die2;
    bool rolled = false;
    int value = die1.rolled_value() + die2.rolled_value();
};

#endif