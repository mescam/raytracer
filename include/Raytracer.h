#ifndef _RAYTRACER_H_
#define _RAYTRACER_H_

#include "Image.h"

class Raytracer {
public:
    Raytracer() {}
    Image raytrace(Scene scene, Camera camera, int w, int h) {
        Image img(w,h);
        for(int x = 0; x < w, x++) {
            for (int y = 0; y < h; y++) {
                Vector2 pictureCoordinates = Vector2(((x + 0.5) / (double)w) * 2 - 1),((y + 0.5) / (double)h) * 2 - 1);
                Ray ray = camera.getRayTo(pictureCoordinates);
                HitInfo info = scene.traceRay(ray);
                Color color;
                if (info.HitObject) {
                    color = info.color;
                } else {
                    color = scene.backgroundColor;
                }
                img.setPixel(x,y,color);
            }
        }
        return img;
    }
};

#endif //_RAYTRACER_H_