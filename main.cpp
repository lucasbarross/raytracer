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

Material* findMaterial(vector<Material*> materials, int id){
    for(int i = 0; i < materials.size(); i++){
        if(materials[i]->id == id){
            return materials[i];
        } 
    }

    return new Material(0, 0, 0,0, 100, Vec3(0.1,1,0.1));
}

int main() {
    Parser parser("config.txt");
    map<string, double> camOpt = parser.searchKey("camera")[0];
    map<string, double> imgOpt = parser.searchKey("image")[0];
    map<string, double> sceneOpt = parser.searchKey("scene")[0];
    map<string, double> lightOpt = parser.searchKey("light")[0];
    vector<map<string, double> > materials = parser.searchKey("materials");
    vector<map<string, double> > objects = parser.searchKey("objects");
    // para acessar: cameraOptions["positionX"], cameraOptions["positionY"] e assim por diante, como definido no config.txt

    int width = imgOpt["width"], height = imgOpt["height"];
    
    Camera camera(Vec3(camOpt["positionX"],camOpt["positionY"],camOpt["positionZ"]), 
                  Vec3(camOpt["targetX"],camOpt["targetY"],camOpt["targetZ"]), 
                  Vec3(camOpt["upX"],camOpt["upY"], camOpt["upZ"]), 
                  camOpt["fov"], camOpt["near"]);

    Light* light = new Light(Vec3(lightOpt["positionX"], lightOpt["positionY"], lightOpt["positionZ"]), 
                             Vec3(lightOpt["colorR"],lightOpt["colorG"], lightOpt["colorB"]));
    
    Vec3 background = Vec3(imgOpt["bgR"], imgOpt["bgG"], imgOpt["bgB"]);
    
    Scene scene(light, background, sceneOpt["ka"]);
    Image image(width, height);
    
    vector<Material*> materialsObjects;
    vector<Object*> objectsToRender;

    for(int i = 0; i < materials.size(); i++) {
        map<string,double> materialOpt = materials[i];
        materialsObjects.push_back(new Material(materialOpt["id"], materialOpt["ke"], materialOpt["kd"], materialOpt["ks"], 
                                   materialOpt["alpha"], Vec3(materialOpt["colorR"], materialOpt["colorG"], materialOpt["colorB"])));
    }

    for(int i = 0; i < objects.size(); i++){
        map<string,double> objectsOpt = objects[i];
        
        Geometry* geometry;
        Material* material = findMaterial(materialsObjects, objectsOpt["materialId"]);
        if(objectsOpt["type"] == 1){
            geometry = new InfinitePlane(Vec3(objectsOpt["centerX"], objectsOpt["centerY"], objectsOpt["centerZ"]), 
                                 Vec3(objectsOpt["vec1X"],objectsOpt["vec1Y"], objectsOpt["vec1Z"]),
                                 Vec3(objectsOpt["vec2X"], objectsOpt["vec2Y"], objectsOpt["vec2Z"]));
        }else if(objectsOpt["type"]==2){
            geometry = new Triangle(Vec3(objectsOpt["aX"],objectsOpt["aY"],objectsOpt["aZ"]), Vec3(objectsOpt["bX"],objectsOpt["bY"],objectsOpt["bZ"]), Vec3(objectsOpt["cX"],objectsOpt["cY"],objectsOpt["cZ"]));
        } else{
            geometry = new Sphere(Vec3(objectsOpt["centerX"], objectsOpt["centerY"], objectsOpt["centerZ"]), objectsOpt["radius"]);
        }

        scene.add(new Object(geometry, material));
    }
    
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
