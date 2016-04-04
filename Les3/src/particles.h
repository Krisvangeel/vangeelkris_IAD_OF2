#pragma once
#include "ofMain.h"

class particle {
public:
	particles(int x, int y);

	void update();
	void draw();

	ofPoint position;
	ofVec2f speed;
	int radius;
};
