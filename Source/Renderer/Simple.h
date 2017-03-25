#ifndef SIMPLE_H_INCLUDED
#define SIMPLE_H_INCLUDED

#include <vector>
#include <SFML/System/Clock.hpp>
#include "../Shaders/Simple_Shader.h"

class Quad;
class Camera;

namespace Renderer
{
    class Simple
    {
    public:
        void draw(const Quad& quad);
        
        void update(const Camera& camera);
        
    private:
        void prepare(const Quad& quad);
        
        std::vector<const Quad*> m_quads;
        
        Shader::Simple_Shader m_shader;
        sf::Clock m_clock;
    };
}


#endif