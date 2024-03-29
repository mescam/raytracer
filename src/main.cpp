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
#include "materials/Transparent.h"
#include "Light.h"
#include "Settings.h"

#include <ctime>

int main(int argc, char** argv) {
    srand(time(0));
    timespec begin, end;
    clock_gettime(CLOCK_REALTIME, &begin);
    //let the journey begin
    Scene sampleScene = Scene();
    Reflective red(Color(1.0f, 0.0f, 0.0f), 0, 0.4, 1, 300, 0.3),
          green(Color(0.0f, 1.0f, 0.0f), 0, 0.4, 1, 300, 0.3),
          blue(Color(0.0f, 0.0f, 1.0f), 0, 0.4, 1, 300, 0.3),
          gray(Color(0.7f, 0.7f, 0.7f), 0, 0.4, 0, 0, 0.0),
          white(Color(1.0f, 1.0f, 1.0f), 0, 0.4, 0, 300, 1);

    Transparent whiteT(Color(1.0f, 1.0f, 1.0f), 0, 0.1, 0, 0, 0.3, 1.05, 0.9);

    sampleScene.addObject(new Sphere(Vector3(-4, 0, 0), 2, red));
    sampleScene.addObject(new Sphere(Vector3(4, 0, 0), 2, green));
    sampleScene.addObject(new Sphere(Vector3(0, 0, 3), 2, blue));
    sampleScene.addObject(new Sphere(Vector3(0, -2, -2), 1, whiteT));
    sampleScene.addObject(new Plane(Vector3(0, 0, 4), Vector3(0, 0, -1), gray));

    Camera* camera = new PinholeCamera(Vector3(0, 1,-8), Vector3(0,0,0), Vector3(0,-1, 1), 1.0);

    sampleScene.addObject(new Light(Vector3(0, 5, -5), 1.0, Color(1.0f, 1.0f, 1.0f)));
    sampleScene.addObject(new Light(Vector3(0, -5, -5), 1.0, Color(1.0f, 1.0f, 1.0f)));

    printf("Rendering scene to image with resolution %dx%d and SSAA = %d. Please wait, it may take some time...\n",OUTPUT_RESOLUTION_X,OUTPUT_RESOLUTION_Y,SSAA_SAMPLES);

    Raytracer test;
    Image* img = test.raytrace(sampleScene, camera,
    	                       OUTPUT_RESOLUTION_X, OUTPUT_RESOLUTION_Y);
    img->render();
    clock_gettime(CLOCK_REALTIME, &end);

    printf("Image generated in %fs\n", (double) (end.tv_sec - begin.tv_sec)
    +1.e-9*(end.tv_nsec - begin.tv_nsec));
    return 0;
}
