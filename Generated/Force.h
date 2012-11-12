#ifndef Force_h
#define Force_h

#include "Vec.h"
#include "Particle.h"

class Force  {

 public:
    Vec position;

 public:
    virtual void applyParticle(Particle *p)=0;
    ~Force();
};

#endif // Force_h
