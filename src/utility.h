#pragma once

#include <cstdlib>
#include <numbers>

const double pi = 3.1415926535897932385;

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

inline double clamp(double x, double min, double max)
{
    if (x < min)
        return min;
    if (x > max)
        return max;
    return x;
}