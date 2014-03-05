#ifndef _RAY_H_
#define _RAY_H_

#include <cfloat>

#include "Vectors.h"

class Ray {
	const double epsilon = 0.000001;
	const double infinity = DBL_MAX;

	Vector3 origin;
	Vector3 direction;

	Ray(Vector3 origin, Vector3 direction): origin(origin), direction(direction.getNormalized()) {

	}

	Vector3 getOrigin();
	Vector3 getDirection();

	void setOrigin(Vector3 v);
	void setDirection(Vector3 v);

};

#endif //_RAY_H_