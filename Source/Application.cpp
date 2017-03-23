#include "Application.h"

#include "Display.h"

Application::Application()
{
    
}

void Application::runMainGameLoop()
{
    sf::Clock clock;
    
    while (Display::isOpen())
    {
        auto dt = clock.restart().asSeconds();
        
        
        
        Display::checkForClose();
    }
}