#ifndef APPLICATION_H_INCLUDED
#define APPLICATION_H_INCLUDED

#include <stack>
#include <memory>

#include "Renderer/Master.h"

class Application
{
public:
    Application();
    
    void runMainGameLoop();
    
private:
    Renderer::Master m_renderer;
};



#endif