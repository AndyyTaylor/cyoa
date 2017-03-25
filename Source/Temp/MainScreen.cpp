#include "MainScreen.h"

#include <iostream>
#include "Quad.h"
#include "../Texture/Texture_Atlas.h"

namespace Object
{
    MainScreen::MainScreen(Texture::Atlas& textureAtlas)
    : Quad(textureAtlas)
    {
        std::cout << "Hello" << std::endl;
        setupTexture();
    }
    
    void MainScreen::setupTexture()
    {
        textureCoords.clear();
        insertTextureCoords(m_textureAtlas.getTextureCoords({1, 0}));
        insertTextureCoords(m_textureAtlas.getTextureCoords({0, 0}));
        insertTextureCoords(m_textureAtlas.getTextureCoords({story % 5, (floor(story/5)+1)}));
        insertTextureCoords(m_textureAtlas.getTextureCoords({0, 0}));
        insertTextureCoords(m_textureAtlas.getTextureCoords({0, 0}));
        insertTextureCoords(m_textureAtlas.getTextureCoords({0, 0}));

        m_model.addData(vertexPositions, textureCoords, indices);
    }
}