#pragma once

#include <utility>
#include <vector>
#include <math.h>
#include <float.h>
#include <iostream>

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
#include "Parser/Parser.h"

using namespace std;


int main() {
    Parser parser("config.txt");
    
    // map<string, int> cameraOptions = parser.searchKey("#camera")[0];
    // para acessar: cameraOptions["positionX"], cameraOptions["positionY"] e assim por diante, como definido no config.txt

    int width = 800, height = 600;
    
    Camera camera(Vec3(0,0,100), Vec3(0,0,0), Vec3(0,1,0), 50, 10);

    Light* light = new Light(Vec3(100, 100, 0), Vec3(255,255,255));
    Vec3 background = Vec3(50, 50, 50);
    
    Scene scene(light, background, 0.1);
    Image image(width, height);

    // Ta distocendo quanto mais longe do centro

   
    Geometry* sphere = new Sphere(Vec3(0,0,0), 10);
    Material* material = new Material(0.1, 0.45, 0.1, 200, Vec3(0.1, 1, 0.1));
    Object* sphereObject = new Object(sphere, material);

    scene.add(sphereObject);

    Geometry* spherea = new Plane(Vec3(0,0,0), Vec3(50,30, 2), Vec3(22,32,44));
    Material* materiala = new Material(0.5, 0.45, 0.1, 200, Vec3(1, 0, 0));
    Object* sphereObjecta = new Object(spherea, materiala);

    scene.add(sphereObjecta);

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
