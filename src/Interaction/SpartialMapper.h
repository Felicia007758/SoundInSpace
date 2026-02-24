#pragma once
#include "ofMain.h"
class SpartialMapper {
public:
	void setup(int width, int height) {
		screenWidth = width;
		screenHeight = height;
	}

	float mouseYToAmplitude(float mouseY) {
		return ofMap(mouseY, 0, screenHeight, 1.0f, 0.0f, true);
	}

	float mouseXToFrequency(float mouseX) {
		return ofMap(mouseX, 0, screenWidth, 80.0f, 800.0f, true);
	}

	float positionToPan(glm::vec2 pos) {
		float centerX = screenWidth / 2;
		return ofMap(pos.x, 0, screenWidth, -1.0f, 1.0f, true);
	}

	float distanceToEffect(glm::vec2 pos) {
		glm::vec2 center(screenWidth / 2, screenHeight / 2);
		float distance = glm::distance(pos, center);
		float maxDistance = glm::distance(glm::vec2(0, 0), center);
		return ofMap(distance, 0, maxDistance, 0.0f, 1.0f, true);
	}

private:
	int screenWidth, screenHeight;
};

