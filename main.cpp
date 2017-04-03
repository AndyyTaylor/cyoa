#include "Source/Display.h"

#include "Source/Application.h"

// Now this.. this is what a main.cpp should look like
int main()
{
    Display::init();
    
    Application app;
    
    app.runMainGameLoop();
    
    return 0;
}