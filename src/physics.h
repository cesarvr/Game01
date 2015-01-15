//
//  physics.h
//  BlockGame
//
//  Created by Cesar Luis Valdez on 20/10/14.
//  Copyright (c) 2014 Cesar Luis Valdez. All rights reserved.
//

#ifndef __BlockGame__physics__
#define __BlockGame__physics__

#include "mathla.h"

typedef struct {
    float           mass;
    float           force;
    mathc::Vector2  position;
    mathc::Vector2  velocity;
}Body;


class Physics {
    void ComputeForce();
public:
    Body CreateParticle(float x, float y, float mass);
    void EulerStep();
};

#endif /* defined(__BlockGame__physics__) */
