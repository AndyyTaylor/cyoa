#include "Playing.h"

#include <iostream>
#include <SFML/System/Clock.hpp>

#include "../Renderer/Master.h"

#include "../Camera.h"

namespace State
{
    sf::Clock clock;

    Playing::Playing(Application& application)
    :   Game_State  (application)
    ,   m_texture   ("mctex", 1024, 200)
    ,   m_mainScreen      (m_texture)
    {
        m_texture.bind();

        m_mainScreen.position.z -= 2;
        m_mainScreen.position.y -= 2;
    }

    void Playing::input(Camera& camera)
    {

    }

    void Playing::update(Camera& camera, float dt)
    {
        //m_quad.rotation += .1;
        camera.input(dt);
    }

    void Playing::draw(Renderer::Master& renderer)
    {
        renderer.draw(m_mainScreen);
    }
}