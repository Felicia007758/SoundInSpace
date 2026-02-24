#pragma once
#include "SineVoice.h"
#include "ofMain.h"
 
class SynthEngine {
public:
	void setup(int sampleRate) {
		this->sampleRate = sampleRate;
 
		// Setup three different voices
		voice1.setup(sampleRate);
		voice2.setup(sampleRate);
		voice3.setup(sampleRate);
 
		// Give them different base characteristics
		voice1.setAmplitude(0.0f);
		voice2.setAmplitude(0.0f);
		voice3.setAmplitude(0.0f);
 
		// Voice 1 - pure sine (already default)
 
		// Voice 2 - higher octave
		voice2.setFrequency(440.0f);
 
		// Voice 3 - lower octave
		voice3.setFrequency(110.0f);
	}
 
	void setFrequencyForAll(float baseFreq) {
		voice1.setFrequency(baseFreq);
		voice2.setFrequency(baseFreq * 2.0f); // Octave above
		voice3.setFrequency(baseFreq * 0.5f); // Octave below
	}
 
	void setAmplitudes(float amp1, float amp2, float amp3) {
		voice1.setAmplitude(amp1);
		voice2.setAmplitude(amp2);
		voice3.setAmplitude(amp3);
	}
 
	float process() {
		// Mix the three voices
		return (voice1.process() + voice2.process() + voice3.process()) * 0.3f; // Reduce volume to prevent clipping
	}
 
private:
	SineVoice voice1, voice2, voice3;
	float sampleRate;
};
#pragma once