#version 410

out vec4 colour;              // The fragment shader is used to change the colour of certain points

in vec2 passTextureCoords;    // Passed in by the vertex shader
in vec3 vertexPositions;

uniform sampler2D ourTexture; // Uniform variables are like static globals for shaders

uniform float goodness;

void main()
{
    colour = texture(ourTexture, passTextureCoords);
    if (colour[2] > 0 && colour[2] < 1) {           // Handles any opaque points
        colour[3] = colour[2];
        colour[2] = 0;
    }
    if (colour[2] == 1 || colour[3] < 1) {          // Find points that were opaque or blue and replaces their
        if (vertexPositions[1] > goodness/10) {     // primary colour with green or red depending on their height
            colour = vec4(1*colour[3], 0, 0, 1);    // (used for the scoring system)
        } else {
            colour = vec4(0, 1*colour[3], 0, 1);
        }
    } 
    
}