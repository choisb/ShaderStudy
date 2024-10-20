#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofDisableArbTex(); // (���Ž� ������)�ؽ�ó�� ��ũ�� �ȼ� ��ǥ ��� ��Ȱ��ȭ. UV���� �ʿ�
	ofLogToConsole();

	alienSprite.load("texture/walk_sheet.png");
	charPos = glm::vec3(0.0f, -0.25f, 0.0f);
	backgroundImg.load("texture/forest.png");
	cloudImg.load("texture/cloud.png");
	cloudMaxAlpha = 0.9f;
	sunImg.load("texture/sun.png");

	alphaTestShader.load("shader/vertex/passthrough.vert","shader/fragment/alphaTest.frag");
	blendModeShader.load("shader/vertex/passthrough.vert","shader/fragment/blendMode.frag");
	spritesheetShader.load("shader/vertex/spritesheet.vert","shader/fragment/alphaTest.frag");

	spriteFrameRate = 18;
	spriteSize = glm::vec2(0.28f, 0.19f);
	buildSpriteMesh();
}

//--------------------------------------------------------------
void ofApp::update(){
	charPos.x += charSpeed * ofGetLastFrameTime();
}

//--------------------------------------------------------------
void ofApp::draw(){

	camera.position = glm::vec3(0.0f, 0.0f, 0.0f);
	const glm::mat4 viewMatrix = buildViewMatrix(camera);
	const glm::mat4 projMatrix = glm::ortho(-1.33f, 1.33f, -1.0f, 1.0f, 0.0f, 10.0f);
	const glm::mat4 projViewMatrix = projMatrix * viewMatrix;

	backgroundTransform = buildRenderTransform(glm::vec3(0.0f, 0.0f, 0.0f), 0.0f, glm::vec3(1.0f, 1.0f, 1.0f));
	charTransform = buildRenderTransform(charPos, 0.0f, glm::vec3(0.1f, 0.2f, 1.0f));
	cloudATransform = buildRenderTransform(glm::vec3(-0.5f, 0.0f, 0.0f), 0.0f, glm::vec3(0.25f, 0.16f, 1.0f));
	cloudBTransform = buildRenderTransform(glm::vec3(0.2f, 0.2f, 0.0f), 0.0f, glm::vec3(0.25f, 0.16f, 1.0f));
	ofEnableDepthTest(); // ���� ���۸� ���� �����׸�Ʈ ���̴� �ܰ迡�� ���� �׽�Ʈ�� �ϵ��� Ȱ��ȭ. ���̴� ���ؽ��� z�� ���.
	ofDisableBlendMode();
	spritesheetShader.begin();
	const float currentTime = ofGetElapsedTimef();
	const int spriteFrame = (int)(spriteFrameRate * currentTime) % 10;
	glm::vec2 spriteFrameOffset = glm::vec2(spriteFrame % 3, (int)(spriteFrame / 3));
	spritesheetShader.setUniformTexture("tex", alienSprite, 0);
	spritesheetShader.setUniform2f("size", spriteSize);
	spritesheetShader.setUniform2f("offset", spriteFrameOffset);
	spritesheetShader.setUniformMatrix4f("projView", projViewMatrix);
	spritesheetShader.setUniformMatrix4f("model", charTransform);
	spriteMesh.draw();
	spritesheetShader.end();

	alphaTestShader.begin();

	alphaTestShader.setUniformTexture("tex", backgroundImg, 0);
	alphaTestShader.setUniformMatrix4f("projView", projViewMatrix);
	alphaTestShader.setUniformMatrix4f("model", backgroundTransform);

	spriteMesh.draw();
	alphaTestShader.end();


	
	ofDisableDepthTest();	// �����忡���� ������ �κ��� ���ʿ��ϰ� Depth Test�� �����ϴ� ���� ���� ���ؼ� ��Ȱ��ȭ.
	blendModeShader.begin();
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ALPHA);
	
	blendModeShader.setUniformTexture("tex", cloudImg, 0);
	blendModeShader.setUniform1f("maxAlpha", cloudMaxAlpha);
	blendModeShader.setUniformMatrix4f("projView", projViewMatrix);
	blendModeShader.setUniformMatrix4f("model", cloudATransform);
	spriteMesh.draw();
	
	blendModeShader.setUniformMatrix4f("projView", projViewMatrix);
	blendModeShader.setUniformMatrix4f("model", cloudBTransform);
	spriteMesh.draw();
	
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
	blendModeShader.setUniformTexture("tex", sunImg, 0);
	blendModeShader.setUniform1f("maxAlpha", 0.5f);
	blendModeShader.setUniformMatrix4f("projView", projViewMatrix);
	blendModeShader.setUniformMatrix4f("model", sunTransform);

	spriteMesh.draw();
	
	blendModeShader.end();
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

	case ofKey::OF_KEY_RIGHT:
		charSpeed = 0.4f;
		break;

	default:
		break;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	switch (key)
	{
	case ofKey::OF_KEY_RIGHT:
		charSpeed = 0.0f;
		break;

	default:
		break;
	}
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


void ofApp::buildSpriteMesh()
{
	float verts[] = {-1.0f, -1.0f, 0.0f,
	-1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	1.0f, -1.0f, 0.0f 
	};
	float uvs[] = { 0,0, 0,1, 1,1, 1,0 };

	for (int i = 0; i < 4; ++i)
	{
		int idx = i * 3;
		int uvIdx = i * 2;
		spriteMesh.addVertex(glm::vec3(verts[idx], verts[idx + 1], verts[idx + 2]));
		spriteMesh.addTexCoord(glm::vec2(uvs[uvIdx], uvs[uvIdx + 1]));
	}
	ofIndexType indices[6] = { 0,1,2,2,3,0 };
	spriteMesh.addIndices(indices, 6);
}

glm::mat4 ofApp::buildRenderTransform(const glm::vec3& trans, float rot, const glm::vec3& scale)
{
	glm::mat4 ReturnTransform = glm::translate(trans);
	ReturnTransform = glm::rotate(ReturnTransform, rot, glm::vec3(0.0, 0.0, 1.0));
	ReturnTransform = glm::scale(ReturnTransform, scale);
	return ReturnTransform;
}

glm::mat4 ofApp::buildViewMatrix(const cameraData& camera)
{
	glm::mat4 ReturnTransform = glm::inverse(buildRenderTransform(camera.position, camera.rotation, glm::vec3(1.0f, 1.0f, 1.0f)));
	return ReturnTransform;
}
