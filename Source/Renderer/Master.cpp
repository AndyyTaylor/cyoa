#include "Master.h"

#include "../Display.h"

struct Entity;

// This would be the 'master renderer' which would manage all of the smaller renderers
// however this is a very small project
namespace Renderer
{
    void Master::clear()
    {
        Display::clear();
    }
    
    void Master::update(const Camera& camera)
    {
        m_simpleRenderer.update(camera, good);
        
        Display::update();
    }
    
    void Master::draw(const Quad& model)
    {
        m_simpleRenderer.draw(model);
    }
}