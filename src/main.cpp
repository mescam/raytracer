#include <iostream>
#include "Vectors.h"
#include "Color.h"

int main(int argc, char** argv) {
    //let the journey begin
    Color c(1.0f, 0.5f, 0.0f);
    std::clog << c.r << " " << c.g << " " << c.b << std::endl;
    return 0;
}
