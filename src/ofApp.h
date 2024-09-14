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

	void buildMesh(ofMesh& mesh, float w, float h, glm::vec3 pos);
private:
	ofMesh charMesh;
	ofImage alienSprite;

	ofMesh backgroundMesh;
	ofImage backgroundImg;

	ofMesh cloudMesh;
	ofImage cloudImg;
	float cloudMaxAlpha = 1.0f;

	ofMesh sunMesh;
	ofImage sunImg;
	float sumMaxAlpha = 1.0f;

	ofShader alphaTestShader;
	ofShader blendModeShader;
	ofShader spritesheetShader;

	int spriteFrameRate = 0;
	glm::vec2 spriteSize;
};
