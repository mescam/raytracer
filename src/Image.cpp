#include "Image.h"
#include <cassert>
#include <iostream>
#include <SFML/Graphics.hpp>


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
    
    sf::Image buffer;
    buffer.create(width, height, sf::Color(0, 0, 0));
    for (unsigned int i = 0; i < width; ++i) {
        for (unsigned int j = 0; j < height; ++j) {
            Color myColor = bitmap[i][j];
            sf::Color bColor(int(myColor.r*255), int(myColor.g*255), int(myColor.b*255));
            std::clog << "Setting (" << i << ", " << j << ") to color " << int(bColor.r) << ", " << int(bColor.g) << ", " << int(bColor.b) << std::endl;
            buffer.setPixel(i, j, bColor);
        }
    }
    sf::Texture bufferTexture;
    bufferTexture.loadFromImage(buffer);
    sf::Sprite bufferSprite(bufferTexture);
    sf::RenderWindow window(sf::VideoMode(width, height), "Raytracer Window");
    window.clear(sf::Color(0, 0, 0));
    window.draw(bufferSprite);
    window.display();
    std::cin.get();
}