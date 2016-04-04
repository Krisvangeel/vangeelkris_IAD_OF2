#include "spring.h"

spring::spring(particles* firstParticle, particles* secondParticle) {
	first = firstParticle;
	second = secondParticle;
	length = DEFAULT_LENGTH;
}

void spring::draw() {
	ofSetColor(ofColor::white);
	ofDrawLine(first->position, second->position);
}

void spring::update() {
	float distance = first->position.distance(second->position);

	ofVec3f acceleration = second->position - first->position;
	acceleration.normalize();
	acceleration *= (distance - length) / DEFAULT_LENGTH;

	first->speed += acceleration;
	second->speed -= acceleration;
}