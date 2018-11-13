#pragma once

struct Light {
    Vec3 position;
    Vec3 is; //specular - color
    Vec3 id; //diffuse - point of reflection color

    Light(Vec3 position, Vec3 is, Vec3 id){
        this->position = position;
        this->is = is;
        this->id = id;
    }
};