#ifndef _COLOR_H_
#define _COLOR_H_

class Color {
public:
    float r; //red
    float g; //green
    float b; //blue
    float a; //alpha

    Color(float r, float g, float b, float a);
    Color(float r, float g, float b) : Color(r,g,b,1.0f) {}
    Color(): Color(1.0f,1.0f,1.0f,1.0f) {}

    Color operator+(const Color b);
    Color operator*(const float val);
    Color operator*(const Color b);
    Color operator/(const float val);

};

#endif