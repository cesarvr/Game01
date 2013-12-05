//
//  CLFColision.h
//  Game01
//
//  Created by Cesar Luis Valdez on 03/12/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#ifndef Game01_CLFColision_h
#define Game01_CLFColision_h

#include <stdio.h>
#include "CLVector2DLib.h"
#include "CLFObjetos.h"

enum colision_tipo {
    COLISION_CIRCULO_CIRCULO = 1,
    COLISION_AABB_CIRCULO = 2,
    COLISION_LINEA_CIRCULO = 3,
    NO_COLISION = 0
};

struct CLFContactoData_t
{
    
    CLFObjetos *colision1;
    CLFObjetos *colision2;
    CLVector2  normal;
    
    int estado_contacto;
    float penetracion;
    
    
};
typedef struct CLFContactoData_t CLFContactoData;

#ifdef __cplusplus
extern "C" {
    
    int CLFColisionResolver(CLFContactoData *contact_data, int tipo_colision);
    int CLFColisionDetector(CLFContactoData *contact_data);
    void CLFColisionApplyLinearImpulse(CLFContactoData *contact_data);
    int CircleToCircleResolver(CLFContactoData *contact_data);
}
#endif


#endif
