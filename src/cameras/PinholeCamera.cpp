#include "cameras/PinholeCamera.h"

PinholeCamera::PinholeCamera(Vector3 origin, Vector3 lookAt, 
    Vector3 up, double distance) : onb(OrthonormalBasis(origin, lookAt, up)) {
    this->origin = origin;
    this->distance = distance;
}

Ray PinholeCamera::getRayTo(Vector2 location) {
    return Ray(origin, rayDirection(location));
}

Vector3 PinholeCamera::rayDirection(Vector2 v) {
    return this->onb * Vector3(v.x, v.y, -distance);
}
