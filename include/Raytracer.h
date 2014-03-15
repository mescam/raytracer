#ifndef _RAYTRACER_H_
#define _RAYTRACER_H_

#include "Image.h"
#include "Scene.h"
#include "Ray.h"
#include "Camera.h"
#include "Color.h"

class Raytracer {
public:
    Raytracer() {}
    Image* raytrace(Scene scene, Camera* camera, int w, int h);
    Color shadeRay(Scene &scene, Ray &ray);
};

#endif //_RAYTRACER_H_