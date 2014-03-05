#ifndef _IMAGE_H_
#define _IMAGE_H_

#include "Color.h"

class Image {
private:
    Color **bitmap = nullptr;
    unsigned int width;
    unsigned int height;

public:
    Image(unsigned int w, unsigned int h);
    Image(Image& img);
    ~Image();
    void setPixel(unsigned int w, unsigned int h, Color c);
    Color getPixel(unsigned int w, unsigned int h);
    Color** getBitmap();
    unsigned int getWidth();
    unsigned int getHeight();
};

#endif