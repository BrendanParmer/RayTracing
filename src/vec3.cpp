#include "vec3.h"

vec3::vec3(double set_x, double set_y, double set_z)
{
    x = set_x;
    y = set_y;
    z = set_z;
}
vec3 vec3::operator-() const {
    return vec3(-x, -y, -z);
}

vec3 vec3::operator+(const vec3 &other)
{
    return vec3(x+other.x, y+other.y, z+other.z);
}

vec3 vec3::operator-(const vec3 &other)
{
    return (*this) + -other;
}

vec3 vec3::operator*(const double &a)
{
    return vec3(a*x, a*y, a*z);
}

vec3 vec3::operator/(const double &a)
{
    return vec3(x/a, y/a, z/a);
}


vec3 vec3::operator+=(const vec3 &other)
{
    return *this + other;
}

vec3 vec3::operator-=(const vec3 &other)
{
    return *this - other;
}

vec3 vec3::operator*=(const double &a)
{
    return *this * a;
}

vec3 vec3::operator/=(const double &a)
{
    return *this/a;
}

