#ifndef _PNG_EXPORT_H_
#define _PNG_EXPORT_H_

#include <string>

#include <png++/png.hpp>

#include "Image.h"

class PngExport {
private:
    class Image* img;
public:
    PngExport(class Image* img): img(img) {}
    void exportToFile(std::string filename);        
};

#endif //_PNG_EXPORT_H_