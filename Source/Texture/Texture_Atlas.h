#ifndef TEXTURE_ATLAS_H_INCLUDED
#define TEXTURE_ATLAS_H_INCLUDED

#include "Texture.h"
#include "../Glm_Common.h"

#include <vector>

namespace Texture
{
    class Atlas : public Basic_Texture
    {
    public:
        Atlas(const std::string& textureName, GLuint size, GLuint textureSize);
        
        std::vector<GLfloat> getTextureCoords(const Vector2& location);
        
    private:
        GLuint m_size;
        
        GLuint m_textureSize = 100;
    };
}


#endif