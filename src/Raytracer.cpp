#include "Raytracer.h"
#include "Material.h"
#include "Figure.h"
#include "Settings.h"

#include <vector>
#include <cmath>

Image* Raytracer::raytrace(Scene scene, Camera* camera, int w, int h) {
    Image* img = new Image(w,h);
    if (SSAA_SAMPLES > 1) {
        int ss_w = w*SSAA_SAMPLES;
        int ss_h = h*SSAA_SAMPLES;
        #pragma omp parallel for
        for (int x = 0; x < w; x++) {
            #pragma omp parallel for
            for (int y = 0; y < h; y++) {
                Color finalColor = Color(0.0f,0.0f,0.0f,0.0f);
                for (int i = 0; i < SSAA_SAMPLES; i++) {
                    for (int j = 0; j < SSAA_SAMPLES; j++) {
                        Color sampleColor = Color(0.0f,0.0f,0.0f,0.0f);

                        Vector2 pictureCoordinates = Vector2(((((x*SSAA_SAMPLES) + i + 0.5)/(double)ss_w) * 2 - 1),((((y*SSAA_SAMPLES) + j + 0.5)/(double)ss_h)* 2 - 1));
                        Ray ray = camera->getRayTo(pictureCoordinates);
                        sampleColor = this->shadeRay(scene, ray, 0);
                        
                        finalColor.r += sampleColor.r;
                        finalColor.g += sampleColor.g;
                        finalColor.b += sampleColor.b;
                        finalColor.a += sampleColor.a;
                    }
                }
                finalColor.r /= pow(SSAA_SAMPLES,2.0);
                finalColor.g /= pow(SSAA_SAMPLES,2.0);
                finalColor.b /= pow(SSAA_SAMPLES,2.0);
                finalColor.a /= pow(SSAA_SAMPLES,2.0);

                img->setPixel(x,y,finalColor);
            }
        }
    }
    else {
        for(int x = 0; x < w; x++) {
            for (int y = 0; y < h; y++) {
                Vector2 pictureCoordinates = Vector2((((x + 0.5)/(double)w) * 2 - 1),(((y + 0.5)/(double)h)* 2 - 1));
                Ray ray = camera->getRayTo(pictureCoordinates);
                img->setPixel(x,y,this->shadeRay(scene, ray, 0));
            }
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
