#pragma once

#include <vector>
#include "Image.cpp"
#include <bits/stdc++.h>

//#include "Ray.h"
//#include <cmath>

using namespace std;

// class Camera {
// 	private: 
// 		Vec3 position, axisX, axisY axisZ
// 		double fov, near;
		
// 	public:
// 		Camera(Vec3 position, Vec3 target, Vec3 up, double fov, double near);
		
// 		Ray getRay(double x, double y, int width, int height) const;
// }

int main(){
	Image* teste = new Image(1000, 1000);
	const Vec3 vec1(255, 0, 0);
	const Vec3 vec2(0, 255, 0);
	const Vec3 vec3(0, 0, 255);
	const Vec3 vec4(255, 255, 0);


	for (int i = 0; i < 250; ++i)
	{
		for (int j = 0; j <  1000; ++j)
		{
			teste->setPixel(i, j, vec1);
		}
	}


	for (int i = 0; i < 250; ++i)
	{
		for (int j = 0; j <  1000; ++j)
		{
			teste->setPixel(250 + i, j, vec2);
		}
	}

	for (int i = 0; i < 250; ++i)
	{
		for (int j = 0; j <  1000; ++j)
		{
			teste->setPixel(500 + i, j, vec3);
		}
	}

	for (int i = 0; i < 250; ++i)
	{
		for (int j = 0; j <  1000; ++j)
		{
			teste->setPixel(750 + i, j, vec4);
		}
	}


	teste->saveAsPBM();
}