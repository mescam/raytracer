#include "materials/Reflective.h"

Color Reflective::shade(Raytracer &tracer, HitInfo &info) {
    //direct lights from Phong
    Color directColor = directLight.shade(tracer, info);
    //calculate ray to camera and create an instance of Ray
    Vector3 toCam = -info.ray.getDirection();
    Vector3 reflDir = Vector3::reflect(toCam, info.normal);
    Ray reflRay = Ray(info.hitPoint, reflDir);
    //trace it!
    Color traced = tracer.shadeRay(*(info.scene), reflRay);

    return directColor + traced * reflectionColor * reflectivity;
}