//
//  render.h
//  PuzzleGame
//
//  Created by Cesar Luis Valdez on 22/09/14.
//  Copyright (c) 2014 Cesar Luis Valdez. All rights reserved.
//

#ifndef __PuzzleGame__render__
#define __PuzzleGame__render__

#include "common.h"
#include "entity.h"

class Render {
    GLsizei stride;
public:
    Render();
    void Clean(float r=0, float g=0, float b=0, float a=0);
    void DoRender(Entity& entity);
};


#endif /* defined(__PuzzleGame__render__) */
