#include "Image.h"
#include <cassert>
#include <iostream>
//#include <SFML/Graphics.hpp>


Image::Image(unsigned int w, unsigned int h) : width(w), height(h) {
    bitmap = new Color*[width];
    for (unsigned int i = 0; i < width; ++i) {
        bitmap[i] = new Color[height];
    }
}

Image::Image(Image &img) {
    width = img.getWidth();
    height = img.getHeight();
    bitmap = new Color*[width];
    for (unsigned int i = 0; i < width; ++i) {
        bitmap[i] = new Color[height];
        for (unsigned int j = 0; j < height; ++j) {
            bitmap[i][j] = img.getPixel(i, j);
        }
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

unsigned int Image::getWidth() {
    return width;
}

unsigned int Image::getHeight() {
    return height;
}

void Image::render() {
    PngExport test = PngExport(this);
    test.exportToFile("output.png");
}
