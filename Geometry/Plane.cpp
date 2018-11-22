Plane::Plane(Vec3 p1, Vec3 p2, Vec3 p3) {
    
    this->p1 = p1;
    this->p2 = p2;
    this->p3 = p3;

    this->h = 20;
    this->b = 30;

    this->normal = (p2 - p1).crossProd(p3 - p1).normalize();
};

bool Plane::intersectPlane(Ray& r, ObjectIntersection* info){      
    float t, denom; 
    // this->normal = this->normal.invert();
    Vec3 normalAux = this->normal;
    denom = normalAux.dotProd(r.getDirection());
    
    if(denom < 0){
        normalAux = normalAux.invert();
        // denom = normalAux.dotProd(r.getDirection());  
    } 

    if ( -denom > 0.0001) { 
        Vec3 point = (this->p1 - r.getOrigin()); 

        t = ((point.dotProd(normalAux) + normalAux.dotProd(this->p1)) / -denom);
        // float t = - (dot(N, orig) + D) / dot(N, dir);
        if(t < 0.00001) return false;
        
        info->t = t;
        info->p = r.sample(info->t);
        info->n = normalAux;
        return true;
    } 
    return false;
};
bool Plane::intersect(Ray& r, ObjectIntersection* info){
    if (this->intersectPlane(r, info)) {
        // double xDistance =  
        // info->p distancia pro this->p1
        return true;
    }
    return false;
}

Vec3 Plane::getPoint() {
    return this->p1;
}

Vec3 Plane::getNormal() {
    return this->normal;
}
