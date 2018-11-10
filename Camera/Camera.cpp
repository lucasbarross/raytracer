Camera::Camera(Vec3 position, Vec3 target, Vec3 up, double fov, double near){
	this->fov = fov;
	this->near = near;
	this->position = position;

	Vec3 diference = position - target;
	this->axisZ = diference.normalize();
	this->axisX = this->axisZ.crossProd(up).invert().normalize();
	this->axisY = this->axisZ.crossProd(this->axisX).normalize();

	this->axisZ.print();
	this->axisX.print();
	this->axisY.print();
}

// Retorna o raio da camera para a posição x e y da imagem em coordenadas de mundo
Ray Camera::getRay(double x, double y, int width, int height) {
	Vec3 origin = this->position;
	
	double aspectRatio = width/(double)height;
	double viewPlaneHalfWidth= tan(this->fov/2);
	double viewPlaneHalfHeight = aspectRatio*viewPlaneHalfWidth;
	Vec3 lookAtPoint = this->position + this->axisZ.scale(this->near);

	Vec3 viewPlaneBottomLeftPoint = lookAtPoint - this->axisY.scale(viewPlaneHalfHeight) - this->axisX.scale(viewPlaneHalfWidth);
	Vec3 xIncVect = this->axisX.scale(2* viewPlaneHalfWidth/width);
	Vec3 yIncVect = this->axisY.scale(2* viewPlaneHalfHeight/height);

	Vec3 direction = viewPlaneBottomLeftPoint + (xIncVect.scale(x)) + (yIncVect.scale(y));
	
	Ray r(this->position, direction);
	return r;
}