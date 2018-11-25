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
        // Itera pela lista de objetos adicionando os intersectados a lista
        ObjectIntersection* actualObjIntersection = new ObjectIntersection();
        
        if (this->objects[i]->intersect(r, actualObjIntersection)) {
            actualObjIntersection->o = this->objects[i];
            intersected = true;
            auxInfo.push_back(actualObjIntersection);
        }
    }

    if(!intersected) return false;

    ObjectIntersection* min = auxInfo[0];
    // Procura objeto com o menor T
    for(int i = 1; i < auxInfo.size(); i++){
        if(auxInfo[i]->t < min->t){
            delete min;
            min = auxInfo[i];
        } else {
            delete auxInfo[i];
        }
    }   

    // Salva as informações do Objeto
    info->t = min->t - EPSILON; 
    // A substração do EPISILON para corrigir o caso em que a propria superficie se bloqueia
    // causando um glitch na iluminação da superificie toda
    info->n = min->n;
    info->p = min->p;
    info->o = min->o;

    return true;
};

Vec3 Scene::trace(Ray& r, int recursionLevel){
    ObjectIntersection* objIntersection = new ObjectIntersection();
    
    // Testa se o objeto foi intersectado
    if (this->intersect(r, objIntersection)){
        Material* material = objIntersection->o->getMaterial();
        Vec3 normal = objIntersection->n;
        Vec3 direction = r.getDirection();

        // Calcula componente emissiva (que independe da fonte de luz)
        Vec3 color = (Vec3(255, 255, 255) * material->color).scale(material->ke);

        // Calcula o raio de luz incidente no ponto de intersecção            
        Vec3 lightRayVector = (light->position - objIntersection->p );
        Vec3 lightRayDirection = lightRayVector.normalize();
        Ray lightRay = Ray(objIntersection->p, lightRayDirection);
        double tLight = lightRayVector.magnitude();

        // Testa se raio de luz intersecta objeto antes de chegar na luz     
        ObjectIntersection* info = new ObjectIntersection();
        if (this->intersect(lightRay, info)) {
            // Testa se objeto está antes do ponto (em relação a luz) e na frente da luz 
            if (info->t > 0 && info->t <= tLight) { 
                return color;
            }
        }
        delete info;

        return color + this->phong(material, direction, normal,lightRayDirection); 
    } else {
        return this->background;
    };
    delete objIntersection;
}

Vec3 Scene::phong(Material* material, Vec3 direction, Vec3 normal, Vec3 lightRay){ // Calcula modelo de iluminação local de phong
    Vec3 reflection = (lightRay - normal.scale((lightRay.dotProd(normal) * 2))).normalize();

    double diffuse, specular;

    diffuse = lightRay.dotProd(normal) * material->kd; // Componente difusa
    specular = (material->ks * pow(reflection.dotProd(direction), material->alpha)); // Componente specular

    if (normal.dotProd(lightRay) < 0 || specular < 0) specular = 0;

    if (diffuse < 0) diffuse = 0;

    Vec3 resultColor = this->light->color * material->color;

    return resultColor.scale(specular + diffuse); 
}
