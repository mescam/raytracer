#include "Scene.h"
#include "Figure.h"

Color Scene::getBackgroundColor() {
    return this->backgroundColor;
}

void Scene::setBackgroundColor(Color c) {
    this->backgroundColor = c;
}

void Scene::addObject(Figure* object) {
    this->objects.push_back(object);
}

void Scene::addObject(PointLight* light) {
    this->lights.push_back(light);
}

HitInfo Scene::traceRay(Ray ray) {
    HitInfo result;
    double minimalDistance = Ray::infinity;
    double hitDistance = 0;
    Vector3 normal;

    for (std::list<Figure*>::iterator it = this->objects.begin(); it != this->objects.end(); it++) {
        if ((*it)->testHit(ray, hitDistance, normal) && hitDistance < minimalDistance) {
            minimalDistance = hitDistance;
            result.hitObject = (*it);
            result.normal = normal;
        }
    }

    if(result.hitObject != nullptr) {
        result.hitPoint = ray.getOrigin() + ray.getDirection() * minimalDistance;
        result.ray = ray;
        result.scene = this;
    }

    return result;
}