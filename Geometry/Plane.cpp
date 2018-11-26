InfinitePlane::InfinitePlane(Vec3 p1, Vec3 p2, Vec3 p3) {
    
    this->p1 = p1;
    this->p2 = p2;
    this->p3 = p3;

    this->normal = (p2 - p1).crossProd(p3 - p1).normalize();
};

bool InfinitePlane::intersect(Ray& r, ObjectIntersection* info){      
    float t, denom; 
    Vec3 normalAux = this->normal;
    denom = normalAux.dotProd(r.getDirection());
    
    if(denom < 0){
        normalAux = normalAux.invert();
    } 

    if ( -denom > EPSILON) { 
        Vec3 point = (this->p1 - r.getOrigin()); 

        t = ((point.dotProd(normalAux) + normalAux.dotProd(this->p1)) / -denom);
        if(t < EPSILON) return false;
        
        info->t = t;
        info->p = r.sample(info->t);
        info->n = normalAux;
        return true;
    } 
    return false;
};

Vec3 InfinitePlane::getPoint() {
    return this->p1;
}

Vec3 InfinitePlane::getNormal() {
    return this->normal;
}
