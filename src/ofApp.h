#pragma once
#include "audio/synthEngine.h"
#include "interaction/spartialMapper.h"
#include "ofMain.h"

class ofApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();

	void audioOut(ofSoundBuffer & buffer);

private:
	ofSoundStream soundStream;
	SynthEngine synth;
	SpatialMapper mapper;

	glm::vec2 prevMouse;
};
