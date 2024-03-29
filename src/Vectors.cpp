#include "Vectors.h"

// == Vector3 ==

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

Vector3 Vector3::operator!() {
    return Vector3(-(this->x),-(this->y),-(this->z));
}
Vector3 Vector3::operator+(const Vector3 & v) {
    return Vector3(this->x+v.x, this->y+v.y, this->z+v.z);
}
Vector3 Vector3::operator-(const Vector3 & v) {
    return Vector3(this->x-v.x, this->y-v.y, this->z-v.z);
}
Vector3 Vector3::operator-() {
    return Vector3(-this->x, -this->y, -this->z);
}
Vector3 Vector3::operator*(const double & val) {
    return Vector3(this->x*val, this->y*val, this->z*val);
}
Vector3 Vector3::operator/(const double & val) {
	return Vector3(this->x/val, this->y/val, this->z/val);
}


double Vector3::dot(Vector3 a, Vector3 b) {
    return (a.x*b.x + a.y*b.y + a.z*b.z);
}

Vector3 Vector3::cross(Vector3 a, Vector3 b) {
    return Vector3(a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x);
}

Vector3 Vector3::reflect(Vector3 v, Vector3 normal) {
    return normal * Vector3::dot(normal, v) * 2 - v;
}

double Vector3::length() {
    return sqrt(this->lengthSq());
}
    
double Vector3::lengthSq() {
    return (this->x*this->x + this->y*this->y + this->z*this->z);
}

Vector3 Vector3::getNormalized() {
    return ((*this)/this->length());
}

// == Vector2 ==

double Vector2::getX() {
    return this->x;
}
double Vector2::getY() {
    return this->y;
}

void Vector2::setX(double x) {
    this->x = x;
}
void Vector2::setY(double y) {
    this->y = y;
}

Vector2 Vector2::operator!() {
    return Vector2(-(this->x),-(this->y));
}
Vector2 Vector2::operator+(const Vector2 & v) {
    return Vector2(this->x+v.x,this->y+v.y);
}
Vector2 Vector2::operator-(const Vector2 & v) {
    return Vector2(this->x-v.x,this->y-v.y);
}
Vector2 Vector2::operator*(const double & val) {
    return Vector2(this->x*val,this->y*val);
}
Vector2 Vector2::operator/(const double & val) {
    return Vector2(this->x/val,this->y/val);
}

double Vector2::dot(Vector2 a, Vector2 b) {
    return (a.x*b.x + a.y*b.y);
}

double Vector2::length() {
    return sqrt(this->lengthSq());
}

double Vector2::lengthSq() {
    return (this->x*this->x + this->y*this->y);
}

Vector2 Vector2::getNormalized() {
    return ((*this)/this->length());
}