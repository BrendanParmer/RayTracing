#include <iostream>
#include <fstream>
#include <sstream>

#define STB_IMAGE_IMPLEMENTATION
#include "extern/stb_image.h"

#define STBI_MSC_SECURE_CRT
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "extern/stb_image_write.h"

int main() {

    // Image

    const int width = 256;
    const int height = 256;

    const int channels = 3;

    uint8_t* pixels = new uint8_t[width*height*channels];

    int index = 0;
    for (int j = height - 1; j >= 0; --j)
    {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < width; ++i)
        {
            float r = (float)i / (float)width;
            float g = (float)j / (float)height;
            float b = 0.2f;
            int ir = int(255.99 * r);
            int ig = int(255.99 * g);
            int ib = int(255.99 * b);

            pixels[index++] = ir;
            pixels[index++] = ig;
            pixels[index++] = ib;
        }
    }
    stbi_write_png("image.png", width, height, channels, pixels, width*channels);
    delete[] pixels;
    return 0;
}