#ifndef _VECTORS_H_
#define _VECTORS_H_

#include <cmath>

class Vector3 {
public:
    double x;
    double y;
    double z;
public:
    Vector3(double x, double y, double z): x(x), y(y), z(z) {

    }
    // gettery
    double getX() {
        return this->x;
    }
    double getY() {
        return this->y;
    }
    double getZ() {
        return this->z;
    }
    // settery
    void setX(double x) {
        this->x = x;
    }
    void setY(double y) {
        this->y = y;
    }
    void setZ(double z) {
        this->z = z;
    }

    Vector3 operator+(const Vector3 & v) {
        return Vector3(this->x+v.x, this->y+v.y, this->z+v.z);
    }
    Vector3 operator-(const Vector3 & v) {
        return Vector3(this->x-v.x, this->y-v.y, this->z-v.z);
    }
    Vector3 operator*(const double & val) {
        return Vector3(this->x*val, this->y*val, this->z*val);
    }
    Vector3 operator/(const double & val) {
        return Vector3(this->x/val, this->y/val, this->z/val);
    }

    static double dot(Vector3 a, Vector3 b) {
        return (a.x*b.x + a.y*b.y + a.z*b.z);
    }
    static Vector3 cross(Vector3 a, Vector3 b) {
        return Vector3(a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x);
    }

    double length() {
        return sqrt(this->lenght2());
    }
    double lenght2() {
        return (this->x*this->x + this->y*this->y + this->z*this->z);
    }

    Vector3 getNormalized() {
        return ((*this)/this->length());
    }

};

#endif //_VECTORS_H_