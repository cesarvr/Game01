//
//  render.cpp
//  PuzzleGame
//
//  Created by Cesar Luis Valdez on 22/09/14.
//  Copyright (c) 2014 Cesar Luis Valdez. All rights reserved.
//

#include "render.h"

Render::Render() {
    stride = sizeof(Geometry);
}
void Render::Clean(float r, float g, float b, float a) {
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Render::DoRender( Entity &entity) {

    
    GLBuffers   &buffer = entity.buffer;
    GLSLShader  &shader = entity.shader;
    Transform   &tform  = entity.transform;
    shader.Use();
    
    glUniformMatrix4fv(shader("mv"),
                       1,
                       GL_FALSE,
                       tform.mvp.get_matrix());
    
    glBindBuffer(GL_ARRAY_BUFFER, buffer.vertex_buffer);
  
    
    glVertexAttribPointer(shader["posicion"],
                          VERTEX_POSITION,
                          GL_FLOAT,
                          GL_FALSE,
                          stride,
                          0);
    glEnableVertexAttribArray(shader["posicion"]);
    GL_CHECK_ERROR();
    glVertexAttribPointer(shader["color"],
                          VERTEX_COLOR,
                          GL_FLOAT,
                          GL_FALSE,
                          stride,
                          (const GLvoid*)offsetof(Geometry, color));
    glEnableVertexAttribArray(shader["color"]);
    GL_CHECK_ERROR();
    glVertexAttribPointer(shader["textura_uv"],
                          VERTEX_UV,
                          GL_FLOAT,
                          GL_FALSE,
                          stride,
                          (const GLvoid*)offsetof(Geometry, texture));
    glEnableVertexAttribArray(shader["textura_uv"]);
    GL_CHECK_ERROR();
    //Usamos indices
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer.index_buffer);
   
    
    if (buffer.using_indices) {
        glDrawElements(buffer.mode,
                       (int)buffer.indices.size(),
                       GL_UNSIGNED_SHORT, 0);
    }else{
        glDrawArrays(buffer.mode,
                     0,
                     (int)buffer.geometry.size());
    }
    
    
    
    
    shader.UnUse();
}