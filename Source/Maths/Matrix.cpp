#include "Matrix.h"
#include "../Entity.h"
#include "../Display.h"
#include "../Camera.h"

namespace Maths
{
    // You can imagine this function creating a matrix, or a viewpoint
    // Rotating it to match the camera's orientation, the translating it to match the camera's position
    Matrix4 createViewMatrix(const Camera& camera)
    {
        Matrix4 matrix;
        // glm::rotate is actually kinda confusing
        matrix = glm::rotate(matrix, glm::radians(camera.rotation.x), {1, 0, 0});
        matrix = glm::rotate(matrix, glm::radians(camera.rotation.y), {0, 1, 0});
        matrix = glm::rotate(matrix, glm::radians(camera.rotation.z), {0, 0, 1});
        
        matrix = glm::translate(matrix, -camera.position);
        return matrix;
    }
    
    Matrix4 createModelMatrix(const Entity& entity)
    {
        Matrix4 matrix;
        
        matrix = glm::translate(matrix, entity.position);
        
        matrix = glm::rotate(matrix, glm::radians(entity.rotation.x), {1, 0, 0});
        matrix = glm::rotate(matrix, glm::radians(entity.rotation.y), {0, 1, 0});
        matrix = glm::rotate(matrix, glm::radians(entity.rotation.z), {0, 0, 1});
        
        return matrix;
    }
    
    Matrix4 createProjMatrix()
    {
                    // From memory - fov                    aspect rotatio                             near dist, far dist
                    // anything outside the fov, closer than the near dist, or further than the far dist doesn't get renderered
        return glm::perspective(glm::radians(120.0f), (float) Display::WIDTH/ (float) Display::HEIGHT, 0.001f, 1000.0f);
    }
}