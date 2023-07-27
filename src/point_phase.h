#include "phase.h"

#ifndef POINT_PHASE_H
#define POINT_PHASE_H

class PointPhase : public Phase{
public:
    PointPhase(int p){point = p;}
    RollOutcome get_outcome(Roll* roll) override;

private:
    int point;
};

#endif