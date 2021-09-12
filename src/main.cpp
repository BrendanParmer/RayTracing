#include <iostream>
#include <fstream>
#include <sstream>

#define STB_IMAGE_IMPLEMENTATION
#include "../extern/stb_image.h"

#define STBI_MSC_SECURE_CRT
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../extern/stb_image_write.h"

#include "vec3.h"
#include "ray.h"


double hit_sphere(const ray& r, const point3& center, double radius)
{
    vec3 sdfo = r.orig - center; //sphere distance from origin
    double a = dot(r.dir, r.dir);
    double half_b = dot(r.dir, sdfo);
    double c = dot(sdfo, sdfo) - radius*radius;
    double discriminant = half_b*half_b - a*c;
    if (discriminant < 0)
        return -1.0;
    else
        return (-half_b - sqrt(discriminant)) / a;
}

color ray_color(const ray& r)
{
    point3 center = point3(0, 0, -1);
    double radius = 0.4;
    double t = hit_sphere(r, center, radius);
    if (t > 0.0)
    {
        vec3 normal = unit(r.at(t) - center);
        return 0.5*color(normal.x +1, normal.y+1, normal.z+1);
    }
    t = 0.5*(unit(r.dir).y + 1.0);
    return (1.0-t)*color(0.93, 0.9, 1.0) + t*color(0.53, 0.5, 0.6);
}

int main() {

    // Image
    const double aspect_ratio = 16.0/9.0;
    const int width = 1600;
    const int height = static_cast<int>(width/aspect_ratio);
    std::cout << "Creating image of dimensions (" << width << ", " << height << ")" << std::endl;
    const int channels = 3;

    //camera stuff

    double viewport_height = 2.0;
    double viewport_width = aspect_ratio * viewport_height;
    double focal_length = 1.0;

    point3 origin = point3(0, 0, 0);
    vec3 horizontal = vec3(viewport_width, 0, 0);
    vec3 vertical = vec3(0, viewport_height, 0);
    vec3 lower_left_corner = origin - horizontal/2 -vertical/2 - vec3(0, 0, focal_length);

    uint8_t* pixels = new uint8_t[width*height*channels];

    int index = 0;
    for (int j = height - 1; j >= 0; --j)
    {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < width; ++i)
        {
            double u = double(i)/(width - 1);
            double v = double(j)/(height - 1);
            ray r(origin, lower_left_corner + u*horizontal + v*vertical - origin);

            color pixel_color = ray_color(r) * 255;

            pixels[index++] = pixel_color.x;
            pixels[index++] = pixel_color.y;
            pixels[index++] = pixel_color.z;
        }
    }
    stbi_write_png("image.png", width, height, channels, pixels, width*channels);
    delete[] pixels;
    return 0;
}