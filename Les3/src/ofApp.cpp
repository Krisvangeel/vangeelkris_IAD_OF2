#include "ofApp.h"

#include "ofApp.h"

void ofApp::setup() {
  ofSetFrameRate(60);
  ofBackground(0);
}

void ofApp::update() {
  ofSetWindowTitle(ofToString(ofGetFrameRate(), 0) + "FPS");

  // bereken de effecten van alle Springs
  for (int i = 0; i < springs.size(); i++) {
    springs[i]->update();
  }

  // bereken de nieuwe positie & snelheid van de Particles
  for (int i = 0; i < particles.size(); i++) {
    particles[i]->update();
  }
}

void ofApp::draw() {
  ofSetWindowTitle(ofToString(ofGetFrameRate(), 0) + "FPS");

  if (drawParticles) {
    for (int i = 0; i < particles.size(); i++) {
      particles[i]->draw();
    }
  }

  if (drawSprings) {
    for (int i = 0; i < springs.size(); i++) {
      springs[i]->draw();
    }
  }

  // have selected a Particle: draw temporary Spring from Particle to mouse position
  if (selectedFirstParticle) {
    ofSetColor(ofColor::white);
    ofDrawLine(firstParticle->position, ofPoint(mouseX, mouseY));
  }
}

void ofApp::mousePressed(int x, int y, int button) {
  // did we click on an existing particle?
  particles* clickedParticle = findParticle(x, y);
  if (clickedParticle != NULL) {  // yes, clicked on a particle
    if (selectedFirstParticle) {  // do we already have a Particle selected?
      // yes, so we clicked the second Particle ...
      particles* secondParticle = clickedParticle;

      // ... create a Spring between the two selected Particles
      spring* spring = new spring(firstParticle, secondParticle);
      springs.push_back(spring);
      selectedFirstParticle = false;
    } else {  // no Particle selected yet, so this was the first one
      firstParticle = clickedParticle;
      selectedFirstParticle = true;
    }
  } else {  // we clicked empty space, create a new Particle
    addParticle(x, y);
  }
}

void ofApp::keyPressed(int key) {
  ofLog() << "Pressed " << key << endl;
  if (key == 's') {
    drawSprings = !drawSprings;
  } else if (key == 'p') {
    drawParticles = !drawParticles;
  }
}

void ofApp::addParticle(int x, int y) {
  particles* particle = new Particle(x, y);
  particles.push_back(particle);
}

particles* ofApp::findParticle(int x, int y) {
  for (int i = 0; i < particles.size(); i++) {
    particles* particles = particles[i];
    if (particles->position.distance(ofPoint(x, y)) < particles->radius) {
      return particles;
    }
  }
  return NULL;
}