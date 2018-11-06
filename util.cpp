using namespace std;

vector<vector<double> > matrixMult(vector<vector<double> > a, vector<vector<double> > b) {
    vector<vector<double> > mult;
    
    if (a[0].size() != b.size()) {
        cout << "Matrizes de tamanho inválido";
        return mult;
    }

    for (int i = 0; i < b[0].size(); i++) {
        vector<double> v;
        for (int j = 0; j < a.size(); j++) {
            v.push_back(0);
        }
        mult.push_back(v);
    }

    for(int i = 0; i < a.size(); ++i)
        for(int j = 0; j < b[0].size(); ++j)
            for(int k = 0; k < a[0].size(); ++k){
                mult[i][j] += a[i][k] * b[k][j];
            }

    return mult;
};
