#pragma once

using namespace std;

struct Material {
    int id;
    double ke;
    double kd;
    double ks;
    double alpha;
    Vec3 color;

    Material(int id, double ke, double kd, double ks, double alpha, Vec3 color){
        this->id = id;
        this->ke = ke;
        this->kd = kd;
        this->ks = ks;
        this->alpha = alpha;
        this->color = color;    
    }
};