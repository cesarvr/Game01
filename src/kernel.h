//
//  kernel.h
//  BlockGame
//
//  Created by Cesar Luis Valdez on 13/10/14.
//  Copyright (c) 2014 Cesar Luis Valdez. All rights reserved.
//

#ifndef __BlockGame__kernel__
#define __BlockGame__kernel__

#include "particle.h"
#include "render.h"


class Kernel {

public:
    enum GState {running, stop, sleep};
    
    ~Kernel();
    void Init();
    void Render();
    void Update();
    void SetState(GState state);
    
private:
    Particle particle;
    class Render renderer;
    mathc::Matrix4 camera;
    GState state;
};

#endif /* defined(__BlockGame__kernel__) */
