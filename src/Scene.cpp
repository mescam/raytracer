#include "Scene.h"

Color Scene::getBackgroundColor() {
    return this->backgroundColor;
}

void Scene::setBackgroundColor(Color c) {
    this->backgroundColor = c;
}

void Scene::addObject(Figure* object) {
    this->objects.push_back(object);
}

HitInfo Scene::traceRay(Ray ray) {
    HitInfo result;
    double minimalDistance = Ray::infinity;
    double hitDistance = 0;

    for (std::list<Figure*>::iterator it = this->objects.begin(); it != this->objects.end(); it++) {
        if ((*it)->testHit(ray,hitDistance) && hitDistance < minimalDistance) {
            minimalDistance = hitDistance;
            result.hitObject = true;
            result.color = (*it)->color;
        }
    }
    return result;
}