#pragma once

#include "hittable.h"
#include "vec3.h"

class sphere : public hittable
{
    public:
        point3 center;
        double radius;

        sphere();
        sphere(point3 center, double r);
        virtual bool hit(const ray &ray, double t_min, double t_max, hit_record &rec) const override;
};