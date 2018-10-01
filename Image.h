#include <vector>
#include <string>
#include "Vec3.h"

using namespace std;

class Image {
	private: 
		int width, height;
		vector<vector<Vec3*> > buffer;
	public:
		Image(int width, int height);
		
		void SetPixel(int x, int y, Vec3* color);
		
		void SaveAsPBM(const string& filePath) const;
};