#include "Shader_Program.h"
#include "Shader_Loader.h"

namespace Shader
{
    Shader_Program::Shader_Program(const std::string& vertexShaderFile, const std::string& fragmentShaderFile)
    : m_programId (loadShader(vertexShaderFile, fragmentShaderFile))
    {
        
    }
    
    Shader_Program::~Shader_Program()
    {
        glDeleteProgram(m_programId);
    }
    
    void Shader_Program::bind()
    {
        glUseProgram(m_programId);
    }
    
    void Shader_Program::unbind()
    {
        // Use program with id 0 means to clear the program
        // useful so you don't accidently use the wrong program
        glUseProgram(0);
    }
    
    GLuint Shader_Program::getId() const
    {
        return m_programId;
    }
    
    void Shader_Program::loadFloat(GLuint location, float value)
    {
        glUniform1f(location, value);
    }
    
    void Shader_Program::loadVector2(GLuint location, const Vector2 &vector)
    {
        glUniform2f(location, vector.x, vector.y);
    }
    
    void Shader_Program::loadMatrix4(GLuint location, const Matrix4 &matrix)
    {
        glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
    }
}