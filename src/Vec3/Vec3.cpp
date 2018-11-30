Vec3::Vec3(double x, double y, double z){
    this->x = x;
    this->y = y;
    this->z = z;
};

Vec3::Vec3() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Vec3 Vec3::operator+(Vec3 b){
    vector<double> a = this->getCoords();
    vector<double> bc = b.getCoords();
    Vec3 v(a[0] + bc[0], a[1] + bc[1], a[2] + bc[2]);
    return v;
}

Vec3 Vec3::operator-(Vec3 b){
    vector<double> a = this->getCoords();
    vector<double> bc = b.getCoords();
    Vec3 v(a[0] - bc[0], a[1] - bc[1], a[2] - bc[2]);
    return v;
}
Vec3 Vec3::operator*(Vec3 b){
    vector<double> a = this->getCoords();
    vector<double> bc = b.getCoords();
    Vec3 v(a[0] * bc[0], a[1] * bc[1], a[2] * bc[2]);
    return v;
}

Vec3 Vec3::scale(double k){
    vector<double> a = this->getCoords();
    Vec3 v(a[0] * k, a[1] * k, a[2] * k);
    return v;
}

double Vec3::dotProd(Vec3 b){
    vector<double> a = this->getCoords();
    vector<double> bc = b.getCoords();
    double pe = a[0] * bc[0] + a[1] * bc[1] + a[2] * bc[2];
    return pe;
}

Vec3 Vec3::crossProd(Vec3 b){
    vector<double> a = this->getCoords();
    vector<double> bc = b.getCoords();
    Vec3 v = Vec3((a[1]*bc[2]) - (a[2] * bc[1]), a[2] * bc[0] - a[0] * bc[2], a[0] * bc[1] - a[1] * bc[0]);
    return v;
}

Vec3 Vec3::invert() {
    return Vec3(-1 * this->x, -1 * this->y, -1 * this->z);
}

double Vec3::magnitude() {
    return sqrt((this->x * this->x) + (this->y * this->y) + (this->z * this->z));
}

Vec3 Vec3::normalize() {
    double magnitude = this->magnitude();
    return Vec3(this->x/magnitude, this->y/magnitude, this->z/magnitude);
}

vector<double> Vec3::getCoords(){
    vector<double> coords;

    coords.push_back(this->x);
    coords.push_back(this->y);
    coords.push_back(this->z);

    return coords;
}

Vec3 Vec3::transformVec(vector<vector<double>> a) {
    vector<double> coords;
    for(int i = 0; i < a.size(); i++)
        coords.push_back((a[i][0] * this->x) + (a[i][1] * this->y) + (a[i][2] * this->z));
    
    return Vec3(coords[0], coords[1], coords[2]);
}

bool Vec3::equals(Vec3 b) {
    return this->x == b.getX() && this->y == b.getY() && this->z == b.getZ();
}

bool Vec3::aproximateEquals(Vec3 b) {
    double xDifference = this->x - b.getX();
    double yDifference = this->y - b.getY();
    double zDifference = this->z - b.getZ();
    return (xDifference < EPSILON) && (yDifference < EPSILON) && (zDifference < EPSILON);
}

double Vec3::getX() {
    return this->x;
}

double Vec3::getY() {
    return this->y;
}

double Vec3::getZ() {
    return this->z;
}

void Vec3::print() {
    printf("(%.1f,%.1f,%.1f)\n", this->x, this->y, this->z);
}
