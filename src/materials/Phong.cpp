#include "materials/Phong.h"
#include <cmath>

Color Phong::radiance(PointLight &light, HitInfo &info) {
    Vector3 direction = (light.position - info.hitPoint).getNormalized();
    double diffFactor = Vector3::dot(direction, info.normal);

    if(diffFactor < 0)
        return Color(0.0f, 0.0f, 0.0f);

    Color result = light.color * materialColor * diffFactor * diffuseCoeff;

    double pFac = phongFactor(direction, info.normal, -info.ray.getDirection());
    if(pFac != 0) {
        result = result + materialColor * specular * pFac;
    }

    return result;
}

double Phong::phongFactor(Vector3 direction, Vector3 normal, Vector3 cameraDir) {
    Vector3 reflection = Vector3::reflect(direction, normal);
    double cosAngle = Vector3::dot(reflection, cameraDir);
    if(cosAngle <= 0)
        return 0;
    return pow(cosAngle, specularExp);
}