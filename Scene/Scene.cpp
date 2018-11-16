Scene::Scene(Light* light, Vec3 background, double ka){
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
        Vec3 normal = objIntersection->n.normalize();
        Vec3 direction = r.getDirection();
        Vec3 lightRay = (this->light->position - objIntersection->p).normalize();
        Vec3 reflection = (lightRay - normal.scale((lightRay.dotProd(normal) * 2)));
        // this->phong(material, direction, lightRay, normal, reflection).print();
        return this->phong(material, direction, lightRay, normal, reflection); 

    } else {
        return this->background;
    };
    delete objIntersection;
}

Vec3 Scene::phong(Material* material, Vec3 direction, Vec3 lightRay, Vec3 normal, Vec3 reflection){
    double diffuse, specular;
    diffuse = lightRay.dotProd(normal) * material->kd;
    specular = (material->ks * pow(reflection.dotProd(direction), material->alpha));
    
    if (diffuse < 0) {
        diffuse = 0;
    }
    if (specular < 0) {
        specular = 0;
    }
    
    Vec3 resultColor = this->light->color * material->color;

    return resultColor.scale(material->ke + specular + diffuse); 
}
