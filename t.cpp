#pragma once

#include <vector>
//#include "Vec3.h"

//#include "Ray.h"
#include <cmath>

using namespace std;


class Vec3{
	private:
		double x, y, z;
	public:
		Vec3(double x, double y, double z);
		vector<double> getCoords();
}

class Image {
	private: 
		int width, height;
		vector<vector<Vec3> > buffer;
	public:
		Image(int width, int height){
			this.width = width;
			this.height = height;
		 	for(int i = 0; i < height; i++){
		 		vector<Vec3> row;
		 		this.buffer.push_back(row);
		 		for(int j = 0; j < width; j++){
		 			this.buffer[i].push_back(new Vec3(0,0,0))
		 		}
		 	}
		};
		
		void SetPixel(int x, int y, const Vec3& color){
			this.buffer[x][y] = color;
		};
		
		void SaveAsPBM(const string& filePath) const;
}

class Camera {
	private: 
		Vec3 position, axisX, axisY axisZ
		double fov, near;
		
	public:
		Camera(Vec3 position, Vec3 target, Vec3 up, double fov, double near);
		
		Ray getRay(double x, double y, int width, int height) const;
}

