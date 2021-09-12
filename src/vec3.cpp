#include "vec3.h"

vec3::vec3()
{
    x = 0;
    y = 0;
    z = 0;
}

vec3::vec3(double set_x, double set_y, double set_z)
{
    x = set_x;
    y = set_y;
    z = set_z;
}


vec3 vec3::operator-() const {
    return vec3(-x, -y, -z);
}


vec3& vec3::operator+=(const vec3 &other)
{
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

vec3& vec3::operator-=(const vec3 &other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}

vec3& vec3::operator*=(const double &a)
{
    x *= a;
    y *= a;
    z *= a;
    return *this;
}

vec3& vec3::operator/=(const double &a)
{
    x /= a;
    y /= a;
    z /= a;
    return *this;
}


double vec3::length() const {
    return std::sqrt(x*x + y*y + z*z);
}

std::string vec3::to_string()
{
    return "(" + std::to_string(x) + ", " 
               + std::to_string(y) + ", " 
               + std::to_string(z) + ")";
}

vec3 vec3::clamp_vec3(double min, double max)
{
    return vec3(clamp(x, min, max),
                clamp(y, min, max),
                clamp(z, min, max));
}

double vec3::operator[](int i) const {
    i %= 3;
    if (i < 0)
        i += 3;
    if (i == 0)
        return x;
    else if (i == 1)
        return y;
    else
        return z;
}

double vec3::operator[](unsigned i) const {
    return (*this)[(int) i];
}