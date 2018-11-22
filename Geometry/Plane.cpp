Plane::Plane(Vec3 p1, Vec3 p2, Vec3 p3) {
    
    this->p1 = p1;
    this->p2 = p2;
    this->p3 = p3;

    this->normal = (p2 - p1).crossProd(p3 - p1).normalize();
};

bool Plane::intersect(Ray& r, ObjectIntersection* info){      
    float t, denom; 
    // this->normal = this->normal.invert();
    Vec3 normalAux = this->normal;
    denom = normalAux.dotProd(r.getDirection());
    
    if(denom < 0){
        normalAux = normalAux.invert();
        denom = normalAux.dotProd(r.getDirection());  
    } 
    
    cout << denom << endl;

    // if (denom > 1e-6) { 
        Vec3 point = (this->p1 - r.getOrigin()); 
        
        t = point.dotProd(normalAux) / denom;
        
        if(t < 0) return false;
        
        info->t = t;
        info->p = r.sample(info->t);
        info->n = normalAux;
        cout << (info->t) << endl;
        return true;     
    return false;
};

Vec3 Plane::getPoint() {
    return this->p1;
}

Vec3 Plane::getNormal() {
    return this->normal;
}
