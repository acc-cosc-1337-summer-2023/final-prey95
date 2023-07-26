#include "die.h"
#include "roll.h"

#ifndef SHOOTER_H
#define SHOOTER_H

class Shooter{
public:
    Roll* throw_die(Die& die1, Die& die2);
    ~Shooter();
    friend ostream& operator<<(ostream& os, const Shooter& shoot);

private:
    vector<Roll*> rolls;
};

#endif