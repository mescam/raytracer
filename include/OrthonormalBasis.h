#ifndef _OTHORNORMALBASIS_H_
#define _OTHORNORMALBASIS_H_

#include "Vectors.h"

class OrthonormalBasis {
public:
    Vector3 u;
    Vector3 v;
    Vector3 w;

    OrthonormalBasis(Vector3 eye, Vector3 lookAt, Vector3 up);

    Vector3 operator*(const Vector3 v);
};

#endif