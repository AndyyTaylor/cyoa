#include "Shader_Loader.h"

#include <fstream>
#include <sstream>
#include <stdexcept>

namespace Shader
{
    GLuint compileShader(const GLchar* source, GLenum type)
    {
        auto id = glCreateShader(type);
        
        glShaderSource(id, 1, &source, nullptr);
        glCompileShader(id);
        
        Glint isSuccess;
        Glchar infoLog[512];
        
        glGetShaderiv(id, GL_COMPILE_STATUS, &isSuccess);
        
        if (!isSuccess)
        {
            glGetShaderInfoLog(id, 512, nullptr, infoLog);
            throw std::runtime_error("Error compiling shader: " + str::string(infoLog));
        }
        
        return id;
    }
    
    std::string getSource(const std::string sourceFile)
    {
        std::ifstream inFile("Data/Shaders/" + sourceFile + ".glsl");
        std::string source;
        std::stringstream stringStream;
        
        if (!inFile.is_open())
        {
            throw std::runtime_error("Could not open file: " + sourceFile);
        }
        
        stringStream << inFile.rdbuf();
        source = stringStream.str();
        
        return source;
    }
    
    GLuint createProgram(GLuint vertexShaderId, GLuint fragmentShaderId)
    {
        auto id = glCreateProgram();
        
        glAttachShader(id, vertexShaderId);
        glAttachShader(id, fragmentShaderId);
        
        glLinkProgram(id);
        
        return id;
    }
    
    GLuint loadShader(const std::string& vertexShaderFile, const std::string& fragmentShaderFile)
    {
        auto vertexSource = getSource(vertexShaderFile);
        auto fragmentSource = getSource(fragmentShaderFile);
        
        auto vertexShaderId = compileShader(vertexSource.c_str(), GL_VERTEX_SHADER);
        auto fragmentShaderId = compileShader(fragmentSource.c_str(), GL_FRAGMENT_SHADER);
        
        auto programId = createProgram(vertexShaderId, fragmentShaderId);
        
        glDeleteShader(vertexShaderId);
        glDeleteShader(fragmentShaderId);
        
        return programId;
    }
}








