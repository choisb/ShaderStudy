#version 410

layout (location = 0) in vec3 pos;
layout (location = 3) in vec2 uv;

out vec2 fragUV;

uniform mat4 transform;

void main()
{
    gl_Position = transform * vec4(pos, 1.0);
    fragUV = vec2(uv.x, 1.0 - uv.y); // opengl은 이미지가 하단부터 저장되어 있음을 가정하기 때문에, y 값을 반전
}