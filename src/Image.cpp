#include "Image.h"
#include <cassert>

Image::Image(unsigned int w, unsigned int h) : width(w), height(h) {
    bitmap = new Color*[width];
    for (unsigned int i = 0; i < width; ++i) {
        bitmap[i] = new Color[height];
    }
}

Image::~Image() {
    for (unsigned int i = 0; i < width; ++i) {
        delete[] bitmap[i];
    }
    delete[] bitmap;
}

void Image::setPixel(unsigned int w, unsigned int h, Color c) {
    assert(w < width);
    assert(h < height);
    assert(bitmap != nullptr);
    bitmap[w][h] = c;
}

Color Image::getPixel(unsigned int w, unsigned int h) {
    assert(w < width);
    assert(h < height);
    assert(bitmap != nullptr);
    return bitmap[w][h];
}

Color** Image::getBitmap() {
    return bitmap;
}