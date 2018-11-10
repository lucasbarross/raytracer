#pragma once

#include <vector>
#include <bits/stdc++.h>
#include <math.h>
#include <float.h>

#include "util.cpp"
#include "Vec3/Vec3.h"
#include "Image/Image.h"
#include "Ray/Ray.h"
#include "Camera/Camera.h"
#include "Object/ObjectIntersection.h"
#include "Material/Material.h"
#include "Geometry/Geometry.h"
#include "Object/Object.h"
#include "Scene/Scene.h"

using namespace std;


int main() {
    int width = 800, height = 600;
    Scene scene;
    Camera camera(Vec3(0,0,500), Vec3(0,0,0), Vec3(0,1,0), 70, 10);
    Image image(width, height);
    Geometry* sphere = new Sphere(Vec3(0,0,0), 20);
    Material* material = new Material();
    Object* sphereObject = new Object(sphere, material);
    scene.add(sphereObject);
    
    ObjectIntersection* objectIntersect = new ObjectIntersection();
    
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            Ray r = camera.getRay(i, j, width, height);
            bool test = scene.intersect(r, objectIntersect);
            cout << test << " ";
            r.getDirection().print();
            if(test) {
                image.setPixel(i, j, Vec3(255,255,255));
            } else {
                image.setPixel(i, j, Vec3(0,0,0));
            };
        }
    }

    image.saveAsPBM();
    cout << "MEU DEUS FOI";
    return 0;
}