#ifndef Gravity_h
#define Gravity_h

#include "Force.h"


class Gravity : public Force {

 public:
    double amplitude;
    void applyParticle(Particle *p);
};

#endif // Gravity_h
