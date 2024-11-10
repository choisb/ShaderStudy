#pragma once

#include "ofMain.h"
struct CameraData
{
	glm::vec3 pos;
	glm::vec3 right;
	float angle;
	float fov;
	float aspect;
	float nearPlan;
	float farPlan;
};

struct DirectionalLight {
	glm::vec3 direction;
	glm::vec3 color;
	float intensity;

	glm::vec3 getLightDireciton() { return glm::normalize(direction * -1.0f); }
	glm::vec3 getLightColor() { return color * intensity; }
};

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

	ofShader diffuseShader;
	ofMesh torusMesh;
	CameraData cam;
	DirectionalLight dirLight;
};
