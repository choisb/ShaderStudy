#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofDisableArbTex(); // (레거시 지원용)텍스처의 스크린 픽셀 좌표 기능 비활성화. UV사용시 필요
	ofDisableAlphaBlending();
	ofEnableDepthTest(); // 깊이 버퍼를 만들어서 프래그먼트 세이더 단계에서 깊이 테스트를 하도록 활성화. 깊이는 버텍스의 z값 사용.

	buildMesh(charMesh, 0.1f, 0.2f, glm::vec3(0.0f, -0.2f, 0.0f));
	buildMesh(backgroundMesh, 1.0f, 1.0f, glm::vec3(0.0f, 0.0f, 0.5f));

	alienImg.load("texture/alien.png");
	backgroundImg.load("texture/forest.png");

	alphaTestShader.load("shader/vertex/passthrough.vert","shader/fragment/alphaTest.frag");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	alphaTestShader.begin();
	
	alphaTestShader.setUniformTexture("tex", alienImg, 0);
	charMesh.draw();

	alphaTestShader.setUniformTexture("tex", backgroundImg, 0);
	backgroundMesh.draw();

	alphaTestShader.end();
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


void ofApp::buildMesh(ofMesh& mesh, float w, float h, glm::vec3 pos)
{
	float verts[] = { -w + pos.x, -h + pos.y, pos.z,
		-w + pos.x, h + pos.y, pos.z,
		w + pos.x, h + pos.y, pos.z,
		w + pos.x, -h + pos.y, pos.z };
	float uvs[] = { 0,0, 0,1, 1,1, 1,0 };

	for (int i = 0; i < 4; ++i)
	{
		int idx = i * 3;
		int uvIdx = i * 2;
		mesh.addVertex(glm::vec3(verts[idx], verts[idx + 1], verts[idx + 2]));
		mesh.addTexCoord(glm::vec2(uvs[uvIdx], uvs[uvIdx + 1]));
	}

	ofIndexType indices[6] = {0,1,2,2,3,0};
	mesh.addIndices(indices, 6);
}