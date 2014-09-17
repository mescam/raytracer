#include "materials/PerfectDiffuse.h"
#include "Light.h"

Color PerfectDiffuse::shade(Raytracer &tracer, HitInfo &hit) {
    Color total = Color(0.1f, 0.1f, 0.1f);
    for (Light* light : hit.scene->lights) {
        Vector3 lightPos = light->sample();
        Vector3 inDir = (lightPos - hit.hitPoint).getNormalized();
        double diffuseFactor = Vector3::dot(inDir, hit.normal);

        if (diffuseFactor < 0)
            continue;
        if (hit.scene->isObstacleBetween(hit.hitPoint, lightPos))
            continue;


        total = total + light->color * materialColor * diffuseFactor;
    }

    return total;
}
