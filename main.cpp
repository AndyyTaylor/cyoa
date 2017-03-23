#include <iostream>

#include "Source/Display.h"
#include "Source/Application.h"

int main()
{
    Display::init();
    
    Application app;
    app.runMainGameLoop();
    
    std::cout<<"Hello world"<<std::endl;
    
    return 0;
}