#ifndef _FIGURE_H_
#define _FIGURE_H_

#include "Color.h"
#include "Ray.h"

class Figure {
public:
	Color color;

	Figure(Color c) : color(c) {};
	virtual bool testHit(Ray ray, double distance) = 0;
};

#endif