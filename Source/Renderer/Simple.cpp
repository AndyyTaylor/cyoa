#include "Simple.h"

#include "../Temp/Quad.h"
#include "../Maths/Matrix.h"

namespace Renderer
{
    void Simple::draw(const Quad& quad)
    {
        m_quads.push_back(&quad);
    }
    
    void Simple::update(const Camera& camera, float goodness)
    {
        // Binds the shaders id with opengl
        m_shader.bind();
        m_shader.setGoodness(goodness);
        
        // Gets passed into the shader
        m_shader.setViewMatrix(Maths::createViewMatrix(camera));
        
        for (auto& quad : m_quads)
        {
            // Pointers and references are very confusing
            prepare(*quad);
            glDrawElements(GL_TRIANGLES, quad->getModel().getIndicesCount(), GL_UNSIGNED_INT, nullptr);
        }
         
        m_quads.clear();
    }
    
    void Simple::prepare(const Quad& quad)
    {
        quad.getModel().bind();
        m_shader.setModelMatrix(Maths::createModelMatrix(quad));
    }
}