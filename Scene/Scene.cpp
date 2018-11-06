void Scene::add(Object* object){
    this->objects.push_back(object);
}

bool Scene:intersect(const Ray& r, ObjectIntersection* info = nullptr) const {
    vector<ObjectIntersection*> auxInfo;
    
    bool intersected = false;

    for(int i = 0; i < this->objects->length; i++){
        ObjectIntersection* actualObjIntersection = new ObjectIntersection();
        
        if (this->objects[i]->intersect(r, actualObjIntersection)) {
            auxInfo.push_back(actualObjIntersection);
            intersected = true;
        }
    }

    if(!intersected) return false;

    ObjectIntersection* min = auxInfo[0];

    for(int i = 1; i < auxInfo.length; i++){
        if(auxInfo[i]->t < min->t){
            delete min;
            min = auxInfo[i];
        } else {
            delete auxInfo[i];
        }
    }   

    info->t = min->t;
    info->n = min->n;
    info->p = min->p;
    info->object = min->object;

    return true;
};