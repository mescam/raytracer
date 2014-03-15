#ifndef _MATERIAL_H_
#define _MATERIAL_H_

#include "HitInfo.h"
#include "PointLight.h"

class Material {
public:
    virtual Color radiance(PointLight &light, HitInfo &info) = 0;
};

#endif