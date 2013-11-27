//
//  CCamara.h
//  Game01
//
//  Created by Cesar Luis Valdez on 25/11/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#ifndef __Game01__CCamara__
#define __Game01__CCamara__

#include <iostream>

#include "CCamara.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"


using namespace glm;

class CvCamara {
    mat4 matCamara;
    
public:
    
    CvCamara();
    mat4 getMatCamara();
    
    
};


#endif /* defined(__Game01__CCamara__) */
