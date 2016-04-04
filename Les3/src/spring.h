#pragma once
#include "particles.h"

#define DEFAULT_LENGTH 100

class spring {
public:
	spring(particles* first, particles* second);
	void draw();
	void update();

private:
	particles* first;
	particles* second;
	int length;
}
