#ifndef SHADER_PROGRAM_H_INCLUDED
#define SHADER_PROGRAM_H_INCLUDED


#include <GL/Glew.h>
#include <string>

#include "../Glm_Common.h"

// More header files!
// Also namespaces are a really interesting way of keeping things in different files 'connected' by scope
namespace Shader
{
    class Shader_Program
    {
    public:
        Shader_Program(const std::string& vertexShaderFile, const std::string& fragmentShaderFile);
        ~Shader_Program();
        
        void bind();
        void unbind();
        
    protected:
        virtual void getUniformLocations() = 0;
        
        GLuint getId() const;
        
        // Used to load values into uniform variables
        void loadFloat(GLuint location, float value);
        void loadVector2(GLuint location, const Vector2& vector);
        void loadMatrix4(GLuint location, const Matrix4& matrix);
        
    private:
        GLuint m_programId;
    };
}

#endif