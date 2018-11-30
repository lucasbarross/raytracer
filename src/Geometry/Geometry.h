#pragma once

// #include "Vec3.h"
// #include "Ray.h"
// #include "ObjectIntersection.h"
#include <cmath>

using namespace std;

class Geometry {
    public:
        virtual bool intersect(Ray& r, ObjectIntersection* info) = 0; 
        //Retorna um ponto do objeto para ser usado como fonte de luz.
        virtual Vec3 getPoint() = 0;
};

class Sphere : public Geometry {
    private:
        Vec3 center;
        double radius;

    public: 
        Sphere(Vec3 center, double radius);
        bool intersect(Ray& r, ObjectIntersection* info);
        Vec3 getPoint() override;
};

class Triangle : public Geometry {
    private: 
        Vec3 a;
        Vec3 b;
        Vec3 c;
        Vec3 normal;
    public:
        Triangle(Vec3 a, Vec3 b, Vec3 c);
        Vec3 getPoint() override;
        bool intersectPlane(Ray& r);
        bool intersect(Ray& r, ObjectIntersection* info);
};


#include "Sphere.cpp"
#include "Triangle.cpp"
