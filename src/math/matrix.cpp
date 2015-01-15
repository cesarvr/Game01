//
//  matrix.cpp
//  CPluss
//
//  Created by Cesar Luis Valdez on 12/10/14.
//  Copyright (c) 2014 Cesar Luis Valdez. All rights reserved.
//

#include "matrix.h"

using namespace mathc;

Matrix4::Matrix4() {
    mm[ 0] = mm[ 5] = mm[10] = mm[15] = 1.0f;
    mm[ 1] = mm[ 2] = mm[ 3] = mm[ 4] =
    mm[ 6] = mm[ 7] = mm[ 8] = mm[ 9] =
    mm[11] = mm[12] = mm[13] = mm[14] = 0.0;
}

float* Matrix4::get_matrix() {
    return mm;
}

float Matrix4::operator[](int i) const {
    return mm[i];
}
float& Matrix4::operator[](int i) {
    return mm[i];
}

Matrix4 operator*(const Matrix4& A, const Matrix4& B){
    Matrix4 M;
    
    M[ 0] = A[ 0]*B[ 0] + A[ 4]*B[ 1] + A[ 8]*B[ 2] + A[12]*B[ 3];
    M[ 1] = A[ 1]*B[ 0] + A[ 5]*B[ 1] + A[ 9]*B[ 2] + A[13]*B[ 3];
    M[ 2] = A[ 2]*B[ 0] + A[ 6]*B[ 1] + A[10]*B[ 2] + A[14]*B[ 3];
    M[ 3] = A[ 3]*B[ 0] + A[ 7]*B[ 1] + A[11]*B[ 2] + A[15]*B[ 3];
    
    M[ 4] = A[ 0]*B[ 4] + A[ 4]*B[ 5] + A[ 8]*B[ 6] + A[12]*B[ 7];
    M[ 5] = A[ 1]*B[ 4] + A[ 5]*B[ 5] + A[ 9]*B[ 6] + A[13]*B[ 7];
    M[ 6] = A[ 2]*B[ 4] + A[ 6]*B[ 5] + A[10]*B[ 6] + A[14]*B[ 7];
    M[ 7] = A[ 3]*B[ 4] + A[ 7]*B[ 5] + A[11]*B[ 6] + A[15]*B[ 7];
    
    M[ 8] = A[ 0]*B[ 8] + A[ 4]*B[ 9] + A[ 8]*B[10] + A[12]*B[11];
    M[ 9] = A[ 1]*B[ 8] + A[ 5]*B[ 9] + A[ 9]*B[10] + A[13]*B[11];
    M[10] = A[ 2]*B[ 8] + A[ 6]*B[ 9] + A[10]*B[10] + A[14]*B[11];
    M[11] = A[ 3]*B[ 8] + A[ 7]*B[ 9] + A[11]*B[10] + A[15]*B[11];
    
    M[12] = A[ 0]*B[12] + A[ 4]*B[13] + A[ 8]*B[14] + A[12]*B[15];
    M[13] = A[ 1]*B[12] + A[ 5]*B[13] + A[ 9]*B[14] + A[13]*B[15];
    M[14] = A[ 2]*B[12] + A[ 6]*B[13] + A[10]*B[14] + A[14]*B[15];
    M[15] = A[ 3]*B[12] + A[ 7]*B[13] + A[11]*B[14] + A[15]*B[15];

    return M;
}


Matrix4 Matrix4::MakeRotateX( float rad) {
    
    Matrix4 A;
    // [ 0 4      8 12 ]
    // [ 1 cos -sin 13 ]
    // [ 2 sin cos  14 ]
    // [ 3 7     11 15 ]
    
    A[10] = A[ 5] = cosf(rad);
    A[ 6] = sinf(rad);
    A[ 9] = -A[ 6];
    
    A[ 0] = A[15] = 1.0f;
    
    A[ 1] = A[ 2] = A[ 3] = A[ 4] =
    A[ 7] = A[ 8] = A[11] = A[12] =
    A[13] = A[14] = 0.0;
    
    return A;
}

Matrix4 Matrix4::MakeRotateY(float rad) {
    Matrix4 A;
    // [ cos 4  -sin 12 ]
    // [ 1   5   9   13 ]
    // [ sin 6  cos  14 ]
    // [ 3   7  11   15 ]
    
    A[ 0] = A[10] = cosf(rad);
    A[ 2] = sinf(rad);
    A[ 8] = -A[2];
    
    A[ 5] = A[15] = 1.0;
    
    A[ 1] = A[ 3] = A[ 4] = A[ 6] =
    A[ 7] = A[ 9] = A[11] = A[12] =
    A[13] = A[14] = 0.0;
    
    return A;
}

Matrix4 Matrix4::MakeRotateZ(float rad) {
    Matrix4 A;
    // [ cos -sin 8 12 ]
    // [ sin cos  9 13 ]
    // [ 2   6   10 14 ]
    // [ 3   7   11 15 ]
    
    A[ 0] = A[ 5] = cosf(rad);
    A[ 1] = sinf(rad);
    A[ 4] = -A[1];
    
    A[10] = A[15] = 1.0;
    
    A[ 2] = A[ 3] = A[ 6] = A[ 7] =
    A[ 8] = A[ 9] = A[11] = A[12] =
    A[13] = A[14] = 0.0;
    
    return A;
}

Matrix4 Matrix4::MakeOrthoProjection(float left, float right,
                                     float bottom, float top,
                                     float nearZ, float farZ) {
    Matrix4 A;
    A[ 0] = 2.0f / (right - left);
    A[ 1] = A[ 2] = A[ 3] = 0.0f;
    
    A[ 5] = 2.0f / (top - bottom);
    A[ 4] = A[ 6] =  A[ 7] = 0.0f;
    
    A[10] = -2.0f / (farZ - nearZ);
    A[ 8] = A[ 9] =  A[11] = 0.0f;
    
    A[12] = -(right + left) / (right - left);
    A[13] = -(top + bottom) / (top - bottom);
    A[14] = -(farZ + nearZ) / (farZ - nearZ);
    A[15] = 1.0f;

    return A;
}

 void Matrix4::ApplyTranslation(Matrix4& M, float xTrans, float yTrans, float zTrans) {

    M[12] += M[0]*xTrans + M[4]*yTrans + M[ 8]*zTrans;
    M[13] += M[1]*xTrans + M[5]*yTrans + M[ 9]*zTrans;
    M[14] += M[2]*xTrans + M[6]*yTrans + M[10]*zTrans;
}



