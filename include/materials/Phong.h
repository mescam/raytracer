#ifndef _PHONG_H_
#define _PHONG_H_

#include "Material.h"
#include "Color.h"

class Phong : public Material {
public:
    Color materialColor;
    double diffuseCoeff;
    double specular;
    double specularExp;

    Phong(Color color, double diffuse, double spec, double specExp) : materialColor(color), diffuseCoeff(diffuse), specular(spec), specularExp(specExp) {
    }

    Color shade(Raytracer &tracer, HitInfo &info);
    double phongFactor(Vector3 direction, Vector3 normal, Vector3 cameraDir);

};
#endif