#include "PngExport.h"

void PngExport::exportToFile(std::string filename) {
    png::image<png::rgba_pixel> pngImg(this->img->getWidth(),this->img->getHeight());

    for (unsigned int x = 0; x < pngImg.get_width(); ++x) {
        for (unsigned int y = 0; y < pngImg.get_height(); ++y) {
            Color c = this->img->getPixel(x, y);
            pngImg[y][x] = png::rgba_pixel((int)(c.r*255), (int)(c.g*255), (int)(c.b*255), (int)(c.a*255));
        }
    }
    pngImg.write(filename);
}