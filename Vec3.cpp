#include "Vec3.h"

using namespace std;

Vec3::Vec3(double x, double y, double z){
    this->x = x;
    this->y = y;
    this->z = z;
};

Vec3 Vec3::operator+(Vec3& b){
    vector<double> a = this->getCoords();
    vector<double> bc = b.getCoords();
    Vec3 v(a[0] + bc[0], a[1] + bc[1], a[2] + bc[2]);
    return v;
}

double Vec3::operator*(Vec3& b){
    vector<double> a = this->getCoords();
    vector<double> bc = b.getCoords();
    double pe = a[0] * bc[0] + a[1] * bc[1] + a[2] * bc[2];
    return pe;
}

Vec3 Vec3::operator-(Vec3& b){
    vector<double> a = this->getCoords();
    vector<double> bc = b.getCoords();
    Vec3 v(a[0] - bc[0], a[1] - bc[1], a[2] - bc[2]);
    return v;
}

Vec3 Vec3::scale(double k){
    vector<double> a = this->getCoords();
    Vec3 v(a[0] * k, a[1] * k, a[2] * k);
    return v;
}

Vec3 Vec3::vectprod(Vec3& b){
    vector<double> a = this->getCoords();
    vector<double> bc = b.getCoords();
    Vec3 v = Vec3(a[1]*bc[2] - a[2] * bc[1], a[2] * bc[0] - a[0] * bc[2], a[0] * bc[1] - a[1] * bc[0]);
    return v;
}

vector<double> Vec3::getCoords(){
    vector<double> coords;

    coords.push_back(this->x);
    coords.push_back(this->y);
    coords.push_back(this->z);

    return coords;
}