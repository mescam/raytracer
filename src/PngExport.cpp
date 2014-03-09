#include "PngExport.h"

void PngExport::exportToFile(std::string filename) {
    png::image<png::rgba_pixel> pngImg(this->img->getWidth(),this->img->getHeight());
    for (unsigned int y = 0; y < pngImg.get_height(); ++y) {
        for (unsigned int x = 0; x < pngImg.get_width(); ++x) {
            pngImg[y][x] = png::rgba_pixel((int)(this->img->getPixel(y,x).r*255),(int)(this->img->getPixel(y,x).g*255),(int)(this->img->getPixel(y,x).b*255),(int)(this->img->getPixel(y,x).a*255));
            //pngImg[y][x] = png::rgba_pixel(128,128,128,128);

        }
    }
    pngImg.write(filename);
}