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

#include "hittable_list.h"
#include "sphere.h"

color ray_color(const ray& r, const hittable& world, int depth)
{
    if (depth <= 0)
        return color(0, 0, 0);

    hit_record rec;
    if (world.hit(r, 0.000001, INFINITY, rec))
    {
        point3 target = rec.p + rec.normal + rec.p.random_in_unit_sphere();
        
        return 0.5 * ray_color(ray(rec.p, target - rec.p), world, depth - 1);
    }
    double t = 0.5 * (unit(r.dir).y + 1.0);
    color world_color = (1.0-t)*color(1.0, 1.0, 1.0) + t*color(0.5, 0.7, 1.0);
    return world_color; 
}

int main() {

    // Image
    const double aspect_ratio = 16.0/9.0;
    const int width = 4096;
    const int height = static_cast<int>(width/aspect_ratio);
    std::cout << "Creating image of dimensions (" << width << ", " << height << ")" << std::endl;
    const int channels = 3;
    const int samples_per_pixel = 100;
    const int depth = 50;

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
        for (int i = 0; i < width; ++i)
        {
            std::cerr << "\rCalculating pixel (" << i << ", " << j << ")" << std::flush;
            color pixel_color(0, 0, 0);
            for (int s = 0; s < samples_per_pixel; ++s)
            {
                double u = double(i + random_double())/(width - 1);
                double v = double(j + random_double())/(height - 1);
                ray ray = cam.get_ray(u, v);
                pixel_color += ray_color(ray, world, depth);
                hit_record temp_rec;
            }
            double scale = 1.0 / samples_per_pixel;
            pixel_color.x = std::sqrt(scale * pixel_color.x);
            pixel_color.y = std::sqrt(scale * pixel_color.y);
            pixel_color.z = std::sqrt(scale * pixel_color.z);

            //gotta clamp to 0.999 because if it's 1 then that component could be 256, 
            //which the PNG converter would discard
            pixel_color = pixel_color.clamp_vec3(0, 0.999);
            pixel_color *= 256;

            pixels[index++] = pixel_color.x;
            pixels[index++] = pixel_color.y;
            pixels[index++] = pixel_color.z;
        }
    }
    stbi_write_png("image.png", width, height, channels, pixels, width*channels);
    delete[] pixels;
    return 0;
}