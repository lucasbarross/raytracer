Parser::Parser(string file){
    this->file = file;
}

vector<map<string, double> > Parser::searchKey(string key){
    ifstream file(this->file);
    string line;
    vector<map<string, double> > params;

    if (!file) {
        cout << "Could not open " << this->file << endl;
        exit(1);
    } 
    
    int current = 0;
    
    map<string, double> firstMap;
    params.push_back(firstMap);
    
    bool match = false;
    while( getline(file, line) ) {
        if(line == ("#" + key)){
            match = true;
            continue;
        } else if (line[0] == '#') {
            match = false; 
        }

        if(line != "" && match) {
            string optkey = line.substr(0, line.find("="));
            string param = line.substr(line.find("=")+1, line.size());
            
            if(params[current].find(optkey) != params[current].end()) {
                map<string, double> newMap;
                current++;
                params.push_back(newMap);
            }
            params[current][optkey] = stod(param);        
        } 
    }

    return params;
}