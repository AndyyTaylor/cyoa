
#include "Simple_Shader.h"
#include "../Maths/Matrix.h"

namespace Shader
{
    Simple_Shader::Simple_Shader()
    : Shader_Program("Simple_Vertex", "Simple_Fragment")
    {
        getUniformLocations();
        
        bind();
        loadMatrix4(m_locationProjMatrix, Maths::createProjMatrix());
        unbind();
    }
    
    void Simple_Shader::getUniformLocations()
    {
        // Get the location of the uniform variables for the shaders
        // It's interesting it refers to them by their actual name
        m_locationGood = glGetUniformLocation(getId(), "goodness");
        m_locationViewMatrix = glGetUniformLocation(getId(), "viewMatrix");
        m_locationProjMatrix = glGetUniformLocation(getId(), "projMatrix");
        m_locationModelMatrix = glGetUniformLocation(getId(), "modelMatrix");
    }
    
    // Loading values into these uniform variables
    void Simple_Shader::setGoodness(float goodness)
    {
        loadFloat(m_locationGood, goodness);
    }
    
    void Simple_Shader::setViewMatrix(const Matrix4 &matrix)
    {
        loadMatrix4(m_locationViewMatrix, matrix);
    }
    
    void Simple_Shader::setModelMatrix(const Matrix4 &matrix)
    {
        loadMatrix4(m_locationModelMatrix, matrix);
    }
    
    void Simple_Shader::setProjMatrix(const Matrix4 &matrix)
    {
        loadMatrix4(m_locationProjMatrix, matrix);
    }
}