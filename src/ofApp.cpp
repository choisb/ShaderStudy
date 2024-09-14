#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofDisableArbTex(); // (���Ž� ������)�ؽ�ó�� ��ũ�� �ȼ� ��ǥ ��� ��Ȱ��ȭ. UV���� �ʿ�

	buildMesh(charMesh, 0.1f, 0.2f, glm::vec3(0.0f, -0.2f, 0.0f));
	alienImg.load("texture/alien.png");
	
	buildMesh(backgroundMesh, 1.0f, 1.0f, glm::vec3(0.0f, 0.0f, 0.5f));
	backgroundImg.load("texture/forest.png");
	
	buildMesh(cloudMesh, 0.25f, 0.16f, glm::vec3(-0.55f, 0.0f, 0.0f));
	cloudImg.load("texture/cloud.png");
	cloudMaxAlpha = 0.9f;

	buildMesh(sunMesh, 1.0, 1.0, glm::vec3(0.0f, 0.0f, 0.4f));
	sunImg.load("texture/sun.png");

	alphaTestShader.load("shader/vertex/passthrough.vert","shader/fragment/alphaTest.frag");
	blendModeShader.load("shader/vertex/passthrough.vert","shader/fragment/blendMode.frag");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	ofEnableDepthTest(); // ���� ���۸� ���� �����׸�Ʈ ���̴� �ܰ迡�� ���� �׽�Ʈ�� �ϵ��� Ȱ��ȭ. ���̴� ���ؽ��� z�� ���.
	ofDisableBlendMode();
	alphaTestShader.begin();

	alphaTestShader.setUniformTexture("tex", backgroundImg, 0);
	backgroundMesh.draw();

	alphaTestShader.setUniformTexture("tex", alienImg, 0);
	charMesh.draw();

	alphaTestShader.end();

	
	ofDisableDepthTest();	// �����忡���� ������ �κ��� ���ʿ��ϰ� Depth Test�� �����ϴ� ���� ���� ���ؼ� ��Ȱ��ȭ.
	blendModeShader.begin();
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ALPHA);
	
	blendModeShader.setUniformTexture("tex", cloudImg, 0);
	blendModeShader.setUniform1f("maxAlpha", cloudMaxAlpha);
	cloudMesh.draw();

	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
	blendModeShader.setUniformTexture("tex", sunImg, 0);
	blendModeShader.setUniform1f("maxAlpha", 1.0f);
	sunMesh.draw();

	blendModeShader.end();

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