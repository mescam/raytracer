#ifndef _RAYTRACER_H_
#define _RAYTRACER_H_

#include "Image.h"
#include "Scene.h"
#include "Ray.h"
#include "Camera.h"

class Raytracer {
public:
    Raytracer() {}
    Image* raytrace(Scene scene, Camera* camera, int w, int h);
};

#endif //_RAYTRACER_H_