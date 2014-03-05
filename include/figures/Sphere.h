#ifndef _SPHERE_H_
#define _SPHERE_H_

#include "Figure.h"
#include "Vectors.h"

class Sphere : public Figure {
public:
    Vector3 center;
    double radius;

    Sphere(Vector3 center, double radius, Color c);
    bool testHit(Ray ray, double &distance);
};

#endif
