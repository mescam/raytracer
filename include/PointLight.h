#ifndef _POINTLIGHT_H_
#define _POINTLIGHT_H_
#include "Vectors.h"
#include "Color.h"

class PointLight {
public:
    Vector3 position;
    Color color;
    
    PointLight(Vector3 position, Color color) : position(position), color(color) {

    }
};
#endif