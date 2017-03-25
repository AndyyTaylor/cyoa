#include "Master.h"

#include "../Display.h"

struct Entity;

namespace Renderer
{
    void Master::clear()
    {
        Display::clear();
    }
    
    void Master::update(const Camera& camera)
    {
        m_simpleRenderer.update(camera);
        
        Display::update();
    }
    
    void Master::draw(const Quad& model)
    {
        m_simpleRenderer.draw(model);
    }
}