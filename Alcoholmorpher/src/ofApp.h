#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofEvent.h"

#define MESH_WIDTH 50
#define MESH_HEIGHT 50
#define MESH_SIZE 10

#define IMAGE_WIDTH 580
#define IMAGE_HEIGHT 3369

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void exit();


		ofSerial serial;
		ofVideoGrabber grabber;
		ofxCvHaarFinder haarFinder;
		ofMesh mesh;
		ofImage image;
		

		int value;



		
		
};
