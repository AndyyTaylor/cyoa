#ifndef QUAD_H_INCLUDED
#define QUAD_H_INCLUDED

#include "../Entity.h"
#include "../Model.h"

#include "../Texture/Texture_Atlas.h"

class Quad : public Entity
{
    public:
        Quad(Texture::Atlas& textureAtlas);

        const Model& getModel() const;
        
        virtual void setupTexture() = 0;

    protected:
        Model m_model;
        std::vector<GLfloat> textureCoords;
        Texture::Atlas m_textureAtlas;
        
        void insertTextureCoords(const std::vector<GLfloat>& coords)
        {
            textureCoords.insert(textureCoords.end(), coords.begin(), coords.end());
        }
};

#endif // QUAD_H_INCLUDED