Triangle::Triangle(Vec3 a, Vec3 b, Vec3 c){
    this->a = a;
    this->b = b;
    this->c = c;
    Vec3 vavb = (this->b - this->a).normalize(); 
    Vec3 vavc = (this->c - this->a).normalize();
    this->normal = vavb.crossProd(vavc).normalize();
}

bool Triangle::intersect(Ray& r, ObjectIntersection* info) { // Möller-Trumbore
    
    Vec3 vavb = (this->b - this->a); 
    Vec3 vavc = (this->c - this->a);
    
    Vec3 pvec = r.getDirection().crossProd(vavc); 
    double det = vavb.dotProd(pvec); 
    if (abs(det) < EPSILON) return false; 
 
    double invDet = 1 / det; 

    Vec3 tvec = (r.getOrigin() - this->a); 
    double u = tvec.dotProd(pvec) * invDet; 

    if (u < 0 || u > 1) return false; 
 
    Vec3 qvec = tvec.crossProd(vavb); 
    double v = r.getDirection().dotProd(qvec) * invDet; 

    if (v < 0 || u + v > 1) return false; 
 
    // if (this->normal.dotProd(r.getDirection().invert()) < 0) this->normal = this->normal.invert(); 

    double t = vavc.dotProd(qvec) * invDet; 
    info->t = t;
    info->p = r.sample(t);
    info->n = this->normal;

    return true;
}


Vec3 Triangle::getPoint() {
    return this->a;
}