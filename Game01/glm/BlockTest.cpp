//
//  BlockTest.cpp
//  EngineOne
//
//  Created by Cesar Luis Valdez on 12/11/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#include "BlockTest.h"

BlockTest::BlockTest(){};
BlockTest::BlockTest( CBackend *backend ){

    _camara = backend->getCamara();
    _shader = backend->getShader();
    _modelo = glm::mat4(1.0f);


};

 void  BlockTest::figuraGeometrica(float ancho , float alto, glm::vec3 color, TexturaUV_t textura){

    
    
    #define TEX_COORD_MAX   1.0f
    #define TEX_COORD_MIN   0.0f
    
     
     
     
     
    float vertx1 =  ancho;
    float vertx2 =  0.0;
    float verty1 =  0.0;
    float verty2 =  alto;
    
    float vertz1 =  0.0;
    //float vertz2 = -1.0;
    
     
     
    
     
   
    
    float vertices[]= {
        
        //0-3
        vertx1, verty1, vertz1, color.r, color.g, color.b, textura.uvx2, textura.uvy1, //0
        vertx2, verty1, vertz1, color.r, color.g, color.b, textura.uvx1, textura.uvy1, //1
        vertx1, verty2, vertz1, color.r, color.g, color.b, textura.uvx2, textura.uvy2, //2
        vertx2, verty2, vertz1, color.r, color.g, color.b, textura.uvx1, textura.uvy2, //3
        
    };
    
    
   // printf(" r: %f  g: %f  b: %f ", color.r, color.g, color.b);
    
    
    short indices[]={0,1,2,3,3};

    render  = Renderable(vertices, sizeof(vertices), indices, sizeof(indices));

    
};


void BlockTest::setPosicion( float x, float y ){
    
    _modelo = glm::translate(glm::mat4(1.0f), glm::vec3(x,y,0.0f));
    
}



void BlockTest::setPosicion( glm::vec2 posicion ){
    
    _modelo = glm::translate(glm::mat4(1.0f), glm::vec3(posicion.x,posicion.y,0.0f));
    
}

void BlockTest::draw(){

    render.render(_shader);

};

void BlockTest::update(){

   // _modelo = glm::rotate(_modelo, 1.0f, glm::vec3(0.0f,0.0f,1.0f));


    glm::mat4 mvp = ( *_camara ) * _modelo;
    
    render.setMVP(mvp);

};

