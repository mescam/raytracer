#ifndef _SCENE_H_
#define _SCENE_H_

#include <list>

#include "Color.h"
#include "HitInfo.h"
#include "Vectors.h"

class Figure;
class PointLight;

class Scene {
private:
    std::list<Figure*> objects;
    
    Color backgroundColor;
public:
    std::list<PointLight*> lights;
    Scene(Color backgroundColor = Color(0.0f,0.0f,0.0f,1.0f)): backgroundColor(backgroundColor) {
        // empty (yet)
    }

    Color getBackgroundColor();
    void setBackgroundColor(Color c);

    void addObject(Figure* object);
    void addObject(PointLight* light);
    HitInfo traceRay(Ray ray);

    bool isObstacleBetween(Vector3 a, Vector3 b);
};

#endif //_SCENE_H_