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
        
        // Yeah not great variable names but anyway
        // this is for the scoring system
        void setGood(float goodness)
        {
            good = goodness;
        }
        
    private:
        Simple m_simpleRenderer;
        float good = 0;
    };
}

#endif