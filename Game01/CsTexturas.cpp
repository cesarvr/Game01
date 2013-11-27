//
//  CsTexturas.cpp
//  Game01
//
//  Created by Cesar Luis Valdez on 25/11/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#include "CsTexturas.h"

void CsTexturas::cargarTexturas(){

    
    std::vector<unsigned char> image;
    
    
    std::string pathFicheroImagen(TEXTURA);
 
    unsigned error = lodepng::decode(image, width, height, pathFicheroImagen);

    
    // If there's an error, display it.
    if(error != 0)
    {
        std::cout << "error " << error << ": " << lodepng_error_text(error) << std::endl;
        
    }
    
    glGenTextures(1, &texturaId);
    glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texturaId);
    
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &image[0]);
    
    GLenum err = glGetError();
    if (err != GL_NO_ERROR)
        std::cout << "Error uploading texture. glError: 0x%04X" << err << std::endl;


}