Camera::Camera(Vec3 position, Vec3 target, Vec3 up, double fov, double near){
	this->fov = fov;
	this->near = near;
	this->position = position;

	Vec3 diference = position - target;
	this->axisZ = diference.normalize();
	this->axisX = this->axisZ.crossProd(up).normalize();
	this->axisY = this->axisZ.crossProd(this->axisX).normalize();
}


// Retorna o raio da camera para a posição x e y da imagem em coordenadas de mundo
Ray Camera::getRay(double x, double y, int width, int height) const {
	Vec3 origin = this->position;
	
	double aspectRatio = width/(double)height;
	double viewPlaneHalfWidth= tan(this->fov/2);
	double viewPlaneHalfHeight = aspectRatio*viewPlaneHalfWidth;
	Vec3 lookAtPoint = this->position + (this->axisZ * this->near);

	Vec3 viewPlaneBottomLeftPoint = lookAtPoint - this->axisY*viewPlaneHalfHeight - this->axisX*viewPlaneHalfWidth;
    
	xIncVect = (this->axisX*2*halfWidth)/width;
	yIncVect = (this->axisY*2*halfHeight)/height;

	Vec3 direction = viewPlaneBottomLeftPoint + (x * xIncVect) + (y * yIncVect);
	
	Ray r(this->position, direction);
	return r;
}