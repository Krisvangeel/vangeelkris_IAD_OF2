
#pragma once

#include "ofMain.h"

#include "particles.h"
#include "spring.h"

class ofApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();

	void mousePressed(int x, int y, int button);
	void keyPressed(int key);

private:
	void addParticle(int x, int y);
	particles* findParticle(int x, int y);

	vector<particles*> particles;
	vector<spring*> springs;

	particles* firstParticle;
	bool selectedFirstParticle;

	bool drawParticles = true;
	bool drawSprings = true;
};