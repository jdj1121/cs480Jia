#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "graphics_headers.h"

class Object
{
  public:
    Object();
    ~Object();
    void Update(unsigned int dt);
    void Render();
    bool loadOBJ(char * obj);
    glm::mat4 GetModel();
    float RandomFloat(float a, float b);

  private:
    glm::mat4 model;
    std::vector<Vertex> Vertices;
    std::vector<unsigned int> Indices;
    GLuint VB;
    GLuint IB;

    float angle;
    float angle2;
};

#endif /* OBJECT_H */
