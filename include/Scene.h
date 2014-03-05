#ifndef _SCENE_H_
#define _SCENE_H_

#include <list>

#include "Figure.h"
#include "Color.h"
#include "HitInfo.h"

class Scene {
private:
    std::list<Figure*> objects;
    Color backgroundColor;
public:
    Scene(Color backgroundColor = Color(0.0f,0.0f,0.0f,1.0f)): backgroundColor(backgroundColor) {
        // empty (yet)
    }

    Color getBackgroundColor();
    void setBackgroundColor(Color c);

    void addObject(Figure* object);
    HitInfo traceRay(Ray ray);
};

#endif //_SCENE_H_