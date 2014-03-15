#ifndef _ORTHOGONAL_CAMERA_H_
#define _ORTHOGONAL_CAMERA_H_

#include <cmath>

#include "Camera.h"

class OrthogonalCamera: public Camera {
public:
    Vector3 eyePosition;
    Vector2 size;
    double angle;
public:
    OrthogonalCamera(Vector3 eyePosition, Vector2 size, double angle): eyePosition(eyePosition), size(size), angle(angle) {
        // empty
    }
    Ray getRayTo(Vector2 location);
};

#endif //_ORTHOGONAL_CAMERA_H_