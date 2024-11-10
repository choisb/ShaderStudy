#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofDisableArbTex(); // (레거시 지원용)텍스처의 스크린 픽셀 좌표 기능 비활성화. UV사용시 필요
	ofLogToConsole();
	torusMesh.load("mesh/torus.ply");
	diffuseShader.load("shader/vertex/rimlight.vert", "shader/fragment/rimlight.frag");

	dirLight.direction = glm::normalize(glm::vec3(0.0f, -1.0f, 0.0f));
	dirLight.color = glm::vec3(1.0f, 1.0f, 1.0f);
	dirLight.intensity = 1.0f;

	cam.pos = glm::vec3(0.0f, 0.75f, 1.0f);
	cam.fov = glm::radians(90.0f);
	cam.angle = glm::radians(-45.f);
	cam.right = glm::vec3(1.0f, 0.0f, 0.0f);
	cam.aspect = 1024.0f / 768.0f;
	cam.nearPlan = 0.01f;
	cam.farPlan = 10.0f;
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofEnableDepthTest();

	const glm::mat4 model = glm::rotate(glm::radians(90.0f), glm::vec3(1.0f, 0.0, 0.0f)) * glm::scale(glm::vec3(0.5f));
	const glm::mat4 view = glm::inverse(glm::translate(cam.pos) * glm::rotate(cam.angle, cam.right));
	const glm::mat4 proj = glm::perspective(cam.fov, cam.aspect, cam.nearPlan, cam.farPlan);

	const glm::mat4 mvp = proj * view * model;
	const glm::mat4 invTransModel = glm::transpose(glm::inverse(glm::mat3(model))); // 법선 벡터를 월드공간으로 변환하기 위해 역전치행렬 사용. (https://dev-sbee.tistory.com/248 참고)

	diffuseShader.begin();
	diffuseShader.setUniformMatrix4f("mvp", mvp);
	diffuseShader.setUniformMatrix4f("invTransModel", invTransModel);
	diffuseShader.setUniformMatrix4f("model", model);
	diffuseShader.setUniform3f("meshCol", glm::vec3(1, 0, 0));
	diffuseShader.setUniform3f("lightDir", dirLight.getLightDireciton());
	diffuseShader.setUniform3f("lightCol", dirLight.getLightColor());
	diffuseShader.setUniform3f("cameraPos", cam.pos);
	torusMesh.draw();
	diffuseShader.end();
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
