#pragma once
#include "core.h"

//particles happen to be the simplest objects that can be simulated

namespace batian{
    class Particle{
    public:

    protected:
        Vector3 position; //linear position in space
        Vector3 velocity; //linear velocity in space
        Vector3 acceleration; //any constant acceleration, of value however in most cases is gravity

        //Newton's Laws of Motion
        //First Law: Object continues in initial state of motion unless acted upon by an external force
        //First law is best described by inertial reference frames
        //Second Law: Force acting on a body will produce an acceleration proportional to its mass

        // this will act as our drag force. Have numerical instability in integrator, the velocity one
        //ideally btwn 0 and 1, with 0.99 preferred. At 0, no motion, at 1, object moves forever
        real damping;

        //makes integration simpler where we have acceleration and force
        //a=(1/m)f force is a vector
        real mass;
        real inverseMass;
        
    public:
        void setInverseMass(const real inverseMass);
        void integrate(real duration);
        void setMass(const real mass);
        void setDamping(const real damping);

        real getMass() const;
        real getInverseMass() const;
        real getDamping() const;

        void clearAccumulator();


    };

}
