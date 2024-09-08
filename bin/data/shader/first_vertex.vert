#version 410

layout ( location = 0 ) in vec3 pos;
layout ( location = 1 ) in vec3 color;

out vec4 fragCol;

void main()
{
	gl_Position = vec4(pos, 1.0);
	fragCol = vec4(color, 1.0);
}