#include "materials/PerfectDiffuse.h"
#include "PointLight.h"

Color PerfectDiffuse::shade(Raytracer &tracer, HitInfo &hit) {
    Color total = Color(0.0f, 0.0f, 0.0f);
    for (PointLight* light : hit.scene->lights) {
        Vector3 inDir = (light->position - hit.hitPoint).getNormalized();
        double diffuseFactor = Vector3::dot(inDir, hit.normal);
        if (diffuseFactor < 0)
            continue;
        if(hit.scene->isObstacleBetween(hit.hitPoint, light->position))
            continue;

        total = total + light->color * materialColor * diffuseFactor;
    }

    return total;
}