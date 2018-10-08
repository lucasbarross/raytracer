#include "Image.h"
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

void Image::SetPixel(int x, int y, const Vec3& color){
    this->buffer[x][y] = color;
};

void Image::SaveAsPBM(const string& filePath) const{
    // FILE *f = fopen("image.ppm", "w");         // Write image to PPM file. 
    // fprintf(f, "P3\n%d %d\n%d\n", w, h, 255); 
    // for (int i=0; i<w*h; i++) 
    //     fprintf(f,"%d %d %d ", toInt(c[i].x), toInt(c[i].y), toInt(c[i].z)); 
};