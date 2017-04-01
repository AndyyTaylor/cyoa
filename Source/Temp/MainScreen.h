#ifndef MAIN_SCREEN_H_INCLUDED
#define MAIN_SCREEN_H_INCLUDED

#include "Quad.h"
#include <map>



namespace Object 
{
    struct Room
    {
        int id;
        std::vector<int> options;
    };
    
    class MainScreen : public Quad
    {
    public:
        MainScreen(Texture::Atlas& textureAtlas);
        
        void setupTexture() override;
        
        GLuint getStory();
        
        void input();
        void readStory();
        
        float getGoodness()
        {
            return goodness;
        }
        
        void updateCurrentRoom()
        {
            for (int i = 0; i < all_rooms.size(); i++)
            {
                if (all_rooms[i].id == story)
                {
                    current_room = all_rooms[i];
                    return;
                }
            }
        }
        
    private:
        int story = 2; // Would be using GLuint's because of their cross platform and unsigned nature but dunno how to convert strings to them
        bool released = true;
        float goodness = 100;
        float total_good = 0;
        float actual_good = 0;
        Room current_room;
        std::vector<Room> all_rooms;
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