Camera::Camera(Vec3 position, Vec3 target, Vec3 up, double fov, double near){
	this->fov = fov;
	this->near = near;
	this->position = position;

	Vec3 diference = position - target;
	this->axisZ = diference.normalize();
	this->axisX = this->axisZ.crossProd(up).normalize();
	this->axisY = this->axisZ.crossProd(this->axisX).normalize();
}

Ray Camera::getRay(double x, double y, int width, int height) const {
	Vec3 origin = this->position;
	
	double aspectRatio = width/(double)height;
	double pixelScreenX = 2 * ((x+0.5)/width) - 1;
	double pixelScreenY = 2 * ((y+0.5)/height) - 1;

	double pixelCameraX = (2 * pixelScreenX - 1) * aspectRatio * tan(this->fov/2 * M_PI / 180);
	double pixelCameraY = 1 - 2 * pixelScreenY * tan(this->fov/2 * M_PI / 180);
	
    

	// 1 0 0 -x
	// 0 1 0 -y
	// 0 0 1 -z
	// 0 0 0 1
	
	
	Ray r(origin, Vec3(0, 0, 0));
	return r;
}