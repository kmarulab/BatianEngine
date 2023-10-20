#include <assert.h>
#include "BatianEngine/include/batian/particle.h"

using namespace batian;

void Particle::integrate(real duration){
    //terminates when zero mass is encountered
    if (inverseMass <= 0.0f)return;

    assert(duration>0.0);

    //update linear position
    position.addScaledVector(velocity, duration);

    //acceleration from force
    Vector3 resultingAcc = acceleration;

    //velocity from acceleration
    velocity.addScaledVector(resultingAcc, duration);

    //drag
    velocity *= real_pow(damping, duration);

    clearAccumulator();

}