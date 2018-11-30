#pragma once

struct Light {
    Vec3 position;
    Vec3 color;

    Light(Vec3 position, Vec3 color){
        this->position = position;
        this->color = color;
    }
};