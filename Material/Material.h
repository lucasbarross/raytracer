#pragma once

using namespace std;

struct Material {
    double ke;
    double kd;
    double ks;
    double alpha;
    Vec3 color;

    Material(double ke, double kd, double ks, double alpha, Vec3 color){
        this->ke = ke;
        this->kd = kd;
        this->ks = ks;
        this->alpha = alpha;
        this->color = color;    
    }
};