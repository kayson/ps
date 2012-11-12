#include "World.h"

void World::addSource(int type)
{
    if(type == 1){
        Explosion *s = new Explosion();
        s->position.x = 0;
        s->position.y = 0;
        s->position.z = 0;
        s->amplitude = 0.001;
        sourceVec.push_back(s);
    }
    else if(type == 2){
        Cone *s = new Cone();
        s->direction.x = 1;
        s->direction.y = 0;
        s->direction.z = 0;
        s->position.x = 0;
        s->position.y = 0;
        s->position.z = 0;
        s->amplitude = 0.01;
        sourceVec.push_back(s);
    }
}

void World::addForce(int type)
{
    if(type == 1){
        Wind *f = new Wind();
        f->position.x = 0;
        f->position.y = 0;
        f->position.z = 0;
        f->direction.x = -1;
        f->direction.y = 0;
        f->direction.z = 0;
        forceVec.push_back(f);
    }
    else if(type == 2){
        Gravity *f = new Gravity();
        f->position.x = 0;
        f->position.y = 0;
        f->position.z = 0;
        f->amplitude = 0.01;
        forceVec.push_back(f);
    }
}

void World::Render()
{
    for(unsigned int i = 0; i < sourceVec.size(); i++)
    {
      vector< Particle* > tempVec = sourceVec.at(i)->spawnParticles(400);
      particleVec.insert(particleVec.end(), tempVec.begin(), tempVec.end());
    }
    for(unsigned int i = 0; i < particleVec.size(); i++)
    {
        particleVec.at(i)->life--;
        if (particleVec.at(i)->life <= 0)
        {
            particleVec.erase(particleVec.begin()+i);
        }

        for(unsigned int j = 0; j < forceVec.size(); j++)
        {
            forceVec.at(j)->applyParticle(particleVec.at(i));
        }

        particleVec.at(i)->position.x += particleVec.at(i)->velocity.x;
        particleVec.at(i)->position.y += particleVec.at(i)->velocity.y;
        particleVec.at(i)->position.z += particleVec.at(i)->velocity.z;
    }

}

