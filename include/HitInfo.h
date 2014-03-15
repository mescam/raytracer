#ifndef _HIT_INFO_H_
#define _HIT_INFO_H_

#include "Color.h"
#include "Ray.h"

class Scene;
class Figure;

class HitInfo {
public:
    Figure *hitObject = nullptr;
    Scene *scene = nullptr;
    Color color;
    Vector3 normal;
    Vector3 hitPoint;
    Ray ray;

public:
    HitInfo() {

    }
};

#endif //_HIT_INFO_H_