#include "cmath"
#include "figures/Sphere.h"

Sphere::Sphere(Vector3 c, double r, Color cl) : Figure(cl), center(c), radius(r) {

}

bool Sphere::testHit(Ray ray, double& distance) {
    double t, a, b, c, disc;

    Vector3 d = ray.origin - center;
    a = ray.direction.lengthSq();
    b = Vector3::dot(d * 2, ray.direction);
    c = d.lengthSq() - radius * radius;
    disc = b * b - 4 * a * c;

    if (disc < 0)
        return false;

    double discSq = sqrt(disc);
    double denom = 2 * a;

    t = (-b - discSq) / denom;
    if (t < ray.epsilon) 
        t = (-b + discSq) / denom;
    if (t < ray.epsilon)
        return false;

    distance = t;
    return true;
}