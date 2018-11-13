Scene::Scene(Light* light, Vec3 background){
    this->light = light;
    this->background = background;
}


void Scene::add(Object* object){
    this->objects.push_back(object);
}

bool Scene::intersect(Ray& r, ObjectIntersection* info) {
    vector<ObjectIntersection*> auxInfo;
    
    bool intersected = false;

    for(int i = 0; i < this->objects.size(); i++){
        ObjectIntersection* actualObjIntersection = new ObjectIntersection();
        
        if (this->objects[i]->intersect(r, actualObjIntersection)) {
            actualObjIntersection->o = this->objects[i];
            intersected = true;
            auxInfo.push_back(actualObjIntersection);
        }
    }

    if(!intersected) return false;

    ObjectIntersection* min = auxInfo[0];

    for(int i = 1; i < auxInfo.size(); i++){
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
    info->o = min->o;

    return true;
};

Vec3 Scene::trace(Ray& r, int recursionLevel){
    ObjectIntersection* objIntersection = new ObjectIntersection();
    if(this->intersect(r, objIntersection)){
        Material* material = objIntersection->o->getMaterial();
        Vec3 normal = objIntersection->n;
        Vec3 direction = r.getDirection();
        Vec3 lightRay = (objIntersection->p - this->light->position).normalize();
        Vec3 reflection = lightRay - normal.scale((lightRay.dotProd(normal) * 2));
        this->phong(material, direction, lightRay, normal, reflection).print();
        return this->phong(material, direction, lightRay, normal, reflection); 

    } else {
        return this->background;
    };
    delete objIntersection;
}

Vec3 Scene::phong(Material* material, Vec3 direction, Vec3 lightRay, Vec3 normal, Vec3 reflection){
    double a = lightRay.dotProd(normal);
    double b = reflection.dotProd(direction);
    Vec3 diffuse, specular;

    if (a < 0) {
        diffuse = Vec3(0,0 ,0);
    } else {
        diffuse = this->light->id.scale(material->kd * a);
    }

    if (b < 0) {
        specular = Vec3(0, 0, 0);
    } else {
        specular = this->light->is.scale(material->ks * pow(b, material->alpha));

    }
    
    return material->color.scale(material->ke) + diffuse + specular; 
}