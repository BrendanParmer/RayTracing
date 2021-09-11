#pragma once

class vec3 {
    public:
        double x;
        double y;
        double z;

        vec3(double x, double y, double z);

        //negative
        vec3 operator-() const;

        //arithmetic
        vec3 operator+(const vec3& other);
        vec3 operator-(const vec3& other);
        vec3 operator*(const double &a);
        vec3 operator/(const double &a);

        vec3 operator+=(const vec3& other);
        vec3 operator-=(const vec3& other);
        vec3 operator*=(const double &a);
        vec3 operator/=(const double &a);

        vec3 operator=(const vec3& other);

        //functions
        double length() const;

        //indexing
        double operator[](int i) const;
        double operator[](unsigned i) const;
};