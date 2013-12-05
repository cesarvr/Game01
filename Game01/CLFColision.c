//
//  CLFColision.c
//  Game01
//
//  Created by Cesar Luis Valdez on 03/12/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//


#include "CLFColision.h"



float SqDistPointAABB(CLVector2 p, AABB b)
{
    float sqDist = 0.0f;
    
    for (int i = 0; i < 2; i++) {
        // For each axis count any excess distance outside box extents
        float v = p[i];
        if (v < b.min[i]) sqDist += (b.min[i] - v) * (b.min[i] - v);
        if (v > b.max[i]) sqDist += (v - b.max[i]) * (v - b.max[i]);
    }
    return sqDist;
}

/*
 
 TEST COLISION
 
 */


int TestSphereAABB(Circle s, AABB b)
{
    float sqDist = SqDistPointAABB(s.centro, b);
   // printf("\n circle x: %f y: %f  \n",s.centro[0],s.centro[1]);
   // printf("sqDist %f",sqDist);
    return sqDist <= s.radio * s.radio;
}


int TestSphereSphere(Circle a, Circle b)
{
    // Calculate squared distance between centers
    //Vector d = a.c - b.c;
    
    CLVector2 distancia;
    CLVector2Distancia(distancia, a.centro, b.centro);
    
    float dist2 = CLVector2Dot(distancia,distancia);
    // Spheres intersect if squared distance is less than squared sum of radii
    float radiusSum = a.radio + b.radio;
    
    //printf("\n radiusSum -> %f   a.radio+b.radio --> %f \n",radiusSum,(a.radio + b.radio));
    return dist2 <= radiusSum * radiusSum;
}


int punto_cercano_segmento(CLVector2 segmento_cercano, Circle a, Linea b){

    
    CLVector2 segmento_linea;
    CLVector2Distancia(segmento_linea, b.max, b.min);
    
    CLVector2 pt_v;
    CLVector2Distancia(pt_v, a.centro, b.min);
    
    CLVector2 segmento_linea_unit;
    CLVector2Copy( segmento_linea_unit, segmento_linea );
    CLVector2Normalizar(segmento_linea_unit);
    float projeccion = CLVector2Dot(pt_v, segmento_linea_unit);
    
    

    if (projeccion <= 0) {
        CLVector2Copy(segmento_cercano, b.min);
    }
    if (projeccion >= CLVector2Tamano(segmento_linea)) {
        CLVector2Copy(segmento_cercano, b.max);

    }
    
    
    CLVector2 proj_v;
    CLVector2Copy(proj_v, segmento_linea_unit);
    CLVector2MultiplicarEscalar(proj_v, projeccion);
    CLVector2AddResultado(segmento_cercano, proj_v, b.min);
    
    return 0;
}

int TestSphereLinea(Circle a, Linea b, CLFContactoData *contact_data){

    CLVector2 punto_cercano, vdistancia;
    punto_cercano_segmento(punto_cercano, a, b);
    
    CLVector2Distancia(vdistancia, a.centro, punto_cercano);
    
    float distancia = CLVector2Tamano(vdistancia);
    
    printf("distancia: %f \n",distancia);

    if(distancia < a.radio){
        printf("colision");
        CLVector2 vdistancia_norm;
        CLVector2Copy(vdistancia_norm, vdistancia);
        CLVector2Normalizar(vdistancia_norm);
        CLVector2Copy(contact_data->normal, vdistancia_norm);
        
        
      //  CLVector2MultiplicarEscalar(vdistancia_norm, (a.radio - distancia));
        contact_data->penetracion = (a.radio - distancia)*0.4f;
        
        
      //  printf("\n penetracion x: %f y: %f", vdistancia_norm[0], vdistancia_norm[1] );
     
        return 1;
    }
    
    return 0;

}





/*
 
    RESOLVER COLISIONES.
 
 */

int CircleToCircleResolver(CLFContactoData *contact_data){


    CLFObjetos *colision1 = contact_data->colision1;
    CLFObjetos *colision2 = contact_data->colision2;
    
    Circle a = colision1->circle;
    Circle b = colision2->circle;

    CLVector2 distancia;
    CLVector2Distancia(distancia, a.centro, b.centro);
    
    
    float tamano_distancia = CLVector2Tamano(distancia);
    float radiusSum = a.radio + b.radio;
    
    contact_data->penetracion = radiusSum - tamano_distancia;
   
   
    //Direccion del contacto.
    
    CLVector2Make( contact_data->normal, distancia[0], distancia[1] );
    CLVector2Normalizar( contact_data->normal );
  
    
    
    return 0;

}



int CLFColisionDetector(CLFContactoData *contact_data)
{

    CLFObjetos *colision1 = contact_data->colision1;
    CLFObjetos *colision2 = contact_data->colision2;
    
    
    //Circle to Circle.
    if(colision1->tipo == CIRCULO && colision2->tipo == CIRCULO){
    
        if (TestSphereSphere(colision1->circle, colision2->circle))
             return COLISION_CIRCULO_CIRCULO;
        
       
    
    }
    
    if (colision1->tipo == CIRCULO && colision2->tipo == CUADRADO){
        
       // printf(" circulo - cuadrado \n");
        if (TestSphereAABB(colision1->circle, colision2->shape))
            return COLISION_AABB_CIRCULO;
        
        
    }else if(colision1->tipo == CUADRADO && colision2->tipo == CIRCULO){
    
       // printf("cuadrado - circulo \n");
        if ( TestSphereAABB(colision2->circle, colision1->shape) )
            return COLISION_AABB_CIRCULO;
    
    }
    
    
    if (colision1->tipo == CIRCULO && colision2->tipo == LINEA){
        
        // printf(" circulo - cuadrado \n");
        if (TestSphereLinea(colision1->circle, colision2->linea, contact_data))
            return COLISION_LINEA_CIRCULO;
        
        
    }else if(colision1->tipo == LINEA && colision2->tipo == CIRCULO){
        
        // printf("cuadrado - circulo \n");
        if ( TestSphereLinea(colision2->circle, colision1->linea, contact_data) )
            return COLISION_LINEA_CIRCULO;
        
    }
    

    
    
    
        return NO_COLISION;
        
}












/*
 
 
 APLICAR IMPULSO - APLICAR FISICAS RESULTANTES DE LA COLISION.
 
 
 */

void CLFColisionApplyLinearImpulse(CLFContactoData *contact_data){


    CLFObjetos *colision1 = contact_data->colision1;
    CLFObjetos *colision2 = contact_data->colision2;
    
    CLVector2 vVelocidad_relativa;
    CLVector2Distancia(vVelocidad_relativa, colision1->velocidad, colision2->velocidad);

    float movimiento_relativo = -CLVector2Dot(vVelocidad_relativa, contact_data->normal);
    
    
    if(movimiento_relativo > -0.01f){
        
        printf(" skiping \n");
        return;
        
    }
    
    /*  coeficiente de restitucion  */
    float e = colision1->coeficiente_restitucion;
    
    
    //calcular impulso.
    // float j = -(1.0f + e) * movimiento_relativo;
    
    
    float mov_relativo = CLVector2Dot(vVelocidad_relativa, contact_data->normal);
  
    
    
    float j = -1 * (1.0f + e) * mov_relativo;
    float dot_contact_normal = CLVector2Dot(contact_data->normal, contact_data->normal);
    
    j /= dot_contact_normal * ( colision1->masa + colision2->masa );
    j += ( contact_data->penetracion * 1.5f );

    
    /*  Impulso para el primer objeto de la colision
     
        COLISION 1
     
     */
    CLVector2 impulso;
    CLVector2Make(impulso, 0.0f, 0.0f);
    CLVector2AddVectorEscalado(impulso, contact_data->normal, j);
    
    
    //añadir inverse mass
    CLVector2MultiplicarEscalar(impulso, colision1->masa);
    
    CLVector2Add(colision1->velocidad, impulso);
    printf("colision1->velocidad -> x:%f y:%f \n",colision1->velocidad[0],colision1->velocidad[1] );
    
    /*  Impulso para el segundo objeto de la colision
     
     COLISION 2
     
     */

    
    CLVector2Make(impulso, 0.0f, 0.0f);
    CLVector2AddVectorEscalado(impulso, contact_data->normal, j);
    CLVector2MultiplicarEscalar(impulso, colision2->masa);
    printf("colision2->mass: %f\n",colision2->masa);
    CLVector2Sub(colision2->velocidad, impulso);
    
    
    
}


void CLFColisionPositionalCorrection(CLFContactoData *contact_data){


    CLFObjetos *A = contact_data->colision1;
    CLFObjetos *B = contact_data->colision2;
    
}







