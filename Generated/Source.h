#ifndef Source_h
#define Source_h

#include "Particle.h"
#include "Vec.h"
#include <vector>


class Source {

 public:

    virtual std::vector< Particle* > spawnParticles(int life)=0;
    ~Source();

 public:
    Vec position;
    double amplitude;
};

#endif // Source_h
