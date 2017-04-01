#version 410

out vec4 colour;

in vec2 passTextureCoords;
in vec3 vertexPositions;

uniform sampler2D ourTexture;

uniform float goodness;

void main()
{
    colour = texture(ourTexture, passTextureCoords);
    if (colour[2] > 0 && colour[2] < 1) {
        colour[3] = colour[2];
        colour[2] = 0;
    }
    if (colour[2] == 1 || colour[3] < 1) {
        if (vertexPositions[1] > goodness/10) { 
            colour = vec4(1*colour[3], 0, 0, 1);
        } else {
            colour = vec4(0, 1*colour[3], 0, 1);
        }
    } 
    
}