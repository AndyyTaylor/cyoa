#ifndef MASTER_H_INCLUDED
#define MASTER_H_INCLUDED

#include "Simple.h"

namespace Renderer
{
    class Master
    {
    public:
        void clear();
        void update();
        void draw(const Model& model);
        
    private:
        Simple m_simpleRenderer;
    };
}


#endif