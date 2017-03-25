#include "Source/Display.h"

#include "Source/Application.h"

int main()
{
    Display::init();
    
    Application app;
    
    app.runMainGameLoop();
    
    return 0;
}