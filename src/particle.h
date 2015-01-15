//
//  particle.h
//  BlockGame
//
//  Created by Cesar Luis Valdez on 13/10/14.
//  Copyright (c) 2014 Cesar Luis Valdez. All rights reserved.
//

#ifndef __BlockGame__particle__
#define __BlockGame__particle__

#include <stdio.h>

#include "entity.h"
#include "buffer.h"

class Particle {
    void InitShader();
    void InitGeometry();
    Entity CreateEntity(float x, float y, float size);
    
    GLBuffers bufferz;
    GLSLShader particle_shader;
    vector<Entity> entities;
    
public:
    
    ~Particle();
    void Init();
    void Update(mathc::Matrix4& camera);
    void Clean();
    vector<Entity>& get_entities();
};


#endif /* defined(__BlockGame__particle__) */
