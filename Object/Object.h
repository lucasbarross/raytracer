#pragma once

// #include "../Geometry/Geometry.h"
// #include "Material.h"
// #include "ObjectIntersection.h"

using namespace std;

class Object {
    private:
        Geometry* geometry;
        Material* material;

    public:
        Object(Geometry* geometry, Material* material);

        bool intersect (Ray& r, ObjectIntersection* info);
};

#include "Object.cpp"