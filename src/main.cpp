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

int main(int argc, char** argv) {
    //let the journey begin
    Scene sampleScene = Scene(Color(1.5f,1.5f,1.5f,1.0f));

    PerfectDiffuse red(Color(1.0f,0.0f,0.0f,1.0f)), 
                   green(Color(0.0f,1.0f,0.0f,1.0f)),
                   blue(Color(0.0f,0.0f,1.0f,1.0f)),
                   gray(Color(0.7f, 0.7f, 0.7f));

    sampleScene.addObject(new Sphere(Vector3(-2.5,0,0),2, red));
    sampleScene.addObject(new Sphere(Vector3(2.5,0,0),2, green));
    sampleScene.addObject(new Sphere(Vector3(0,0,2.5),2, blue));
    sampleScene.addObject(new Plane(Vector3(0, -2, 0), Vector3(0, 1, 0), gray));

    Camera* camera = new PinholeCamera(Vector3(0,1,-8),Vector3(0,0,0),Vector3(0,-1,1),1.0);

    Raytracer test;
    Image* img = test.raytrace(sampleScene,camera,256,256);
    img->render();
    return 0;
}
