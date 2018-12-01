#pragma once

#include <vector>

using namespace std;

class Scene {
    private:
        vector<Object*> objects;
        Vec3 background;
        Light *light;
        Vec3 phong(Material* material, Vec3 direction, Vec3 normal, Vec3 lightRay);
        
    public:
        Scene(Light* light, Vec3 background);
        //Retorna true se r intersecta a cena e falso caso contrário.
        //Guarda possíveis informacoes sobre a intersection em info, caso seja provido
        bool intersect(Ray& r, ObjectIntersection* info);

        //Implementa o modelo de iluminacao escolhido, retornando uma cor
        Vec3 trace (Ray& r, int recursionLevel);
        
        //adiciona um objeto na cena
        void add (Object* object);
};

#include "Scene.cpp"