#pragma once

#include <cmath>
#include <string>

class vec3 {
    public:
        double x;
        double y;
        double z;

        vec3();
        vec3(double x, double y, double z);

        //negative
        vec3 operator-() const;

        vec3 operator+=(const vec3& other);
        vec3 operator-=(const vec3& other);
        vec3 operator*=(const double &a);
        vec3 operator/=(const double &a);
        
        //functions
        double length() const;
        vec3 unit(vec3 v);
        std::string to_string(const vec3 &v);

        //indexing
        double operator[](int i) const;
        double operator[](unsigned i) const;
};

inline vec3 operator+(const vec3 &u, const vec3 &v)
{
    return vec3(u.x+v.x, u.y+v.y, u.z+v.z);
}

inline vec3 operator-(const vec3 &u, const vec3 &v)
{
    return vec3(u.x-v.x, u.y-v.y, u.z-v.z);
}

inline vec3 operator*(double t, const vec3 &v)
{
    return vec3(t*v.x, t*v.y, t*v.z);
}

inline vec3 operator*(const vec3 &v, double t)
{
    return t * v;
}

inline vec3 operator/(const vec3 &v, const double &t)
{
    return vec3(v.x/t, v.y/t, v.z/t);
}


inline double dot(const vec3 &u, const vec3 &v)
{
    return u.x*v.x + u.y*v.y + u.z*v.z;
}

inline vec3 cross(const vec3 &u, const vec3 &v)
{
    return vec3(u.y*v.z - u.z*v.y,
                u.z*v.x - u.x*v.z,
                u.x*v.y - u.y*v.x);
}

using point3 = vec3;
using color = vec3;