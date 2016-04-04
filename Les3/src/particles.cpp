
#include "particles.h"

particle::particles(int x, int y) {
	position.set(x, y);
	radius = 40;
}



void particles::update() { position += speed; }

void particles::draw() {
	ofSetColor(0, 20, 180, 130);
	ofDrawCircle(position, radius);
}