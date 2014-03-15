#include "materials/PerfectDiffuse.h"

Color PerfectDiffuse::radiance(PointLight &light, HitInfo &hit) {
    Vector3 direction = (light.position - hit.hitPoint).getNormalized();
    double diffuseFactor = Vector3::dot(direction, hit.normal);

    if(diffuseFactor < 0) {
        return Color(0.0f, 0.0f, 0.0f); //return black
    }

    return light.color * materialColor * diffuseFactor;
}

