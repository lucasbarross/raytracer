#ifndef CAMERA_H	
#define CAMERA_H

class Camera {
	private:
		Vec3 position, axisX, axisY, axisZ, target;
		double fov, near;
	public:		
		Camera(Vec3 position, Vec3 target, Vec3 up, double fov, double near);

		Ray getRay(double x, double y, int width, int height);
	
};

#include "Camera.cpp"

#endif