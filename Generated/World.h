#ifndef World_h
#define World_h

#include <vector>
#include "Force.h"
#include "Particle.h"
#include "Source.h"
#include "Cone.h"
#include "Wind.h"
#include "Gravity.h"
#include "Explosion.h"

#include <iostream>

using namespace std;

class World {

 public:
    void virtual addSource(int type);

    void virtual addForce(int type);

    virtual void Render();

 public:
    vector< Source* > sourceVec;
    vector< Force* > forceVec;
    vector< Particle* > particleVec;

};

#endif // World_h
