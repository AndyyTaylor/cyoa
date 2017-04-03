#include "Display.h"

#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include <GL/glew.h>
#include "States/Playing.h"

namespace Display 
{    
    std::unique_ptr<sf::RenderWindow> window;
    
    void init()
    {
        // Setup opengl context
        sf::ContextSettings settings;
        settings.depthBits = 24;
        settings.majorVersion = 4;
        settings.minorVersion = 1;
        
        window = std::make_unique<sf::RenderWindow>(sf::VideoMode(WIDTH, HEIGHT), 
                                                    "Window", 
                                                    sf::Style::Close, 
                                                    settings);
        
        // Ahhhh this line... Mentioned in the bug report
        glewExperimental = GL_TRUE;
        glewInit();
        glViewport(0, 0, WIDTH, HEIGHT);
        glEnable(GL_DEPTH_TEST); // Literally tests the depth of pixels so as to render them in the correct order
        
        window->setMouseCursorVisible(false); // No mouse pointer
    }
    
    void close()
    {
        window->close();
    }
    
    void clear()
    {
        // Clears everything relevant to each pixel
        glClearColor(0.0, 0.0, 0.0, 1.0);
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
    
    bool isOpen()
    {
        return window->isOpen();
    }
    
    const sf::Window& get()
    {
        return *window;
    }
}