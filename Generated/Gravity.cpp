#include "Gravity.h"

void Gravity::applyParticle(Particle *p)
{
    p->velocity.y -= amplitude;
}
