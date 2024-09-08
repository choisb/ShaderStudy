#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofDisableArbTex(); // (레거시 지원용)텍스처의 스크린 픽셀 좌표 기능 비활성화. UV사용시 필요

	quad.addVertex(glm::vec3(-1.0f, -1.0f, 0.0f));
	quad.addVertex(glm::vec3(-1.0f, 1.0f, 0.0f));
	quad.addVertex(glm::vec3(1.0f, 1.0f, 0.0f));
	quad.addVertex(glm::vec3(1.0f, -1.0f, 0.0f));

	quad.addTexCoord(glm::vec2(0.0f, 0.0f));
	quad.addTexCoord(glm::vec2(0.0f, 1.0f));
	quad.addTexCoord(glm::vec2(1.0f, 1.0f));
	quad.addTexCoord(glm::vec2(1.0f, 0.0f));

	ofIndexType indices[6] = { 0,1,2,2,3,0 };
	quad.addIndices(indices, 6);

	shader.load("shader/scrolling_uv.vert","shader/texture.frag");

	image.load("texture/parrot.png");
	image.getTexture().setTextureWrap(GL_REPEAT,GL_REPEAT);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	shader.begin();
	shader.setUniformTexture("parrotTex", image, 0);
	shader.setUniform1f("time", ofGetElapsedTimef());
	quad.draw();
	shader.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
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
