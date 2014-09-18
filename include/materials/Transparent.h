#ifndef _TRANSPARENT_H_
#define _TRANSPARENT_H_

#include "Material.h"
#include "Color.h"
#include "Ray.h"
#include "materials/Phong.h"
#include "Vectors.h"

class Transparent : public Material {
private:
    double refractionCoeff(double eta, double cosIncAngle);
    bool isTotalInternalReflection(double refrCoeff);

    Ray getTransmissionDirection(Vector3 hitPoint, Vector3 camDir, Vector3 normal,
                                 double eta, double cosTrAngle, double cosIncAngle);
    Color getTransmissionColor(double eta);
public:
    Phong direct;
    Color color;
    double reflection;
    double refraction;
    double transmission;

    Transparent(Color color, double ambient, double diffuse, double specular,
                double exponent, double reflection, double refraction,
                double transmission) : direct(color, ambient, diffuse, specular,
                exponent), color(color), reflection(reflection), 
                refraction(refraction), transmission(transmission) {}

    Color shade(Raytracer &tracer, HitInfo &info);
};

#endif