#ifndef _REFLECTIVE_H_
#define _REFLECTIVE_H_
#include "Material.h"
#include "materials/Phong.h"
#include "PointLight.h"

class Reflective : public Material {
private:
    Color materialColor;
    Phong directLight;
    double reflectivity;
    Color reflectionColor;
public:
    Reflective(
        Color materialColor, double diffuse, double specular, 
        double exponent, double reflectivity) : directLight(Phong(materialColor, diffuse, specular, exponent)), reflectivity(reflectivity), materialColor(materialColor) { };
        //nawet nie wiem jak to złamać...
    Color shade(Raytracer &tracer, HitInfo &info);


};
#endif