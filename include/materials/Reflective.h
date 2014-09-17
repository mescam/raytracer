#ifndef _REFLECTIVE_H_
#define _REFLECTIVE_H_
#include "Material.h"
#include "materials/Phong.h"
#include "Light.h"

class Reflective : public Material {
private:
    Phong directLight;
    double reflectivity;
    Color materialColor;
    Color reflectionColor;

public:
    Reflective(
        Color materialColor, double ambient, double diffuse, double specular,
        double exponent, double reflectivity) : directLight(Phong(materialColor, ambient, diffuse, specular, exponent)),
        reflectivity(reflectivity), materialColor(materialColor) { };
        //nawet nie wiem jak to złamać...
    Color shade(Raytracer &tracer, HitInfo &info);


};
#endif
