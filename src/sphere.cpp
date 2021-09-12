#include "sphere.h"

sphere::sphere()
{
    center = point3(0, 0, 0);
    radius = 1;
}

sphere::sphere(point3 set_center, double set_r)
{
    center = set_center;
    radius = set_r;
}

bool sphere::hit(const ray &ray, double t_min, double t_max, hit_record &rec) const
{
    vec3 sdfo = ray.orig - center; //sphere distance from origin
    double a = dot(ray.dir, ray.dir);
    double half_b = dot(ray.dir, sdfo);
    double c = dot(sdfo, sdfo) - radius*radius;
    double discriminant = half_b*half_b - a*c;
    if (discriminant < 0)
        return false;

    double root = (-half_b - std::sqrt(discriminant)) / a;
    if (root < t_min || t_max < root)
    {
        root += 2 * std::sqrt(discriminant) / a;
        if (root < t_min || t_max < root)
            return false;
    }
    rec.t = root;
    rec.p = ray.at(rec.t);
    vec3 outward_normal = (rec.p - center) / radius;
    rec.set_face_normal(ray, outward_normal);
    return true;
}