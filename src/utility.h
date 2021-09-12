#include "vec3.h"
#include "ray.h"
#include "hittable_list.h"

#include <cstdlib>
#include <numbers>

const double pi = 3.1415926535897932385;

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

inline double deg_to_rad(double deg)
{
    return deg * pi / 180.0;
}
inline double rad_to_deg(double rad)
{
    return rad * 180.0 / pi;
}

inline double random_double() 
{
    return rand() / (RAND_MAX + 1.0);
}
inline double random_double(double min, double max)
{
    return min + (max-min)*random_double();
}