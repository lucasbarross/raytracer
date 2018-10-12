Camera::Camera(Vec3 position, Vec3 target, Vec3 up, double fov, double near){
	this->fov = fov;
	this->near = near;
	this->position = position;

	Vec3 diference = position - target;
	this->axisZ = diference.normalize();
	this->axisX = this->axisZ.crossProd(up).normalize();
	this->axisZ = this->axisZ.crossProd(this->axisX).normalize();
}

Ray getRay(double x, double y, int width, int height) {
	Ray r(Vec3(0, 0, 0), Vec3(0, 0, 0));
	return r;
}