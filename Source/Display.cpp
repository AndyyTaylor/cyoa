#include "Display.h"

#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include <GL/glew.h>

namespace Display
{
    // Automatically clears this pointer when the window is out of scope
    std::unique_ptr<sf::RenderWindow> window;
    
    // Defining the functions declared in 'Display.h'
    void init()
    {
        sf::ContextSettings settings;
        settings.depthBits = 24;
        settings.majorVersion = 4;
        settings.minorVersion = 1;
        
        window = std::make_unique<sf::RenderWindow>(sf::VideoMode(WIDTH, HEIGHT)
                                                    , "Choose Your Own Adventure"
                                                    , sf::Style::Close
                                                    , settings);
        
        // Otherwise you get a seg fault error which I spent a good hour debugging
        glewExperimental = GL_TRUE;
        glewInit();
        glViewport(0, 0, WIDTH, HEIGHT);    // Literally the 'viewing port'
        glEnable(GL_DEPTH_TEST);            // So 3D objects render in the proper order
    }
    
    void close()
    {
        window->close();
    }
    
    void clear()
    {
        glClearColor(0.0, 0.0, 0.0, 1.0); // rgba
        glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    }
    
    void update()
    {
        window->display();
    }
    
    void checkForClose()
    {
        sf::Event e;
        while (window->pollEvent(e))
        {
            if (e.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                close();
            }
        }
    }
}