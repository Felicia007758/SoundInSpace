#pragma once
#include "ofMain.h"
#include "sineVoice.h"

class SynthEngine {
public:
	void setup(float sampleRate) {
		this->sampleRate = sampleRate;
		sine.setup(sampleRate);
	}

	void setPitch(float pitch) {
		sine.setFrequency(pitch);
	}

	void setAmplitude(float amp) {
		sine.setAmplitude(amp);
	}

	void audioOut(float * output, int bufferSize, int nChannels) {
		for (int i = 0; i < bufferSize; i++) {
			float sample = sine.process();
			for (int c = 0; c < nChannels; c++) {
				output[i * nChannels + c] = sample;
			}
		}
	}

private:
	float sampleRate;
	SineVoice sine;
};
