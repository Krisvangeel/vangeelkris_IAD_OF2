#include "ofApp.h"



void ofApp::setup() {
	serial.setup("COM7", 9600);
	value = 0;
	ofSetFrameRate(30);
	grabber.setup(800, 800, true);
	image.load("28-128.png");
	haarFinder.setup("haarcascade_frontalface_default.xml");

	for (int y = 0; y < MESH_HEIGHT; y++) {
		for (int x = 0; x < MESH_WIDTH; x++) {
			ofPoint vertex = ofPoint((x - MESH_WIDTH / 2)*MESH_SIZE, (y - MESH_HEIGHT / 2)*MESH_SIZE, 0);
			mesh.addVertex(vertex);
			mesh.addTexCoord(ofPoint(x*(IMAGE_WIDTH / MESH_WIDTH), y*(IMAGE_HEIGHT / MESH_HEIGHT)));
			ofColor color = ofColor(255, 255, 255);
			mesh.addColor(color);
		}
	}

	for (int y = 0; y < MESH_HEIGHT - 1; y++) {
		for (int x = 0; x < MESH_WIDTH - 1; x++) {
			int vertex1 = x + MESH_WIDTH *y;
			int vertex2 = x + 1 + MESH_WIDTH *y;
			int vertex3 = x + MESH_WIDTH *(y + 1);
			int vertex4 = x + 1 + MESH_WIDTH *(y + 1);
			mesh.addTriangle(vertex1, vertex2, vertex3);
			mesh.addTriangle(vertex2, vertex4, vertex3);
		}

	}
}


void ofApp::update() {
	if (serial.isInitialized() && serial.available() > 0)
	{
		value = serial.readByte();
		serial.flush();
	}

	ofLog() << value;

	grabber.update();

	if (grabber.isFrameNew()) {
		haarFinder.findHaarObjects(grabber.getPixels(), 100, 100);
	}
	if (value > 100) {
		for (int y = 0; y < MESH_WIDTH; y++) {
			for (int x = 0; x < MESH_WIDTH; x++) {
				int index = x + MESH_WIDTH*y;
				ofPoint vertex = mesh.getVertex(index);
				vertex.z = ofNoise(x * 0.05, y * 0.05, ofGetElapsedTimef() * 0.5) * 100;
				mesh.setVertex(index, vertex);
			}
		}
	}

}

void ofApp::draw() {
	ofBackground(ofColor::black);
	grabber.draw(0, 0);

	ofNoFill();
	for (int i = 0; i < haarFinder.blobs.size(); i++) {
		ofRectangle blobBoundingRect = haarFinder.blobs[i].boundingRect;

		//ofDrawRectangle(blobBoundingRect.x, blobBoundingRect.y,
		//	blobBoundingRect.width, blobBoundingRect.height);

		if (value > 100) {
			image.draw(blobBoundingRect.x, blobBoundingRect.y,
				blobBoundingRect.width, blobBoundingRect.height);
			image.bind();
			mesh.drawFaces();
			image.unbind();
		}
	}

	ofDrawBitmapString(ofToString(value), 50, 50);


}


void ofApp::exit() {
	serial.close();

}

