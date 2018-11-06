#pragma once

#include "Object.h"
#include "ObjectIntersection.h"
#include <vector>

using namespace std;

class Scene {
    private:
        vector<Object*> objects;

    public:
        //Retorna true se r intersecta a cena e falso caso contrário.
        //Guarda possíveis informacoes sobre a intersection em info, caso seja provido
        bool intersect(const Ray& r, ObjectIntersection* info = nullptr) const;

        //Implementa o modelo de iluminacao escolhido, retornando uma cor
        Vec3 trace (const Ray& r, int recursionLevel = 0) const;

        //adiciona um objeto na cena
        void add (Object* object);
}