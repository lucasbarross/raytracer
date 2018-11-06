Sphere::Sphere(Vec3 center, double radius) {
    this->center = center;
    this->radius = radius;
};

Sphere:intersect(const Ray& r, ObjectIntersection* info = nullptr) const{
    Vec3 l = this->center - r->getOrigin();
    double tca = l.dotProduct(r->getDirection());
    
    if(tca < 0) return false;

    double d = (l.dotProduct(l)) - (tca * tca));
    
    if(d > this->radius * this->radius) return false;
    
    double thc = sqrt(this->radius*this->radius - d);
    
    info->t = tca - thc;
    info->p = r->sample(info->t);
    info->n = info->p - this->center; 
    info->object = this;
};