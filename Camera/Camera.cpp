Camera::Camera(Vec3 position, Vec3 target, Vec3 up, double fov, double near){
	this->fov = fov;
	this->near = near;
}

Ray getRay(double x, double y, int width, int height) {
	Ray r(Vec3(0, 0, 0), Vec3(0, 0, 0));
	return r;
}