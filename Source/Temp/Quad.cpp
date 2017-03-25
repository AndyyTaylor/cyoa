#include "Quad.h"

#include <vector>

#include "../Texture/Texture_Atlas.h"

Quad::Quad(Texture::Atlas& textureAtlas)
: m_textureAtlas(textureAtlas)
{
    
}


const Model& Quad::getModel() const
{
    return m_model;
}
