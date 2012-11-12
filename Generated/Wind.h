#ifndef Wind_h
#define Wind_h

#include "Force.h"
#include "Vec.h"


class Wind : public Force {

 public:
    Vec direction;
    void applyParticle(Particle *p);
};

#endif // Wind_h
