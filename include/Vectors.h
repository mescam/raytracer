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
    
    double getX();
    double getY();
    double getZ();

    void setX(double x);
    void setY(double y);
    void setZ(double z);

    Vector3 operator!();
    Vector3 operator+(const Vector3 & v);
    Vector3 operator-(const Vector3 & v);
    Vector3 operator*(const double & val);
    Vector3 operator/(const double & val);

    static double dot(Vector3 a, Vector3 b);
    static Vector3 cross(Vector3 a, Vector3 b);

    double length();
    double lengthSq();

    Vector3 getNormalized();
};

class Vector2 {
public:
    double x;
    double y;
public:
    Vector2(double x, double y): x(x), y(y) {

    }

    double getX();
    double getY();

    void setX(double x);
    void setY(double y);
};

#endif //_VECTORS_H_