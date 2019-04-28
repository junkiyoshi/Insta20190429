#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(39);

	this->font.loadFont("fonts/Kazesawa-Bold.ttf", 28, true, true, true);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	int radius = 300;
	for (int y = -300; y <= 300; y += 50) {

		for (int deg = 0; deg < 360; deg += 5) {

			auto location = glm::vec3(0, y, -radius);
			auto rotation_y = glm::rotate(glm::mat4(), (float)(deg * DEG_TO_RAD), glm::vec3(0, 1, 0));
			location = glm::vec4(location, 0) * rotation_y;

			ofPushMatrix();
			ofTranslate(location);
			ofRotateY(180 - deg);

			ofSetColor(39, ofMap(location.z, -radius, radius, 0, 255));

			char noise_value = ofMap(ofNoise(location.x * 0.008, location.y * 0.008, location.z * 0.008, ofGetFrameNum() * 0.003), 0, 1, 'A', 'Z');
			this->font.drawString({ noise_value }, 0, 0);

			ofPopMatrix();
		}
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}