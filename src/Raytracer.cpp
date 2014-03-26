#include "Raytracer.h"
#include "Material.h"
#include "Figure.h"

#include <vector>

#ifndef MSAA_SAMPLES
    #define MSAA_SAMPLES 8
#endif

Image* Raytracer::raytrace(Scene scene, Camera* camera, int w, int h) {
    Image* img = new Image(w,h);
    for(int x = 0; x < w; x++) {
        for (int y = 0; y < h; y++) {
            //Vector2 pictureCoordinates = Vector2((((x + 0.5)/(double)w) * 2 - 1),(((y + 0.5)/(double)h)* 2 - 1));
            //Ray ray = camera->getRayTo(pictureCoordinates);
            std::vector<Color> msaaColors;
            for (int i = 1; i <= MSAA_SAMPLES; i++) {
                for (int j = 1; j <= MSAA_SAMPLES; j++) {
                    Vector2 pictureCoordinates = Vector2((((x + 0.5)/(double)w) * 2 - 1),(((y + 0.5)/(double)h)* 2 - 1));
                    pictureCoordinates.x = pictureCoordinates.x / (double)MSAA_SAMPLES * (double)i;
                    pictureCoordinates.y = pictureCoordinates.y / (double)MSAA_SAMPLES * (double)j;
                    Ray ray = camera->getRayTo(pictureCoordinates);
                    msaaColors.push_back(shadeRay(scene,ray,0));
                }
            }
            Color finalColor = Color(0.0f,0.0f,0.0f,0.0f);
            for (int s = 0; s < msaaColors.size(); s++) {
                finalColor.r += msaaColors[s].r;
                finalColor.g += msaaColors[s].g;
                finalColor.b += msaaColors[s].b;
                finalColor.a += msaaColors[s].a;
            }
            finalColor.r /= (double)msaaColors.size();
            finalColor.g /= (double)msaaColors.size();
            finalColor.b /= (double)msaaColors.size();
            finalColor.a /= (double)msaaColors.size();
            img->setPixel(x,y,finalColor);
            //img->setPixel(x,y, shadeRay(scene, ray, 0));
        }
    }
    return img;
}

Color Raytracer::shadeRay(Scene &scene, Ray &ray, int depth) {
    if(depth > maxDepth)
        return Color(0.0f, 0.0f, 0.0f);

    HitInfo info = scene.traceRay(ray);
    if(info.hitObject == nullptr) {
        return scene.getBackgroundColor();
    }
    info.depth = depth + 1;
    Material &m = info.hitObject->material;

    return m.shade(*this, info);
}
