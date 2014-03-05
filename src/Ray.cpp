#include "Ray.h"

Vector3 Ray::getOrigin() {
	return this->origin;
}

Vector3 Ray::getDirection() {
	return this->direction;
}

void Ray::setOrigin(Vector3 v) {
	this->origin = v;
}

void Ray::setDirection(Vector3 v) {
	this->direction = v.getNormalized();
}