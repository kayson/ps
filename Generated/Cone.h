#ifndef Cone_h
#define Cone_h

#include "Source.h"
#include "Vec.h"
#include <vector>

class Cone : public Source {

 public:
    Vec direction;
    std::vector< Particle* > spawnParticles(int life);
};

#endif // Cone_h
