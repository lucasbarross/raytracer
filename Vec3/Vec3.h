#ifndef VEC3_H
#define VEC3_H

#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

class Vec3{
	private:
		double x, y, z;
	public:
		Vec3(double x, double y, double z);
		Vec3();
		vector<double> getCoords();
		double getX();
		double getY();
		double getZ();
		void print();

		Vec3 operator+(Vec3& b);
		Vec3 operator-(Vec3& b);
		double dotProd(Vec3& b);
		Vec3 crossProd(Vec3& b);

		double magnitude();
		Vec3 scale(double k);
		Vec3 normalize();
		Vec3 invert();
		Vec3 transformVec(vector<vector<double>> a);
};

#include "Vec3.cpp"

#endif
