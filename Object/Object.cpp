Object::Object(Geometry* geometry, Material* material) {
    this->geometry = geometry;
    this->material = material;
};

bool Object::intersect (const Ray& r, ObjectIntersection* info = nullptr) {
    return this->geometry->intersect(r, info);
};