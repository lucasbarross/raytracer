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

using namespace std;


int main() {
    Vec3 x(1, 0, 0);
    Vec3 y(0, 1, 0);
    Vec3 z(0, 0, 1);


    return 0;
}

vector<vector<double>> matrixMult(vector<vector<double>> a, vector<vector<double>> b) {
    vector<vector<double>> mult;
    
    if (a[0].size() != b.size()) {
        cout << "Matrizes de tamanho inválido";
        return mult;
    }

    for (int i = 0; i < b[0].size(); i++) {
        vector<double> v;
        for (int j = 0; j < a.size(); j++) {
            v.push_back(0);
        }
        mult.push_back(v);
    }

    for(int i = 0; i < a.size(); ++i)
        for(int j = 0; j < b[0].size(); ++j)
            for(int k = 0; k < a[0].size(); ++k){
                mult[i][j] += a[i][k] * b[k][j];
            }

    return mult;
};
