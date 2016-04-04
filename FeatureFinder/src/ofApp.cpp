#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(30);

	grabber.setup(480, 320, true);
	image.load("enemy.png");
	haarFinder.setup("haarcascade_frontalface_default.xml");
}

//--------------------------------------------------------------
void ofApp::update(){
	grabber.update();

	if (grabber.isFrameNew()) {
		haarFinder.findHaarObjects(grabber.getPixels(), 100, 100);
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	grabber.draw(0, 0);

	ofNoFill();
	for (int i = 0; i < haarFinder.blobs.size(); i++) {
		ofRectangle blobBoundingRect = haarFinder.blobs[i].boundingRect;

		ofDrawRectangle(blobBoundingRect.x, blobBoundingRect.y, 
						blobBoundingRect.width, blobBoundingRect.height);
		image.draw(blobBoundingRect.x, blobBoundingRect.y,
					blobBoundingRect.width, blobBoundingRect.height);
}
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
