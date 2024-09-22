#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

private:
	void buildMesh(ofMesh& mesh, float w, float h, glm::vec3 pos);
	void buildSpriteMesh();
	void buildRenderTransform(glm::mat4& outTransform, const glm::vec3& trans, float rot, const glm::vec3& scale);
	//ofMesh charMesh;
	ofImage alienSprite;

	//ofMesh backgroundMesh;
	ofImage backgroundImg;
	glm::mat4 backgroundTransform;

	//ofMesh cloudMesh;
	ofImage cloudImg;
	float cloudMaxAlpha = 1.0f;

	glm::mat4 cloudATransform;
	glm::mat4 cloudBTransform;

	//ofMesh sunMesh;
	ofImage sunImg;
	float sumMaxAlpha = 1.0f;
	glm::mat4 sunTransform;

	ofShader alphaTestShader;
	ofShader blendModeShader;
	ofShader spritesheetShader;

	int spriteFrameRate = 0;
	glm::vec2 spriteSize;

	glm::mat4 charTransform;
	glm::vec3 charPos;
	float charSpeed = 0.0f;

	ofMesh spriteMesh;
};
