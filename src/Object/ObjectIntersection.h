#pragma once

class Object;

struct ObjectIntersection {
    double t;
    Vec3 p, n;
    Object* o;
};