#ifndef _RAY_H_
#define _RAY_H_

#include <cfloat>

#include "Vectors.h"

class Ray {
public:
	static constexpr double epsilon = 0.000001;
	static constexpr double infinity = DBL_MAX;

	Vector3 origin;
	Vector3 direction;
public:
	Ray(Vector3 origin, Vector3 direction): origin(origin), direction(direction.getNormalized()) {

	}

	Ray() {};

	Vector3 getOrigin();
	Vector3 getDirection();

	void setOrigin(Vector3 v);
	void setDirection(Vector3 v);
};

#endif //_RAY_H_