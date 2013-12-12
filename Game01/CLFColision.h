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
#include "CLFColisionList.h"
#include "CLFDataType.h"




#ifdef __cplusplus
extern "C" {
    void CLFResolverColisiones();
    void CLFRecopilarContactos(CLFContactoData *contact_data);
    int CLFColisionResolver(CLFContactoData *contact_data, int tipo_colision);
    int CLFColisionDetector(CLFContactoData *contact_data);
    void CLFColisionApplyLinearImpulse(CLFContactoData *contact_data);
    int CircleToCircleResolver(CLFContactoData *contact_data);
    void CLFLiberarMemoria();
}
#endif


#endif
