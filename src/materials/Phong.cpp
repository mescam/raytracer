#include "materials/Phong.h"
#include "Light.h"
#include <cmath>

Color Phong::shade(Raytracer &tracer, HitInfo &info) {
    Color total = Color(0.0f, 0.0f, 0.0f);
    for (Light *light : info.scene->lights) {
        // Vector3 inDir = (light->position - info.hitPoint).getNormalized();
        // double diffuseFactor = Vector3::dot(inDir, info.normal);
        //
        // if (diffuseFactor < 0)
        //     continue;
        //
        // if (info.scene->isObstacleBetween(info.hitPoint, light->position))
        //     continue;
        Vector3 lightPos = light->sample();
        Vector3 inDir = (lightPos - info.hitPoint).getNormalized();
        // printf("lightPos: %f %f %f\n", lightPos.x, lightPos.y, lightPos.z);
        // printf("inDir: %f %f %f\n", inDir.x, inDir.y, inDir.z);
        // printf("normal: %f %f %f\n", info.normal.x, info.normal.y, info.normal.z);
        double diffuseFactor = Vector3::dot(inDir, info.normal);

        if (diffuseFactor < 0)
            continue;
        if (info.scene->isObstacleBetween(info.hitPoint, lightPos)) {
            // printf("Nope :<\n");
            continue;
        }
        // printf("Hit!\n");
    //    printf("light color %f %f %f\n", light->color.r, light->color.g, light->color.b);
        Color result = light->color * materialColor * diffuseFactor * diffuseCoeff;
        // printf("result %f %f\n", diffuseFactor, diffuseCoeff);

        // double phFac = phongFactor(inDir, info.normal, -info.ray.getDirection());
        // if (phFac != 0) {
        //     result = result + materialColor * specular * phFac;
        // }

        total = total + result;

    }
    //printf("total %f %f %f\n", total.r, total.g, total.b);
    return total;
}

double Phong::phongFactor(Vector3 direction, Vector3 normal, Vector3 cameraDir) {
    Vector3 reflection = Vector3::reflect(direction, normal);
    double cosAngle = Vector3::dot(reflection, cameraDir);
    if(cosAngle <= 0)
        return 0;
    return pow(cosAngle, specularExp);
}
