#include "OrthonormalBasis.h"

OrthonormalBasis::OrthonormalBasis(Vector3 eye, Vector3 lookAt, Vector3 up) {
    w = (eye - lookAt).getNormalized();
    u = Vector3::cross(up, w).getNormalized();
    v = Vector3::cross(w, u);
}

Vector3 OrthonormalBasis::operator*(const Vector3 v) {
    return (this->u * v.x + this->v * v.y + this->w * v.z);
}