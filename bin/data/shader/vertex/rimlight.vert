#version 410

layout (location = 0) in vec3 pos;
layout (location = 2) in vec3 nrm;

uniform mat4 mvp; 
uniform mat4 invTransModel;
uniform mat4 model;

out vec3 fragNrm;
out vec3 fragWorldPos;

void main(){
	gl_Position = mvp * vec4(pos, 1.0);
	fragNrm = (invTransModel * vec4(nrm, 0.0)).xyz; // normal 벡터를 world 공간으로 변환 필요.
    fragWorldPos = (model * vec4(pos, 1.0)).xyz;
}