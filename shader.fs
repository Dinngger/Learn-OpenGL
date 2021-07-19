#version 330 core

out vec4 FragColor;
in vec2 TexCoord;

void main()
{
    FragColor = vec4(1.0, TexCoord.xy, 1.0);
}
