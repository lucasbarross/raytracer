#ifndef IMAGE_H
#define IMAGE_H


#include <vector>
#include <string>

using namespace std;

class Image {
	private: 
		int width, height;
		vector<vector<Vec3> > buffer;
	public:
		Image(int width, int height);
		
		void setPixel(int x, int y, const Vec3& color);
		
		void saveAsPBM(string fileName);
};

#include "Image.cpp"

#endif
