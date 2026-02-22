#pragma once
#include "ofMain.h"

class SineVoice {
public:
	void setup(float sampleRate) {
		this->sampleRate = sampleRate;
		phase = 0.0f;
	}

	void setFrequency(float freq) {
		frequency = freq;
	}

	void setAmplitude(float amp) {
		amplitude = amp;
	}

	float process() {
		float sample = sin(TWO_PI * phase) * amplitude;
		phase += frequency / sampleRate;
		if (phase >= 1.0f) phase -= 1.0f;
		return sample;
	}

private:
	float phase = 0.0f;
	float frequency = 220.0f;
	float amplitude = 0.0f;
	float sampleRate = 44100.0f;
};
