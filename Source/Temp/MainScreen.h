#ifndef MAIN_SCREEN_H_INCLUDED
#define MAIN_SCREEN_H_INCLUDED

#include "Quad.h"

namespace Object 
{
    class MainScreen : public Quad
    {
    public:
        MainScreen(Texture::Atlas& textureAtlas);
        
        void setupTexture() override;
        
    private:
        int story = 0;
        std::vector<GLfloat> vertexPositions =
        {
            //Back
            -5, 0, 0,
            5, 0, 0,
            5, 10, 0,
            -5, 10, 0,

            //Right-Side
            -5, 0, 1,
            -5, 0, 0,
            -5, 10, 0,
            -5, 10, 1,

            //Front
            5, 0, 1,
            -5, 0, 1,
            -5, 10, 1,
            5, 10, 1,

            //Left
            5, 0, 0,
            5, 0, 1,
            5, 10, 1,
            5, 10, 0,

            //Top
            5, 10, 1,
            -5, 10, 1,
            -5, 10, 0,
            5, 10, 0,

            //Bottom
            5, 0, 0,
            -5, 0, 0,
            -5, 0, 1,
            5, 0, 1
        };


        std::vector<GLuint> indices =
        {
            0, 1, 2,
            2, 3, 0,

            4, 5, 6,
            6, 7, 4,

            8, 9, 10,
            10, 11, 8,

            12, 13, 14,
            14, 15, 12,

            16, 17, 18,
            18, 19, 16,

            20, 21, 22,
            22, 23, 20
        };
    };    
}



#endif