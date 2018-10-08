#include <vector>

using namespace std;

class Vec3{
	private:
		double x, y, z;
	public:
		Vec3(double x, double y, double z);
		vector<double> getCoords();

		Vec3 operator+(Vec3& b);
		Vec3 operator-(Vec3& b);
		double operator*(Vec3& b);

		Vec3 vectprod(Vec3& b);
		Vec3 scale(double k);
};