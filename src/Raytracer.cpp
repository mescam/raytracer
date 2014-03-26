#include "Raytracer.h"
#include "Material.h"
#include "Figure.h"
#include "Settings.h"

#include <vector>
#include <cmath>

/*
Image* Raytracer::raytrace(Scene scene, Camera* camera, int w, int h) {
    Image* img = new Image(w,h);
    for(int x = 0; x < w; x++) {
        for (int y = 0; y < h; y++) {
            //Vector2 pictureCoordinates = Vector2((((x + 0.5)/(double)w) * 2 - 1),(((y + 0.5)/(double)h)* 2 - 1));
            //Ray ray = camera->getRayTo(pictureCoordinates);
            Vector2 pc1 = Vector2((((x + 0.5)/(double)w) * 2 - 1),(((y + 0.5)/(double)h)* 2 - 1));
            Vector2 pc2 = Vector2(((((x+1) + 0.5)/(double)w) * 2 - 1),((((y+1) + 0.5)/(double)h)* 2 - 1));
            Vector2 diff = Vector2(abs(pc1.x - pc2.x),abs(pc1.y - pc2.y));
            Vector2 size = Vector2(diff.x / (double)MSAA_SAMPLES,diff.y / (double)MSAA_SAMPLES);
            std::vector<Color> msaaColors;
            for (int i = 0; i < MSAA_SAMPLES; i++) {
                for (int j = 0; j < MSAA_SAMPLES; j++) {
                    Vector2 coords = Vector2(pc1.x + (size.x*i),pc1.y + (size.y*j));
                    //pictureCoordinates.x -= ((pictureCoordinates.x / (double)MSAA_SAMPLES) * (double)i);
                    //pictureCoordinates.y -= ((pictureCoordinates.y / (double)MSAA_SAMPLES) * (double)j);
                    Ray ray = camera->getRayTo(coords);
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
*/

/*
Image* Raytracer::raytrace(Scene scene, Camera* camera, int w, int h) {
    Image* img = new Image(w*MSAA_SAMPLES,h*MSAA_SAMPLES);
    int ss_w = w*MSAA_SAMPLES;
    int ss_h = h*MSAA_SAMPLES;
    for(int x = 0; x < ss_w; x++) {
        for (int y = 0; y < ss_h; y++) {
            Vector2 pictureCoordinates = Vector2((((x + 0.5)/(double)ss_w) * 2 - 1),(((y + 0.5)/(double)ss_h)* 2 - 1));
            Ray ray = camera->getRayTo(pictureCoordinates);
            img->setPixel(x,y, shadeRay(scene, ray, 0));
        }
    }
    if (MSAA_SAMPLES > 1) {
        Image* img2 = new Image(w,h);
        for (int x = 0; x < w; x++) {
            for (int y = 0; y < h; y++) {
                Color finalColor = Color(0.0f,0.0f,0.0f,0.0f);
                for (int i = 0; i < MSAA_SAMPLES; i++) {
                    for (int j = 0; j < MSAA_SAMPLES; j++) {
                        finalColor.r += img->getPixel(x*MSAA_SAMPLES+i,y*MSAA_SAMPLES+j).r;
                        finalColor.g += img->getPixel(x*MSAA_SAMPLES+i,y*MSAA_SAMPLES+j).g;
                        finalColor.b += img->getPixel(x*MSAA_SAMPLES+i,y*MSAA_SAMPLES+j).b;
                        finalColor.a += img->getPixel(x*MSAA_SAMPLES+i,y*MSAA_SAMPLES+j).a;
                    }
                }
                finalColor.r /= (double)(MSAA_SAMPLES*MSAA_SAMPLES);
                finalColor.g /= (double)(MSAA_SAMPLES*MSAA_SAMPLES);
                finalColor.b /= (double)(MSAA_SAMPLES*MSAA_SAMPLES);
                finalColor.a /= (double)(MSAA_SAMPLES*MSAA_SAMPLES);
                img2->setPixel(x,y,finalColor);
            }
        }
        return img2;
    } else
        return img;
}
*/

Image* Raytracer::raytrace(Scene scene, Camera* camera, int w, int h) {
    Image* img = new Image(w,h);
    if (SSAA_SAMPLES > 1) {
        int ss_w = w*SSAA_SAMPLES;
        int ss_h = h*SSAA_SAMPLES;
        for (int x = 0; x < w; x++) {
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
