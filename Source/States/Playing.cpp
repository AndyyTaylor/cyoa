#include "Playing.h"

#include <iostream>
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics.hpp>
#include "../Display.h"

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
        
        // These lines are the reason you spawn literally ontop of the screen
        // but at least that forces you to experiment with moving
        m_mainScreen.position.z -= 2;
        m_mainScreen.position.y -= 2;
    }

    void Playing::input(Camera& camera)
    {
        m_mainScreen.input();
    }

    void Playing::update(Camera& camera, float dt)
    {
        //m_quad.rotation += .1;
        camera.input(dt);
    }

    void Playing::draw(Renderer::Master& renderer)
    {
        renderer.draw(m_mainScreen);
        renderer.setGood(m_mainScreen.getGoodness());
    }
}