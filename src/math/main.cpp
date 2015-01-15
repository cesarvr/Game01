//
//  main.cpp
//  CPluss
//
//  Created by Cesar Luis Valdez on 11/10/14.
//  Copyright (c) 2014 Cesar Luis Valdez. All rights reserved.
//

#include <iostream>
#include <memory.h>
#include "mathla.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

using namespace mathc;

void show_raw_matrix(float *M) {

    printf("\n\n");
    
    for (int x= 0; x<16; x++) {
        if (x!=0 && (x % 4) == 0) {
            printf("\n");
        }
        printf(" %f ", M[x]);
        
    }
}
void show_matrix(mathc::Matrix4 &M){
   
    for (int y=0; y<4; y++){
        printf("\n");
        for (int x= 0; x<4; x++) {
            printf(" %f ", M[4*y+x]);
            
        }
    }
        printf("\n\n");

        for (int x= 0; x<16; x++) {
            if (x!=0 && (x % 4) == 0) {
                printf("\n");
            }
            printf(" %f ", M[x]);
            
        }
    
     printf("\n");
}
void Vector_Test(){

    mathc::Vector2 x(1,1);
    mathc::Vector2 y(2,2);
    mathc::Vector2 z(3,3);
    
    mathc::Vector2 r = x+y+(z * 0.015f);
    
    mathc::Vector3 v3(1.0f,2.0f,3.0f);
    
    printf("x:%f y:%f \n", r[0], r[1]);
    printf("x:%f y:%f \n", r.get_vec2()[0], r.get_vec2()[1]);
    
    r = r.Nomalize();
    printf("x:%f y:%f \n", r.get_vec2()[0], r.get_vec2()[1]);
    
    printf(" vec3 -> x:%f y:%f z:%f \n", v3[0], v3[1], v3[2]);

}

void Matrix_Test() {

    mathc::Matrix4 m;
    mathc::Matrix4::ApplyTranslation(m, 10, 10, 0);
    mathc::Matrix4 cam = mathc::Matrix4::MakeOrthoProjection(0, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 1, -1);

    mathc::Matrix4 mvp = cam * m;
    
    show_matrix(mvp);

    
    
}

int main(int argc, const char * argv[]) {
    Matrix_Test();
    return 0;
}
