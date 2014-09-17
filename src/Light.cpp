#include "Light.h"
#include <cmath>
#include <cstdlib>
#include <cstdio>

Vector3 Light::sample() {
    if(radius == 0)
        return this->center;

    Vector2 sample((float)rand()/RAND_MAX, (float)rand()/RAND_MAX);

    return this->center + (sampleToSphere(sample) * radius);
}

Vector3 Light::sampleToSphere(Vector2 sample) {
    double z = 2 * sample.x - 1;
    double t = 2 * 3.14 * sample.y;
    double r = sqrt(1 - z*z);
    // printf("z=%f t=%f r=%f\n", z, t, r);
    return Vector3(r*cos(t), r*sin(t), z);
}
