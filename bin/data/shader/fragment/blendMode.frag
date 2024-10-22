#version 410

uniform sampler2D tex;
uniform float maxAlpha;

in vec2 fragUV;
out vec4 outCol;

void main()
{
    outCol = texture(tex, fragUV);
    outCol.a = min(outCol.a, maxAlpha);
}