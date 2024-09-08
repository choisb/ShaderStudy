#version 410

uniform sampler2D parrotTex;
uniform vec4 multiply;
uniform vec4 add;

in vec2 fragUV;
out vec4 outCol;

void main()
{
    outCol = texture(parrotTex, fragUV) * multiply + add; // mad 최적화 가능한 구문.
}
