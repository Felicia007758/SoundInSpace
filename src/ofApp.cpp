#include "ofApp.h"

class SoundParticle {
public:
	glm::vec2 pos;
	glm::vec2 vel;
	float life;
	float size;

	void update() {
		pos += vel;
		life -= 0.02f; 
	}

	void draw() {
		ofSetColor(255, 255, 255, life * 255);
		ofDrawCircle(pos, size * life);
	}
};

vector<SoundParticle> particles;

void ofApp::setup() {
	ofBackground(0);
	ofSetFrameRate(60);
	ofSetCircleResolution(64);

	int sampleRate = 44100;
	int bufferSize = 512;

	synth.setup(sampleRate);
	mapper.setup(ofGetWidth(), ofGetHeight());

	soundStream.printDeviceList();
	soundStream.setup(this, 2, 0, sampleRate, bufferSize, 4);

	prevMouse = glm::vec2(ofGetMouseX(), ofGetMouseY());
}

void ofApp::update() {
	glm::vec2 mousePos(ofGetMouseX(), ofGetMouseY());
	float amp1 = mapper.mouseYToAmplitude(mousePos.y); 

	float distanceFromCenter = mapper.distanceToEffect(mousePos);
	float panPosition = mapper.positionToPan(mousePos);

	float amp2 = ofMap(mousePos.x, 0, ofGetWidth(), 0.0f, 0.8f, true);

	float amp3 = distanceFromCenter * 0.5f;

	float baseFreq = mapper.mouseXToFrequency(mousePos.x);
	synth.setFrequencyForAll(baseFreq);

	synth.setAmplitudes(amp1, amp2, amp3);

	if (amp1 > 0.3f && ofGetFrameNum() % 3 == 0) {
		SoundParticle p;
		p.pos = mousePos;
		float angle = ofRandom(TWO_PI);
		float speed = ofMap(amp1, 0.3f, 1.0f, 1.0f, 4.0f); 
		p.vel = glm::vec2(cos(angle) * speed, sin(angle) * speed);
		p.life = 1.0f;
		p.size = ofMap(amp1, 0, 1, 5, 25); 
		particles.push_back(p);
	}

	float mouseSpeed = glm::distance(mousePos, prevMouse);
	if (mouseSpeed > 10.0f && ofGetFrameNum() % 2 == 0) {
		SoundParticle p;
		p.pos = mousePos;
		float angle = ofRandom(TWO_PI);
		p.vel = glm::vec2(cos(angle) * 2, sin(angle) * 2);
		p.life = 0.8f;
		p.size = ofMap(mouseSpeed, 10, 50, 3, 15, true);
		particles.push_back(p);
	}
	for (int i = particles.size() - 1; i >= 0; i--) {
		particles[i].update();
		if (particles[i].life <= 0) {
			particles.erase(particles.begin() + i);
		}
	}
	prevMouse = mousePos;
}
void ofApp::draw() {
	glm::vec2 mousePos(ofGetMouseX(), ofGetMouseY());
	ofSetColor(40, 40, 40);
	for (int x = 0; x < ofGetWidth(); x += 50) {
		ofDrawLine(x, 0, x, ofGetHeight());
	}
	for (int y = 0; y < ofGetHeight(); y += 50) {
		ofDrawLine(0, y, ofGetWidth(), y);
	}
	for (auto & p : particles) {
		p.draw();
	}
	float circleSize = ofMap(mousePos.y, 0, ofGetHeight(), 20, 200);
	float brightness = ofMap(mousePos.y, 0, ofGetHeight(), 255, 100);
	float hue = ofMap(mousePos.x, 0, ofGetWidth(), 0, 255);
	ofSetColor(brightness, brightness, 255, 200);
	ofDrawCircle(mousePos, circleSize);
	ofSetColor(255, 255, 255, 100);
	float pulse = sin(ofGetElapsedTimef() * 5) * 10;
	ofNoFill();
	ofSetLineWidth(2);
	ofDrawCircle(mousePos, circleSize + 20 + pulse);
	ofDrawCircle(mousePos, circleSize + 40 + pulse * 2);

	ofSetColor(255, 100, 100);
	ofSetLineWidth(3);
	ofDrawLine(mousePos.x, 0, mousePos.x, ofGetHeight());

	ofSetColor(100, 255, 100);
	ofDrawLine(0, mousePos.y, ofGetWidth(), mousePos.y);

	float amp1 = mapper.mouseYToAmplitude(mousePos.y);
	float amp2 = ofMap(mousePos.x, 0, ofGetWidth(), 0.0f, 1.0f, true);
	float amp3 = mapper.distanceToEffect(mousePos);

	
	ofFill();
	ofSetColor(255, 0, 0, 200); 
	ofDrawRectangle(20, 20, amp1 * 200, 20);

	ofSetColor(0, 255, 0, 200); 
	ofDrawRectangle(20, 50, amp2 * 200, 20);

	ofSetColor(0, 0, 255, 200); 
	ofDrawRectangle(20, 80, amp3 * 200, 20);
	ofSetColor(255);
	ofDrawBitmapString("SOUND IN SPACE", 20, 130);
	ofDrawBitmapString("Move mouse: X = frequency, Y = volume", 20, 150);
	ofDrawBitmapString("Red = Y position | Green = X position | Blue = Distance from center", 20, 170);
	ofDrawBitmapString("Circle size = volume | Color = frequency", 20, 190);
	ofDrawBitmapString("Particles appear with loud sounds and fast movement!", 20, 210);
}

void ofApp::audioOut(ofSoundBuffer & buffer) {
	for (size_t i = 0; i < buffer.getNumFrames(); i++) {
		float sample = synth.process();
		float pan = mapper.positionToPan(prevMouse);

		float leftGain = (1 - pan) * 0.5f;
		float rightGain = (pan + 1) * 0.5f;

		buffer[i * buffer.getNumChannels()] = sample * leftGain;
		buffer[i * buffer.getNumChannels() + 1] = sample * rightGain;
	}
}
