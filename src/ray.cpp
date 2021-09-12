#include "ray.h"

ray::ray()
{
    orig = point3(0,0,0);
    dir = vec3(0,0,0);
}
ray::ray(const point3 &origin, const vec3 &direction)
{
    orig = origin;
    dir = direction;
}

point3 ray::at(double t) const {
    
    return orig + t*dir;
}
