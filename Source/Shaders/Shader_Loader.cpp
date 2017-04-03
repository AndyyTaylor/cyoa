#include "Shader_Loader.h"

#include <fstream>
#include <sstream>
#include <stdexcept>

namespace Shader
{
    GLuint compileShader(const GLchar* source, GLenum type)
    {
        // Opengl refers to practically everything by an 'id' (which is a GLuint)
        auto id = glCreateShader(type);
        
        // Sends in the shader's source code
        glShaderSource(id, 1, &source, nullptr);
        glCompileShader(id);
        
        GLint isSuccess;
        GLchar infoLog[512];
        
        glGetShaderiv(id, GL_COMPILE_STATUS, &isSuccess);
        
        // Error handling
        if (!isSuccess)
        {
            glGetShaderInfoLog(id, 512, nullptr, infoLog);
            throw std::runtime_error("Error compiling shader: " + std::string(infoLog));
        }
        
        return id;
    }
    
    std::string getSource(const std::string sourceFile)
    {
        // Reads the shader source from a file
        std::ifstream inFile ("Data/Shaders/" + sourceFile + ".glsl");
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
        // A program holds a number of shaders, typically a vertexShader,
        // fragmentShader and geometryShader (not used here)
        auto id = glCreateProgram();
        
        glAttachShader(id, vertexShaderId);
        glAttachShader(id, fragmentShaderId);
        
        glLinkProgram(id);
        
        return id;
    }
    
    GLuint loadShader(const std::string& vertexShaderFile, const std::string& fragmentShaderFile)
    {
        // Calls the above functions
        auto vertexSource = getSource(vertexShaderFile);
        auto fragmentSource = getSource(fragmentShaderFile);
        
        auto vertexShaderId = compileShader(vertexSource.c_str(), GL_VERTEX_SHADER);
        auto fragmentShaderId = compileShader(fragmentSource.c_str(), GL_FRAGMENT_SHADER);
        
        auto programId = createProgram(vertexShaderId, fragmentShaderId);
        
        // Don't need the shaders anymore as they've been copied into the program
        glDeleteShader(vertexShaderId);
        glDeleteShader(fragmentShaderId);
        
        return programId;
    }
}