//
//  vector.h
//  CPluss
//
//  Created by Cesar Luis Valdez on 12/10/14.
//  Copyright (c) 2014 Cesar Luis Valdez. All rights reserved.
//

#ifndef __CPluss__vector__
#define __CPluss__vector__

#include <stdio.h>
#include <math.h>

namespace mathc {


//===============================================================
//
// 2D vector
//
//===============================================================
class Vector2 {
    float V[2];
    
public:
    Vector2();
    Vector2(float x, float y);
    float*  get_vec2();
    float   Length();
    float&  operator[](int i);
    float   operator[](int i) const;
    Vector2 Nomalize();
    Vector2& operator+=(const Vector2& A);
    Vector2& operator-=(const Vector2& A);
    Vector2& operator*=(float scalar);
    
};



//===============================================================
//
// 3D vector
//
//===============================================================

class Vector3 {
    float V[3];

public:
    Vector3();
    Vector3(float x, float y, float z);
    float *get_vec3();
    float&  operator[](int i);
    float   operator[](int i) const;

};

//===============================================================
//
// 4D vector
//
//===============================================================

class Vector4 {
    float V[4];
    
public:
    Vector4();
    Vector4(float x, float y, float z, float w);
    float *get_vec4();
    float&  operator[](int i);
    float   operator[](int i) const;
    
};
}


mathc::Vector2 operator+(const mathc::Vector2& A, const mathc::Vector2& B);
mathc::Vector2 operator-(const mathc::Vector2& A, const mathc::Vector2& B);
mathc::Vector2 operator*(const mathc::Vector2& A, float scalar);



#endif /* defined(__CPluss__vector__) */
