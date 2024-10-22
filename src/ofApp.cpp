#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofDisableArbTex(); // (레거시 지원용)텍스처의 스크린 픽셀 좌표 기능 비활성화. UV사용시 필요
	ofLogToConsole();
	torusMesh.load("mesh/torus.ply");
	normalShader.load("shader/vertex/mesh.vert", "shader/fragment/normal_vis.frag");

}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofEnableDepthTest();

	cam.pos = glm::vec3(0, 0, 1);
	cam.fov = glm::radians(90.0f);
	const float aspect = 1024.0f / 768.0f;

	const glm::mat4 model = glm::rotate(1.0f, glm::vec3(1.f)) * glm::scale(glm::vec3(0.5f));
	const glm::mat4 view = glm::inverse(glm::translate(cam.pos));
	const glm::mat4 proj = glm::perspective(cam.fov, aspect, 0.01f, 10.0f);

	const glm::mat4 mvp = proj * view * model;

	normalShader.begin();
	normalShader.setUniformMatrix4f("mvp", mvp);
	torusMesh.draw();
	normalShader.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key)
	{
	case 'v':
		ofSetLogLevel(ofLogLevel::OF_LOG_VERBOSE);
		break;
	case 'n':
		ofSetLogLevel(ofLogLevel::OF_LOG_NOTICE);
		break;

	default:
		break;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}


//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
