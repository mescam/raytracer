#include "materials/Transparent.h"
#include "Vectors.h"

Color Transparent::shade(Raytracer &tracer, HitInfo &info) {
    // phong shading
    Color result = direct.shade(tracer, info);

    Vector3 camDir = -info.ray.getDirection();
    Ray reflectedRay = Ray(info.hitPoint, Vector3::reflect(camDir, info.normal));
    Color reflColor = color * reflection;

    double cosIncAngle = Vector3::dot(info.normal, camDir);
    double eta = (cosIncAngle) > 0 ? refraction : 1 / refraction;
    double refrCoeff = refractionCoeff(eta, cosIncAngle);


    if(isTotalInternalReflection(refrCoeff)) {
        result = result + tracer.shadeRay(*(info.scene), reflectedRay, info.depth);
        return result;
    }

    // transparency goes here!
    Ray transmited = getTransmissionDirection(info.hitPoint, camDir, info.normal,
                                              eta, sqrt(refrCoeff), cosIncAngle);
    Color transmissionColor = getTransmissionColor(eta);

    result = result + reflColor * tracer.shadeRay(*(info.scene), reflectedRay, info.depth);
    result = result + transmissionColor * tracer.shadeRay(*(info.scene), transmited, info.depth);

    return result;
}

bool Transparent::isTotalInternalReflection(double refrCoeff) {
    return refrCoeff < 0;
}

double Transparent::refractionCoeff(double eta, double cosIncAngle) {
    return 1 - (1 - cosIncAngle * cosIncAngle) / (eta * eta);
}

Ray Transparent::getTransmissionDirection(Vector3 hitPoint, Vector3 camDir, 
                                          Vector3 normal, double eta, 
                                          double cosTrAngle, 
                                          double cosIncAngle) {
    if (cosIncAngle < 0) {
        normal = -normal;
        cosIncAngle = -cosIncAngle;
    }

    Vector3 dir = -camDir / eta - normal * (cosTrAngle - cosIncAngle / eta);
    return Ray(hitPoint, dir);
}

Color Transparent::getTransmissionColor(double eta) {
    return ((Color(1.0f, 1.0f, 1.0f) * transmission) / (eta * eta));
}