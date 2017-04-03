#version 410

layout (location = 0) in vec3 inVertexPosition; // Passed in by the shader program
layout (location = 1) in vec2 inTextureCoords;

out vec2 passTextureCoords;     // Passed to the fragment shader
out vec3 vertexPositions;

uniform mat4 viewMatrix;        // mat4 = 4 dimensional matrix
uniform mat4 modelMatrix;
uniform mat4 projMatrix;

void main()
{
    // proj * view * model seems to be a 'given' of opengl programming
    // I think I learn matrices later this year so this'll make more sense then
    gl_Position = projMatrix * viewMatrix * modelMatrix * vec4 (inVertexPosition.x, inVertexPosition.y, inVertexPosition.z, 1.0);
    
    // Doesn't change variables passed to it, only gl_position
    passTextureCoords = inTextureCoords;
    vertexPositions = inVertexPosition;
}