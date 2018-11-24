Triangle::Triangle(Vec3 a, Vec3 b, Vec3 c){
    this->a = a;
    this->b = b;
    this->c = c;
    Vec3 vavb = (this->b - this->a).normalize(); 
    Vec3 vavc = (this->c - this->a).normalize();
    this->normal = vavb.crossProd(vavc).normalize();
}

bool Triangle::intersect(Ray& r, ObjectIntersection* info) {
    // Möller-Trumbore
    // if (!this->intersectPlane(r)) return false;
    
    Vec3 vavb = (this->b - this->a); 
    Vec3 vavc = (this->c - this->a);
    
    Vec3 pvec = r.getDirection().crossProd(vavc); 
    double det = vavb.dotProd(pvec); 
    if (abs(det) < 0.000001) return false; 
 
    double invDet = 1 / det; 

    Vec3 tvec = (r.getOrigin() - this->a); 
    double u = tvec.dotProd(pvec) * invDet; 

    if (u < 0 || u > 1) return false; 
 
    Vec3 qvec = tvec.crossProd(vavb); 
    double v = r.getDirection().dotProd(qvec) * invDet; 

    if (v < 0 || u + v > 1) return false; 
 
    double t = vavc.dotProd(qvec) * invDet; 

    info->t = t;
    info->p = r.sample(t);
    info->n = this->normal;

    return true;
}

bool Triangle::intersectPlane(Ray& r){      
    float t, denom; 
    // this->normal = this->normal.invert();
    Vec3 normalAux = this->normal;
    denom = normalAux.dotProd(r.getDirection());
    
    if(denom < 0){
        normalAux = normalAux.invert();
        // denom = normalAux.dotProd(r.getDirection());  
    } 

    if ( -denom > 0.0001) { 
        Vec3 point = (this->a - r.getOrigin()); 

        t = ((point.dotProd(normalAux) + normalAux.dotProd(this->a)) / -denom);
        // float t = - (dot(N, orig) + D) / dot(N, dir);
        if(t < 0.00001) return false;
        
        return true;
    } 
    return false;
};

Vec3 Triangle::getPoint() {
    return this->a;
}