#include "MainScreen.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

#include <SFML/Window/Keyboard.hpp>
#include "Quad.h"
#include "../Texture/Texture_Atlas.h"

namespace Object
{
    MainScreen::MainScreen(Texture::Atlas& textureAtlas)
    : Quad(textureAtlas)
    {
        std::cout << "Hello" << std::endl;
        setupTexture();
        readStory();
        updateCurrentRoom();
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
    
    void MainScreen::readStory()
    {
        std::ifstream file;
        file.open("Data/Story.txt");
        
        std::string source;
        std::stringstream stringStream;
        
        if (!file.is_open())
        {
            throw std::runtime_error("Could not open file: Story.txt");
        }
        
        stringStream << file.rdbuf();
        source = stringStream.str();
        std::replace(source.begin(), source.end(), '\n', '|');
        
        std::vector<std::string> strings;
        std::istringstream f(source);
        std::string s;
        while (std::getline(f, s, '|')) {
            strings.push_back(s);
        }
        
        Room r;
        for (int i = 0; i < strings.size(); i++)
        {
            if (i % 5 == 0)
            {
                if (i != 0)
                {
                    all_rooms.push_back(r);
                    r.options.clear();
                }
                r.id = std::stoi(strings[i]);
            } 
            else
            {
                r.options.push_back(std::stoi(strings[i]));
            }
        }
        all_rooms.push_back(r);
        
        for (int i = 0; i < all_rooms.size(); i++)
        {
            std::cout << all_rooms[i].options.size() << std::endl;
        }
    }
    
    void MainScreen::input()
    {
        if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
            released = true;
        if (released)
        {
            released = false;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
            {
                story = current_room.options[0];
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
            {
                story = current_room.options[1];
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
            {
                story = current_room.options[2];
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
            {
                story = current_room.options[3];
            } else {
                released = true;
            }
            if (!released)
            {
                updateCurrentRoom();
                setupTexture();
            }
        }
        
    }
    
    GLuint MainScreen::getStory()
    {
        return story;
    }
}