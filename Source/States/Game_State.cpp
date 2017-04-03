#include "Game_State.h"


// GameStates are a great way of keeping a large application clean
// however in this example there will only be 'Playing'
namespace State
{
    Game_State::Game_State(Application& application)
    : m_application (&application)
    {
        
    }
}