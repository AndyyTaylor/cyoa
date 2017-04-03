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
        setupTexture();
        readStory();
        updateCurrentRoom();
    }
    
    void MainScreen::setupTexture()
    {
        // Each insertTextureCoords corresponds to a different face on the screen
        // and the coordinates are the coords on the sprite sheet
        textureCoords.clear();
        insertTextureCoords(m_textureAtlas.getTextureCoords({1, 0}));
        insertTextureCoords(m_textureAtlas.getTextureCoords({0, 0}));
        insertTextureCoords(m_textureAtlas.getTextureCoords({story % 5, (floor(story/5)+1)}));
        insertTextureCoords(m_textureAtlas.getTextureCoords({0, 0}));
        insertTextureCoords(m_textureAtlas.getTextureCoords({0, 0}));
        insertTextureCoords(m_textureAtlas.getTextureCoords({0, 0}));
        
        // Updates the actual model
        m_model.addData(vertexPositions, textureCoords, indices);
    }
    
    void MainScreen::readStory()
    {
        // Reads the story file
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
        while (std::getline(f, s, '|')) { // The closest thing to .split() I could find
            strings.push_back(s);
        }
        
        // I'll be honest I can't exactly remember how this worked.. but it does!
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
                r.options.push_back(std::stoi(strings[i])); // stoi -> string to int
            }
        }
        all_rooms.push_back(r);
    }
    
    void MainScreen::input()
    {
        // Unfortunately this was because I didn't have enough time to do it any other way
        // The Display object already cycles through any created events in order to check if its closed
        // so I had to make my own little pressed / released system
        if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
            released = true;
        if (released)
        {
            released = false;
            int op = -1;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
            {
                op = 0;
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
            {
                op = 1;
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
            {
                op = 2;
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
            {
                op = 3;
            } else {
                released = true;
            }
            if (!released)
            {
                // Change goodness based on how good the choice way 'op -> option number'
                if (story > 2 && story != 7 && story < 16) {
                    total_good += 100;
                    if (op == 0){
                        actual_good += 100;
                    } else if (op == 1){
                        actual_good += 66;
                    } else if (op == 2){
                        actual_good += 33;
                    } // no (op == 3) because it would only += 0
                    goodness = actual_good/total_good * 100;
                } 
                // Set the new story index
                story = current_room.options[op];
                // This code has to be run after the story is updated
                // Skill check screen
                if (story == 7) {
                    if (goodness == 100){ story = 16; }
                    else if (goodness > 75){ story = 17; }
                    else if (goodness > 50){ story = 18; }
                    else { story = 19; }
                } else if (story == 0){ // Reset goodness
                    total_good = 0;
                    actual_good = 0;
                    goodness = 100;
                } 
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