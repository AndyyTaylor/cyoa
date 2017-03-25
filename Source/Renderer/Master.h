#ifndef MASTER_H_INCLUDED
#define MASTER_H_INCLUDED

#include "Simple.h"

class Quad;

namespace Renderer
{
    class Master
    {
    public:
        void clear();
        
        void update(const Camera& camera);
        
        void draw(const Quad& model);
        
    private:
        Simple m_simpleRenderer;
    };
}

#endif