//
//  particle.cpp
//  BlockGame
//
//  Created by Cesar Luis Valdez on 13/10/14.
//  Copyright (c) 2014 Cesar Luis Valdez. All rights reserved.
//

#include "particle.h"

#define MAX_PARTICLE 35
int GenerateRandomBetween(int min, int max);


void Particle::InitShader() {
    particle_shader.LoadFromFile(GL_VERTEX_SHADER,
                                 BASIC_VERTEX_SHADER);
    particle_shader.LoadFromFile(GL_FRAGMENT_SHADER,
                                 BASIC_FRAGMENT_SHADER);
   
    particle_shader.CreateAndLinkProgram();
    particle_shader.Use();
    particle_shader.AddAttribute("position");
    particle_shader.AddAttribute("color");
    particle_shader.AddAttribute("textura_uv");
    particle_shader.AddUniform("mv");
    particle_shader.UnUse();
}

void Particle::InitGeometry() {
    
    Geometry geometry;
    geometry.position = mathc::Vector3(1.0f, 1.0f, 1.0f);
    geometry.color = mathc::Vector4(0.9f,0.5f,0.1f,1.0f);
    geometry.texture = mathc::Vector2(0.0f, 0.0f);
    
    bufferz.using_indices = false;
    bufferz.mode = GL_POINTS;
    bufferz.geometry.push_back(geometry);
    BufferGPU::UploadToGPU(bufferz, GL_STATIC_DRAW);
}

Entity Particle::CreateEntity(float x, float y, float size) {
    Entity particle;
    particle.shader = particle_shader;
    particle.buffer = bufferz;
    
    particle.transform.model = mathc::Matrix4();
    particle.transform.mvp = mathc::Matrix4();
    
    
    mathc::Matrix4::ApplyTranslation(particle.transform.model,
                                     x, y, 0.0f);
    glPointSize(size);
    
    return particle;
}

void Particle::Clean() {
    printf("releasing GPU Memory\n");
    BufferGPU::ReleaseFromGPU(bufferz);
}


void Particle::Init() {
   
    InitShader();
    InitGeometry();
    srand((unsigned int)time(NULL));
    for(int i = 0; i< MAX_PARTICLE; i++) {
        float x = GenerateRandomBetween(0, SCREEN_WIDTH);
        float y = GenerateRandomBetween(0, SCREEN_HEIGHT);
    
        Entity tmp = CreateEntity(x, y, 5.0f);
        entities.push_back(tmp);
    }
}

void Particle::Update(mathc::Matrix4& camera) {
    for(Entity &entity_particle : entities) {
        entity_particle.transform.mvp = camera * entity_particle.transform.model;
    }
    
}

vector<Entity>& Particle::get_entities() {
    return entities;
}

Particle::~Particle() {
    Clean();
}


int GenerateRandomBetween(int min, int max)
{

    return rand()%(max-min + 1) + min;;
}



