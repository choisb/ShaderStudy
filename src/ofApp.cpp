#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofDisableArbTex(); // (���Ž� ������)�ؽ�ó�� ��ũ�� �ȼ� ��ǥ ��� ��Ȱ��ȭ. UV���� �ʿ�
	ofDisableAlphaBlending();
	ofEnableDepthTest(); // ���� ���۸� ���� �����׸�Ʈ ���̴� �ܰ迡�� ���� �׽�Ʈ�� �ϵ��� Ȱ��ȭ. ���̴� ���ؽ��� z�� ���.

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