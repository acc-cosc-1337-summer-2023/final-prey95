#include "shooter.h"

Roll* Shooter::throw_die(Die& die1, Die& die2){
    Roll* myRoll = new Roll();
    myRoll->roll_die();
    rolls.push_back(myRoll);

    return myRoll;
}

Shooter::~Shooter(){

    for(Roll* myRoll: rolls){
        delete myRoll;
    }
}

ostream& operator<<(ostream& out, const Shooter& shoot){
    
    for(Roll* myRoll : shoot.rolls){
        out << myRoll->roll_value() << "\n";
    }

    return out;
}

