#include "Cone.h"


std::vector< Particle* > Cone::spawnParticles(int life)
{
    std::vector< Particle* > tempVec;
    for (int i=0;i<100;i++){
        Particle *p = new Particle();
        p->position.x = position.x;
        p->position.y = position.y;
        p->life = life;
        p->velocity.x = amplitude*direction.x;
        p->velocity.y = amplitude*direction.y;
        tempVec.push_back(p);
    }
    return tempVec;
}
