#include "Image.h"
#include "Vec3.cpp"
#include <vector>

using namespace std;    

Image::Image(int width, int height){
    this->width = width;
    this->height = height;
    for(int i = 0; i < height; i++){
        vector<Vec3> row;
        this->buffer.push_back(row);
        for(int j = 0; j < width; j++){
            Vec3 v(0,0,0);
            this->buffer[i].push_back(v);
        }
    }
};

void Image::setPixel(int x, int y, const Vec3& color){
    this->buffer[x][y] = color;
};

void Image::saveAsPBM(){
    FILE *f = fopen("image.ppm", "w");
    fprintf(f, "P3\n%d %d\n%d\n", this->width, this->height, 255); 
    for (int i=0; i< this->height; i++) {
        for (int j=0; j < this->width; j++) {
            std::vector<double> aux = this->buffer[i][j].getCoords();
            fprintf(f,"%d %d %d ", (int) aux[0], (int) aux[1], (int) aux[2]); 
        }
        
    } 
};
