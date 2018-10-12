Ray::Ray(Vec3 origin, Vec3 direction) {
	this->origin = origin;
	this->direction = direction; 
}

Vec3 Ray::sample(const double& t) {
	return (this->origin + this->direction).scale(t);
}

Vec3 Ray::getOrigin() const {
	return this->origin;
}

Vec3 Ray::getDirection() const {
	return this->direction;
}