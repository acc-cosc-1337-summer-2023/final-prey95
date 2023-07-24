#include <iostream>
#include <random>

using std::cout;

class Die {
public:
    void roll();
    int rolled_value() const{return roll_value;}
private:
    int roll_value;
    int sides{6};

};