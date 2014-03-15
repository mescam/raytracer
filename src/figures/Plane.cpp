#include "figures/Plane.h"

bool Plane::testHit(Ray ray, double &distance) {
    if(Vector3::dot(ray.getDirection(), normal) == 0.0) {
        return false;
    }

    double t = Vector3::dot(point - ray.getOrigin(), normal) / Vector3::dot(ray.getDirection(), normal);
    if (t > Ray::epsilon) {
        distance = t;
        return true;
    }
    return false;
}