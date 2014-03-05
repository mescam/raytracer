#include "Vectors.h"


double Vector3::getX() {
    return this->x;
}
double Vector3::getY() {
    return this->y;
}
double Vector3::getZ() {
    return this->z;
}

void Vector3::setX(double x) {
    this->x = x;
}
void Vector3::setY(double y) {
    this->y = y;
}
void Vector3::setZ(double z) {
    this->z = z;
}


Vector3 Vector3::operator+(const Vector3 & v) {
    return Vector3(this->x+v.x, this->y+v.y, this->z+v.z);
}
Vector3 Vector3::operator-(const Vector3 & v) {
    return Vector3(this->x-v.x, this->y-v.y, this->z-v.z);

}
Vector3 Vector3::operator*(const double & val) {
    return Vector3(this->x*val, this->y*val, this->z*val);

}
Vector3 Vector3::operator/(const double & val) {
	return Vector3(this->x/val, this->y/val, this->z/val);
}


static double Vector3::dot(Vector3 a, Vector3 b) {
    return (a.x*b.x + a.y*b.y + a.z*b.z);
}

static Vector3 Vector3::cross(Vector3 a, Vector3 b) {
    return Vector3(a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x);
}

double Vector3::length() {
    return sqrt(this->length2());
}
    
double Vector3::length2() {
    return (this->x*this->x + this->y*this->y + this->z*this->z);
}

Vector3 Vector3::getNormalized() {
    return ((*this)/this->length());
}