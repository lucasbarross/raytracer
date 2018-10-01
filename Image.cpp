#include "Image.h"
#include <vector>

using namespace std;    

Image::Image(int width, int height){
    this->width = width;
    this->height = height;
    for(int i = 0; i < height; i++){
        vector<Vec3*> row;
        this->buffer.push_back(row);
        for(int j = 0; j < width; j++){
            this->buffer[i].push_back(new Vec3(0,0,0));
        }
    }
};

void Image::SetPixel(int x, int y, Vec3* color){
    this->buffer[x][y] = color;
};