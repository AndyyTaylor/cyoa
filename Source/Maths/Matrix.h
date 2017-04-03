#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include "../Glm_Common.h"

// Forward declarations which I really like the idea of
struct Entity;
class Camera;

// Just a header file, nothing special
namespace Maths
{
    Matrix4 createViewMatrix(const Camera& entity);
    Matrix4 createModelMatrix(const Entity& entity);
    Matrix4 createProjMatrix();
}


#endif