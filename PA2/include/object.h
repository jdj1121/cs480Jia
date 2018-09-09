#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include "graphics_headers.h"

class Object
{
  public:
    Object();
    ~Object();
    void Update(unsigned int dt);
    void Render();
    void Reverse();
    void Pause();
    void OrbitalReverse();
    void OrbitalPause();

    glm::mat4 GetModel();

  private:
    glm::mat4 model;
    std::vector<Vertex> Vertices;
    std::vector<unsigned int> Indices;
    GLuint VB;
    GLuint IB;
    
    int rev;
    int rev2;
    int pau;
    int pau2;
    float angle;
    float angle2;
};

#endif /* OBJECT_H */
