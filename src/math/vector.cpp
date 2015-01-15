//
//  vector.cpp
//  CPluss
//
//  Created by Cesar Luis Valdez on 12/10/14.
//  Copyright (c) 2014 Cesar Luis Valdez. All rights reserved.
//

#include "vector.h"

using namespace mathc;
//===============================================================
//
// 2D vector
//
//===============================================================

Vector2::Vector2() {
    V[0] = 0.0f;
    V[0] = 0.0f;
}

Vector2::Vector2(float x, float y) {
    V[0] = x;
    V[1] = y;
}

float* Vector2::get_vec2() {
    return V;
}

float Vector2::operator[](int i) const {
    return V[i];
}
float& Vector2::operator[](int i) {
    return V[i];
}

Vector2 Vector2::Nomalize() {
    float l = this->Length();
    return Vector2(V[0]/l, V[1]/l);
}

float Vector2::Length() {
    return sqrtf(V[0] * V[0] + V[1] * V[1]);
}


Vector2& Vector2::operator*=(float scalar) {
    V[0]*=scalar;
    V[1]*=scalar;
    return *this;
}

Vector2& Vector2::operator+=(const Vector2& A) {
    V[0]+=A[0];
    V[1]+=A[1];
    return *this;
}

Vector2& Vector2::operator-=(const Vector2& A) {
    V[0]-=A[0];
    V[1]-=A[1];
    return *this;
}

Vector2 operator+(const Vector2& A, const Vector2& B) {
    Vector2 R{A};
    return R+=B;
}

Vector2 operator-(const Vector2& A, const Vector2& B) {
    Vector2 R{A};
    return R-=B;
}

Vector2 operator*(const Vector2& A, float scalar) {
    Vector2 R{A};
    return R*=scalar;
}

//===============================================================
//
// 3D vector
//
//===============================================================

Vector3::Vector3() {
    V[0] = V[1] = V[2] = 0.0f;
}

Vector3::Vector3(float x, float y, float z) {
    V[0]=x; V[1]=y; V[2]=z;
}

float* Vector3::get_vec3() {
    return V;
}

float& Vector3::operator[](int i) {
    return V[i];
}

float Vector3::operator[](int i) const {
    return V[i];
}


//===============================================================
//
// 4D vector
//
//===============================================================

Vector4::Vector4() {
    V[0] = V[1] = V[2] = V[3]= 0.0f;
}

Vector4::Vector4(float x, float y, float z, float w) {
    V[0]=x; V[1]=y; V[2]=z; V[3] = w;
}

float* Vector4::get_vec4() {
    return V;
}

float& Vector4::operator[](int i) {
    return V[i];
}

float Vector4::operator[](int i) const {
    return V[i];
}






