#ifndef _LIGHT_H_
#define _LIGHT_H_
#include "Vectors.h"
#include "Color.h"

class Light {
public:
    Vector3 center;
    double radius;
    Color color;

    Light(Vector3 center, double radius, Color color) : center(center), radius(radius), color(color) {
    }

    Vector3 sample();

private:
    Vector3 sampleToSphere(Vector2 sample);


};
#endif
