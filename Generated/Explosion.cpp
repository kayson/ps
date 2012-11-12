#include "Explosion.h"
#include <iostream>
#include <cstdlib>

std::vector< Particle* > Explosion::spawnParticles(int life)
{
    std::vector< Particle* > tempVec;
    for (int i=0;i<100;i++){
        Particle *p = new Particle();
        p->position.x = position.x;
        p->position.y = position.y;
        p->position.z = position.z;
        p->life = life;
        double rng1 = rand()%40;
        double rng2 = rand()%40;
        double rng3 = rand()%40;
        p->velocity.x = amplitude*rng1;
        p->velocity.y = amplitude*rng2;
        p->velocity.z = amplitude*rng3;
        tempVec.push_back(p);
    }
    return tempVec;

}
