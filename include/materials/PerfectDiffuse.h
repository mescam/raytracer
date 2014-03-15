#ifndef _PERFECTDIFFUSE_H_
#define _PERFECTDIFFUSE_H_
#include "Material.h"

class PerfectDiffuse : public Material {
public:
    Color materialColor;
    PerfectDiffuse(Color materialColor) : materialColor(materialColor) {
    }
    Color radiance(PointLight &light, HitInfo &hit);
};

#endif