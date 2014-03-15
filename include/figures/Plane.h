#ifndef _PLANE_H_
#define _PLANE_H_

#include "Figure.h"
#include "Vectors.h"

class Plane : public Figure {
public:
    Vector3 point; //punkt przez który płaszczyzna przechodzi
    Vector3 normal; //normalna do płaszczyzny

    Plane(Vector3 point, Vector3 normal, Material &m) : Figure(m), point(point), normal(normal){

    }

    virtual bool testHit(Ray ray, double &distance, Vector3 &normal);
};

#endif