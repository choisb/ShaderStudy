#version 410

uniform sampler2D parrotTex;
uniform sampler2D checkerTex;

in vec2 fragUV;
out vec4 outCol;

void main()
{
	vec4 parrot = texture(parrotTex, fragUV);
	vec4 checker = texture(checkerTex, fragUV);

	outCol = mix(checker, parrot, checker.r);
}  
