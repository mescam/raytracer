#ifndef _PINHOLECAMERA_H_
#define _PINHOLECAMERA_H_

#include "Camera.h"
#include "OrthonormalBasis.h"
#include "Vectors.h"

class PinholeCamera : public Camera {
public:
    OrthonormalBasis onb;
    Vector3 origin;
    double distance;

    PinholeCamera(Vector3 origin, Vector3 lookAt, Vector3 up, double distance);
    Ray getRayTo(Vector2 location);
    Vector3 rayDirection(Vector2 v);
};

#endif