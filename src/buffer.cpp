//
//  buffer.cpp
//  BlockGame
//
//  Created by Cesar Luis Valdez on 13/10/14.
//  Copyright (c) 2014 Cesar Luis Valdez. All rights reserved.
//

#include "buffer.h"

void BufferGPU::UploadToGPU(GLBuffers &buffers, GLenum draw_type) {
    
  //  float vsize = buffers.geometry.size() * sizeof(float);
    glGenBuffers(1, &buffers.vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffers.vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(buffers.geometry), &buffers.geometry[0], draw_type);
    
    if (buffers.using_indices) {
      //  float isize = buffers.indices.size() * sizeof(short);
        glGenBuffers(1, &buffers.index_buffer);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers.index_buffer);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(buffers.indices), &buffers.indices[0], draw_type);
    }
}

void BufferGPU::ReleaseFromGPU(GLBuffers &buffers) {
    glDeleteBuffers(1, &buffers.vertex_buffer);
    if (buffers.using_indices)
        glDeleteBuffers(1, &buffers.index_buffer);
}