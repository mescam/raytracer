#include "cameras/OrthogonalCamera.h"

Ray OrthogonalCamera::getRayTo(Vector2 location) {
    Vector3 direction = Vector3(sin(angle),0,cos(angle));
    Vector2 offsetFormCenter = Vector2(location.x*size.x,location.y*size.y);
    Vector3 position = Vector3(eyePosition.x+offsetFormCenter.x*cos(angle),eyePosition.y+offsetFormCenter.y,eyePosition.z+offsetFormCenter.x*sin(angle));   
    return Ray(position,direction);
}