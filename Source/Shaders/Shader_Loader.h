#ifndef SHADER_LOADER_H_INCLUDED
#define SHADER_LOADER_H_INCLUDED


#include <GL/glew.h>
#include <string>


// Really simple header
namespace Shader
{
    GLuint loadShader(const std::string& vertexShaderFile, const std::string& fragmentShaderFile);
}

#endif