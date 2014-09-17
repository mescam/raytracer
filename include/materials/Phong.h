#ifndef _PHONG_H_
#define _PHONG_H_

#include "Material.h"
#include "Color.h"

class Phong : public Material {
public:
    Color materialColor;
    double ambient;
    double diffuseCoeff;
    double specular;
    double specularExp;

    Phong(Color color, double ambient, double diffuse, double spec, double specExp) : materialColor(color), ambient(ambient), diffuseCoeff(diffuse), specular(spec), specularExp(specExp) {
    }

    Color shade(Raytracer &tracer, HitInfo &info);
    double phongFactor(Vector3 direction, Vector3 normal, Vector3 cameraDir);

};
#endif
