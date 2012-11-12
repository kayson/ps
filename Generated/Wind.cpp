#include "Wind.h"

void Wind::applyParticle(Particle *p)
{
    p->velocity.x += direction.x;
    p->velocity.y += direction.y;
    p->velocity.z += direction.z;
}
