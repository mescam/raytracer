#include "figures/Plane.h"

bool Plane::testHit(Ray ray, double &distance, Vector3 &normal) {
    if(Vector3::dot(ray.getDirection(), normal) == 0.0) {
        return false;
    }

    double t = Vector3::dot(point - ray.getOrigin(), normal) / Vector3::dot(ray.getDirection(), normal);
    if (t > Ray::epsilon) {
        distance = t;
        normal = this->normal;
        return true;
    }
    return false;
}