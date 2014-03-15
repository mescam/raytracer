#ifndef _FIGURE_H_
#define _FIGURE_H_

#include "Color.h"
#include "Ray.h"
#include "Material.h"

class Figure {
public:
    Material &material;	
	Figure(Material &m) : material(m) {};
	virtual bool testHit(Ray ray, double &distance, Vector3 &normal) = 0;
};

#endif