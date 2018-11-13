#pragma once

#include <vector>
#include <bits/stdc++.h>
#include <math.h>
#include <float.h>

#include "util.cpp"
#include "Vec3/Vec3.h"
#include "Image/Image.h"
#include "Ray/Ray.h"
#include "Light/Light.h"
#include "Camera/Camera.h"
#include "Object/ObjectIntersection.h"
#include "Material/Material.h"
#include "Geometry/Geometry.h"
#include "Object/Object.h"
#include "Scene/Scene.h"

using namespace std;


int main() {
    int width = 800, height = 600;
    Camera camera(Vec3(0,0,100), Vec3(0,0,0), Vec3(0,1,0), 90, 10);

    Light* light = new Light(Vec3(10, 10, 10), Vec3(255,0,0), Vec3(0,0,255));
    Vec3 background = Vec3(255,0,255);
    
    Scene scene(light, background);
    Image image(width, height);
    
    Geometry* sphere = new Sphere(Vec3(0,0,0), 10);
    Material* material = new Material(0.52, 0, 0.82, 0.1, Vec3(0, 255, 0));
    Object* sphereObject = new Object(sphere, material);

    scene.add(sphereObject);
    
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            Ray r = camera.getRay(i, j, width, height);
            Vec3 color = scene.trace(r, 0);
            image.setPixel(i, j, color);
        }
    }
    
    image.saveAsPBM();
    cout << "MEU DEUS FOI";
    return 0;
}