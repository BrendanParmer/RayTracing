#pragma once

#include "vec3.h"

class ray {
    public:
        point3 orig;
        vec3 dir;
        ray();
        ray(const point3 &origin, const vec3 &direction);
        point3 at(const double t) const;
};