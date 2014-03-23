#include "Raytracer.h"
#include "Material.h"
#include "Figure.h"

Image* Raytracer::raytrace(Scene scene, Camera* camera, int w, int h) {
    Image* img = new Image(w,h);
    for(int x = 0; x < w; x++) {
        for (int y = 0; y < h; y++) {
            Vector2 pictureCoordinates = Vector2((((x + 0.5)/(double)w) * 2 - 1),(((y + 0.5)/(double)h)* 2 - 1));
            Ray ray = camera->getRayTo(pictureCoordinates);
            
            img->setPixel(x,y, shadeRay(scene, ray, 0));
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
