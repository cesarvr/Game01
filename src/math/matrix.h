//
//  matrix.h
//  CPluss
//
//  Created by Cesar Luis Valdez on 12/10/14.
//  Copyright (c) 2014 Cesar Luis Valdez. All rights reserved.
//

#ifndef __CPluss__matrix__
#define __CPluss__matrix__

#include <stdio.h>
#include <math.h>

namespace mathc {
    

class Matrix4 {
    float mm[16];
    
public:
    Matrix4();
    float *get_matrix();
    float&  operator[](int i);
    float   operator[](int i) const;
    
    static void ApplyTranslation(Matrix4& M, float x, float y, float z);
    static Matrix4 MakeRotateX(float rad);
    static Matrix4 MakeRotateY(float rad);
    static Matrix4 MakeRotateZ(float rad);
    
    static Matrix4 MakeOrthoProjection(float left, float right,
                                       float bottom, float top,
                                       float nearZ, float farZ);
    
};
    
    
}

mathc::Matrix4 operator*(const mathc::Matrix4& A, const mathc::Matrix4& B);



#endif /* defined(__CPluss__matrix__) */
