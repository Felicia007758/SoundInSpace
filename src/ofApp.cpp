#include "ofApp.h"

void ofApp::setup() {
	ofSetFrameRate(60);

	int sampleRate = 44100;
	int bufferSize = 512;

	synth.setup(sampleRate);

	ofSoundStreamSettings settings;
	settings.setOutListener(this);
	settings.sampleRate = sampleRate;
	settings.numOutputChannels = 2;
	settings.numInputChannels = 0;
	settings.bufferSize = bufferSize;

	soundStream.setup(settings);

	prevMouse = glm::vec2(mouseX, mouseY);
}

void ofApp::update() {
	glm::vec2 currentMouse(mouseX, mouseY);
	float speed = glm::distance(currentMouse, prevMouse);

	SpatialParams params = mapper.map(
		mouseX, mouseY, speed,
		ofGetWidth(), ofGetHeight());

	synth.setPitch(params.pitch);
	synth.setAmplitude(params.amplitude);

	prevMouse = currentMouse;
}

void ofApp::draw() {
	ofBackground(0);

	float radius = ofMap(mouseY, 0, ofGetHeight(), 60, 10, true);
	ofSetColor(255);
	ofDrawCircle(mouseX, mouseY, radius);
}

void ofApp::audioOut(ofSoundBuffer & buffer) {
	synth.audioOut(buffer.getBuffer().data(),
		buffer.getNumFrames(),
		buffer.getNumChannels());
}
