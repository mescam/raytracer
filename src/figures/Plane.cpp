#include "figures/Plane.h"

bool Plane::testHit(Ray ray, double &distance, Vector3 &normal) {
    if(Vector3::dot(ray.getDirection(), normal)) {
        return false;
    }

    double t = Vector3::dot(point - ray.getOrigin(), this->normal) / Vector3::dot(ray.getDirection(), this->normal);
    if (t > Ray::epsilon) {
        distance = t;
        normal = this->normal;
        return true;
    }
    return false;
}