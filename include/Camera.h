#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "Ray.h"

class Camera {
public:
	virtual Ray getRayTo(Vector2 location) = 0;
};

#endif //_CAMERA_H_