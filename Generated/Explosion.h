#ifndef Explosion_h
#define Explosion_h

#include "Source.h"
#include <vector>

class Explosion : public Source {

    public:
        std::vector< Particle* > spawnParticles(int life);
};



#endif // Explosion_h
