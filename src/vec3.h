#pragma once

#include <cmath>
#include <string>

class vec3 {
    public:
        double x;
        double y;
        double z;

        vec3(double x, double y, double z);

        //negative
        vec3 operator-() const;

        //arithmetic
        vec3 operator+(const vec3 &other);
        vec3 operator-(const vec3 &other);
        vec3 operator*(const double &a);
        vec3 operator/(const double &a);

        double dot(const vec3 &u, const vec3 &v);
        vec3 cross(const vec3 &u, const vec3 &v);

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

using point3 = vec3;
using color = vec3;