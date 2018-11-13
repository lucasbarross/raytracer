Ray::Ray(Vec3 origin, Vec3 direction) {
	this->origin = origin;
	this->direction = direction; 
}

Vec3 Ray::sample(double t) {
	return this->origin + (this->direction).scale(t);
}

Vec3 Ray::getOrigin() {
	return this->origin;
}

Vec3 Ray::getDirection() {
	return this->direction;
}