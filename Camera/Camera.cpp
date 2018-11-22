Camera::Camera(Vec3 position, Vec3 target, Vec3 up, double fov, double near){
	this->fov = 3.14 * fov /180;
	this->near = near;
	this->position = position;
		
	Vec3 diference = target - position; // Inverti aqui
	this->axisZ = diference.normalize();
	this->axisX = this->axisZ.crossProd(up).invert().normalize();
	this->axisY = this->axisZ.crossProd(this->axisX).normalize();
}

// Retorna o raio da camera para a posição x e y da imagem em coordenadas de mundo
Ray Camera::getRay(double x, double y, int width, int height) {
	Vec3 origin = this->position;
	
	double aspectRatio = height/(double)width; // Inverti aqui
	double viewPlaneHalfWidth= tan(this->fov/2) * this->near; //MUltipliquei pelo near
	double viewPlaneHalfHeight = aspectRatio*viewPlaneHalfWidth;
	Vec3 planeCenterPoint = this->position + this->axisZ.scale(this->near);

	Vec3 viewPlaneBottomLeftPoint = planeCenterPoint - this->axisY.scale(viewPlaneHalfHeight) - this->axisX.scale(viewPlaneHalfWidth);
	Vec3 xIncVect = this->axisX.scale(2* viewPlaneHalfWidth/width);
	Vec3 yIncVect = this->axisY.scale(2* viewPlaneHalfHeight/height);

	Vec3 pixelPosition = viewPlaneBottomLeftPoint + (xIncVect.scale(x)) + (yIncVect.scale(y));
	Vec3 rayDirection = pixelPosition - this->position;
	
	Ray r(this->position, rayDirection.normalize());
	return r;
}