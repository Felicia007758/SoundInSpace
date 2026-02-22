#pragma once
#include "ofMain.h"

struct SpatialParams {
	float pitch;
	float brightness;
	float amplitude;
};

class SpatialMapper {
public:
	SpatialParams map(float x, float y, float speed,
		float width, float height) {

		SpatialParams params;

		// Pitch: left (low) → right (high)
		params.pitch = ofMap(x, 0, width, 100, 800, true);

		// Brightness: top (bright) → bottom (dark)
		params.brightness = ofMap(y, 0, height, 1.0, 0.0, true);

		// Amplitude: slow → quiet, fast → loud
		params.amplitude = ofClamp(speed * 0.01f, 0.0f, 0.8f);

		return params;
	}
};
