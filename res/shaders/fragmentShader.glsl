#version 330 core

in vec2 outTexCoord;

out vec4 FragColor;

uniform sampler2D ourTexture;

void main(){
    FragColor = texture(ourTexture, outTexCoord);
}