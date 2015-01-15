//
//  buffer.h
//  BlockGame
//
//  Created by Cesar Luis Valdez on 13/10/14.
//  Copyright (c) 2014 Cesar Luis Valdez. All rights reserved.
//

#ifndef __BlockGame__buffer__
#define __BlockGame__buffer__

#include "entity.h"


class BufferGPU {
    
public:
    static void UploadToGPU(GLBuffers& buffers, GLenum draw_type);
    static void ReleaseFromGPU(GLBuffers& buffers);
};

#endif /* defined(__BlockGame__buffer__) */
