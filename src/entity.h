//
//  entity.h
//  BlockGame
//
//  Created by Cesar Luis Valdez on 13/10/14.
//  Copyright (c) 2014 Cesar Luis Valdez. All rights reserved.
//

#ifndef BlockGame_entity_h
#define BlockGame_entity_h

#include "common.h"
#include "shader.h"
#include <vector>

#define VERTEX_POSITION 3
#define VERTEX_COLOR 4
#define VERTEX_UV 2

typedef struct
{
    mathc::Matrix4 model;
    mathc::Matrix4 mvp;
}Transform;

typedef struct
{
    mathc::Vector3 position;
    mathc::Vector4 color;
    mathc::Vector2 texture;
}Geometry;

typedef struct
{
    GLuint vertex_buffer, index_buffer;
    int vertex_size, index_size;
    bool using_indices;
    GLenum mode;
    std::vector<Geometry> geometry;
    std::vector<short> indices;
    
}GLBuffers;

typedef struct
{
    GLBuffers  buffer;
    GLSLShader shader;
    Transform  transform;
}Entity;

#endif
