#pragma once

#include "ofMain.h"
#include "Parameters.h"
#include "Particle.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		ofFbo fbo;

		float time;
		vector<Particle>particles;

		Parameters parameters;


};
