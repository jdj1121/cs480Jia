#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include "graphics_headers.h"

class Object
{
  public:
    Object();
    ~Object();
    void PlanetUpdate(unsigned int dt);
    void Render();
    void Reverse();
    void Pause();
    void OrbitalReverse();
    void OrbitalPause();

    glm::mat4 GetModel();
    glm::mat4 GetPosition();
    glm::mat4 model;
  private:

    std::vector<Vertex> Vertices;
    std::vector<unsigned int> Indices;
    GLuint VB;
    GLuint IB;
    
    int rev;
    int rev2;
    int pau;
    int pau2;
    float angle[2];
};

#endif /* OBJECT_H */
