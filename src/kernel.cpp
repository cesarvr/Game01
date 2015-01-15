//
//  kernel.cpp
//  BlockGame
//
//  Created by Cesar Luis Valdez on 13/10/14.
//  Copyright (c) 2014 Cesar Luis Valdez. All rights reserved.
//

#include "kernel.h"


Kernel::~Kernel() {
    printf("releasing resources\n");
    particle.Clean();
}

void Kernel::Init() {
    particle.Init();
    camera = mathc::Matrix4::MakeOrthoProjection(0, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 1, -1);
    state = running;
}

void Kernel::SetState(Kernel::GState _state){
    state =_state;
}

void Kernel::Render() {
    if (state == stop) return;
    
    renderer.Clean();
    for(Entity e: particle.get_entities())
        renderer.DoRender(e);
    
}

void Kernel::Update() {
     if (state == stop) return;
    particle.Update(camera);
    
}