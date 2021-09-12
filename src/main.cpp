#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>

#define STB_IMAGE_IMPLEMENTATION
#include "../extern/stb_image.h"

#define STBI_MSC_SECURE_CRT
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../extern/stb_image_write.h"

#include "utility.h"
#include "camera.h"
#include "sphere.h"

color ray_color(const ray& ray, const hittable& world)
{
    hit_record rec;
    if (world.hit(ray, 0, INFINITY, rec))
    {
        return 0.5 * (rec.normal + color(1, 1, 1));
    }
    double t = 0.5 * (unit(ray.dir).y + 1.0);
    return (1.0-t)*color(1.0, 1.0, 1.0) + t*color(0.5, 0.7, 1.0);
}

int main() {

    // Image
    const double aspect_ratio = 16.0/9.0;
    const int width = 1600;
    const int height = static_cast<int>(width/aspect_ratio);
    std::cout << "Creating image of dimensions (" << width << ", " << height << ")" << std::endl;
    const int channels = 3;
    const int samples_per_pixel = 100;

    //world
    hittable_list world;

    //center sphere
    point3 center0 = point3(0, 0, -1);
    double rad0 = 0.5;
    sphere sphere0 = sphere(center0, rad0);

    //ground sphere
    point3 center1 = point3(0, -100.5, -1);
    double rad1 = 100;
    sphere sphere1 = sphere(center1, rad1);

    world.add(std::make_shared<sphere>(sphere0));
    world.add(std::make_shared<sphere>(sphere1));

    //camera stuff

    camera cam;

    uint8_t* pixels = new uint8_t[width*height*channels];

    int index = 0;
    for (int j = height - 1; j >= 0; --j)
    {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < width; ++i)
        {
            color pixel_color(0, 0, 0);
            for (int s = 0; s < samples_per_pixel; ++s)
            {
                double u = double(i + random_double())/(width - 1);
                double v = double(j + random_double())/(height - 1);
                ray ray = cam.get_ray(u, v);
                pixel_color += 255 * ray_color(ray, world);
            }
            pixel_color /= samples_per_pixel;
            
            pixels[index++] = pixel_color.x;
            pixels[index++] = pixel_color.y;
            pixels[index++] = pixel_color.z;
        }
    }
    stbi_write_png("image.png", width, height, channels, pixels, width*channels);
    delete[] pixels;
    return 0;
}