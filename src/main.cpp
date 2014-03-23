#include <iostream>
#include "Vectors.h"
#include "Color.h"
#include "Figure.h"
#include "Image.h"
#include "Scene.h"
#include "Camera.h"
#include "Raytracer.h"
#include "cameras/OrthogonalCamera.h"
#include "cameras/PinholeCamera.h"
#include "figures/Sphere.h"
#include "figures/Plane.h"
#include "materials/PerfectDiffuse.h"
#include "materials/Phong.h"
#include "materials/Reflective.h"
#include "PointLight.h"

int main(int argc, char** argv) {
    //let the journey begin
    Scene sampleScene = Scene();
    Reflective red(Color(1.0f, 0.0f, 0.0f), 0.4, 1, 300, 0.3),
          green(Color(0.0f, 1.0f, 0.0f), 0.4, 1, 300, 0.3),
          blue(Color(0.0f, 0.0f, 1.0f), 0.4, 1, 300, 0.3),
          gray(Color(0.7f, 0.7f, 0.7f), 0.4, 0, 0, 0);

    sampleScene.addObject(new Sphere(Vector3(-4,0,0),2, red));
    sampleScene.addObject(new Sphere(Vector3(4,0,0),2, green));
    sampleScene.addObject(new Sphere(Vector3(0,0,3),2, blue));
    sampleScene.addObject(new Plane(Vector3(0, -2, 0), Vector3(0, 1, 0), gray));

    Camera* camera = new PinholeCamera(Vector3(0,1,-8),Vector3(0,0,0),Vector3(0,-1,1),1.0);

    sampleScene.addObject(new PointLight(Vector3(0, 5, -5), Color(1.0f, 1.0f, 1.0f)));

    Raytracer test;
    Image* img = test.raytrace(sampleScene,camera,800,800);
    img->render();
    return 0;
}
