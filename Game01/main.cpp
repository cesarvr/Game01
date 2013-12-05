
//
//  main.cpp
//  EngineOne
//
//  Created by Cesar Luis Valdez on 12/11/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#include <iostream>
#include "glfw3.h"
#include "CoreGame.h"



#define SCREEN_ANCHO 800
#define SCREEN_ALTO 600


GLboolean ARRIBA = false;
GLboolean ABAJO = false;
GLboolean DERECHA = false;
GLboolean IZQUIERDA = false;
GLboolean KEY_Q = false;
GLboolean KEY_E = false;
GLboolean KEY_ACTION = false;
GLboolean bloquear = false;


static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
    
    
    if(action == GLFW_RELEASE){
    
        IZQUIERDA = false;
        ABAJO = false;
        DERECHA = false;
         ARRIBA = false;
        bloquear = false;
        
    }
    
    if (key == GLFW_KEY_LEFT &&  action == GLFW_PRESS) {
        IZQUIERDA = true;
    }else
        IZQUIERDA = false;
    
    if (key == GLFW_KEY_DOWN &&   action == GLFW_PRESS) {
        ABAJO = true;
    }else
        ABAJO = false;
    
    if (key == GLFW_KEY_RIGHT &&   (action == GLFW_PRESS)) {
        DERECHA = true;
    
    }else
        DERECHA = false;
    
    if (key == GLFW_KEY_UP &&  action == GLFW_PRESS) {
        ARRIBA = true;
        
    }else{
        ARRIBA = false;
    }
    
    if (key == GLFW_KEY_Q &&  (action == GLFW_REPEAT || action == GLFW_PRESS) ) {
        KEY_Q = true;
    }else{
        KEY_Q = false;
    }
    
    
    if (key == GLFW_KEY_E  &&  (action == GLFW_REPEAT || action == GLFW_PRESS) ) {
        KEY_E = true;
    }else{
        KEY_E = false;
    }
    
    if (key == GLFW_KEY_SPACE  &&  action == GLFW_PRESS ) {
        KEY_ACTION = true;
    }else{
        KEY_ACTION = false;
    }

    
    
}






void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}


int main(int argc, const char * argv[])
{
    
    
    if (!glfwInit())
    {
        printf("Error iniciando GLFW");
        exit(EXIT_FAILURE);
    }
    //manejador de errores;
    
    /*
     glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
     glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
     glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
     glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
     */
    
    
    glfwSetErrorCallback(error_callback);
    
    GLFWwindow* window = glfwCreateWindow(SCREEN_ANCHO, SCREEN_ALTO, "Prueba Juego", NULL, NULL);
    
    
    if (!window)
    {
        
        printf("error al crear ventana.");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    
    // Make the window's context current
    glfwMakeContextCurrent(window);
    
    //  printf("\n version: %s \n", glfwGetVersionString());
    printf("\n OpenGL [render]:  %s ", glGetString(GL_RENDERER));
    printf("\n OpenGL [version]: %s ", glGetString(GL_VERSION));
    printf("\n OpenGL [vendor]: %s \n",glGetString(GL_VENDOR));
    
    
    
    CEntradaData entrada;
    CoreGame gameMech(&entrada);
  
    glfwSetKeyCallback(window, key_callback);
    
    double delta =0.0f;
    double old_time = glfwGetTime();
    
    while (!glfwWindowShouldClose(window))
    {
        double current_time = glfwGetTime(),
        delta = (current_time - old_time);
        old_time = current_time;
       
        
        entrada.setTime(delta);
        
        if (!bloquear) {
            
      
        if (ARRIBA) {
            //printf("arriba");
            entrada.setMovimientoArriba();
            bloquear =true;
        }
        if (DERECHA) {
            entrada.setMovimientoDerecha();
            bloquear =true;
        }
        if (ABAJO) {
            entrada.setMovimientoAbajo();
            bloquear =true;
        }
        if (IZQUIERDA) {
            entrada.setMovimientoIzquierda();
            bloquear =true;
        }
        
        if (KEY_ACTION) {
            entrada.setFire();
              bloquear =true;
        }
          }
    
        
        gameMech.draw();
        gameMech.update();
        
        glfwSwapBuffers(window);
        glfwPollEvents();
        

        
    }
    
    
    gameMech.finish();

    
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
    return 0;
}






