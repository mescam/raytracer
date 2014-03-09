#include "Color.h"

Color::Color(float r, float g, float b, float a): r(r), g(g), b(b), a(a) {
    if (this->r > 1.0f) this->r = 1.0f;
    if (this->g > 1.0f) this->g = 1.0f;
    if (this->b > 1.0f) this->b = 1.0f;
    if (this->a > 1.0f) this->a = 1.0f;

    if (this->r < 0.0f) this->r = 0.0f;
    if (this->g < 0.0f) this->g = 0.0f;
    if (this->b < 0.0f) this->b = 0.0f;
    if (this->a < 0.0f) this->a = 0.0f;
}