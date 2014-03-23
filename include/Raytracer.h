#ifndef _RAYTRACER_H_
#define _RAYTRACER_H_

#include "Image.h"
#include "Scene.h"
#include "Ray.h"
#include "Camera.h"
#include "Color.h"

class Raytracer {
private:
    int maxDepth;
public:
    Raytracer(int maxDepth = 5) : maxDepth(maxDepth) {}
    Image* raytrace(Scene scene, Camera* camera, int w, int h);
    Color shadeRay(Scene &scene, Ray &ray, int depth = 0);
};

#endif //_RAYTRACER_H_