
#ifndef RAY_H
#define RAY_H

class Ray {
	private:
		Vec3 origin, direction;
	public:
		Ray(Vec3 origin , Vec3 direction);

		Vec3 sample(const double& t);

		Vec3 getOrigin() const;

		Vec3 getDirection() const;
};

#include "Ray.cpp"

#endif