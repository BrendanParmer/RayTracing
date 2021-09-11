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

double vec3::dot(const vec3 &u, const vec3 &v)
{
    return u.x*v.x + u.y*v.y + u.z*v.z;
}

vec3 vec3::cross(const vec3 &u, const vec3 &v)
{
    return vec3(u.y*v.z - u.z*v.y,
                u.z*v.x - u.x*v.z,
                u.x*v.y - u.y*v.x);
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

double vec3::length() const {
    return std::sqrt(x*x + y*y + z*z);
}

vec3 vec3::unit(vec3 v)
{
    return v / v.length();
}

std::string vec3::to_string(const vec3 &v)
{
    return "(" + std::to_string(v.x) + ", " 
               + std::to_string(v.y) + ", " 
               + std::to_string(v.z) + ")";
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