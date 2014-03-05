#ifndef _COLOR_H_
#define _COLOR_H_

class Color {
public:
    float r; //red
    float g; //green
    float b; //blue
    float a; //alpha

    Color(float _r, float _g, float _b) : r(_r), g(_g), b(_b) {}
    Color(float _r, float _g, float _b, float _a): r(_r), g(_g), b(_b), a(_a) {}

    
};

#endif