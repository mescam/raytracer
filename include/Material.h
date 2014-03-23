#ifndef _MATERIAL_H_
#define _MATERIAL_H_

#include "HitInfo.h"
#include "Raytracer.h"

class Material {
public:
    virtual Color shade(Raytracer &tracer, HitInfo &info) = 0;
};

#endif