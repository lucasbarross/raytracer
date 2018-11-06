#pragma once

#include "Vec3.h"
#include "Ray.h"
#include "ObjectIntersection.h"
#include <cmath>

using namespace std;

class Geometry {
    public:
        virtual bool intersect(const Ray& r, ObjectIntersection* info = nullptr) const; 
        //Retorna um ponto do objeto para ser usado como fonte de luz.
        virtual Vec3 getPoint() const = 0;
}

class Sphere : public Geometry {
    private:
        Vec3 center;
        double radius;

    public: 
        Sphere(Vec3 center, double radius);
        bool intersect(const Ray& r, ObjectIntersection* info = nullptr) const;
        Vec3 getPoint() const override;
}