#include "Texture_Atlas.h"

// The texture atlas contains the spritesheet
namespace Texture
{
    Atlas::Atlas(const std::string& textureName, GLuint size, GLuint textureSize)
    : m_size(size)
    , m_textureSize(textureSize)
    {
        load(textureName);
    }
    
    std::vector<GLfloat> Atlas::getTextureCoords(const Vector2& location)
    {
        // All of this is just so that I can use say {2, 3} to reference the 2nd accross and 3rd down image
        static auto texturesPerRow = m_size / m_textureSize;
        static auto unitSize = 1.0f/(float) texturesPerRow;
        
        auto xMin = location.x * unitSize;
        auto yMin = location.y * unitSize;
        
        auto xMax = xMin + unitSize;
        auto yMax = yMin + unitSize;
        
        return {
            xMax, yMax,
            xMin, yMax,
            xMin, yMin,
            xMax, yMin
        };
    }
}