#include <vector>

using namespace std;

class Vec3{
	private:
		double x, y, z;
	public:
		Vec3(double x, double y, double z);
		vector<double> getCoords();
};