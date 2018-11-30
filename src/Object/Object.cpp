Object::Object(Geometry* geometry, Material* material) {
    this->geometry = geometry;
    this->material = material;
};

bool Object::intersect (Ray& r, ObjectIntersection* info) {
    return this->geometry->intersect(r, info);
};

Material* Object::getMaterial(){
    return this->material;
}