Parser::Parser(string file){
    this->file = file;
}

vector<map<string, int> > Parser::searchKey(string key){
    ifstream file(this->file);
    string line;
    vector<map<string, int> > params;
    
    int current = 0;
    
    map<string, int> firstMap;
    params.push_back(firstMap);
    
    bool match = false;
    
    while( getline(file, line) ) {
        
        if(line == key){
            match = true;
            continue;
        } else if (line[0] == '#') {
            match = false; 
        }

        if(line != "" && match) {
            string key = line.substr(0, line.find("="));
            string param = line.substr(line.find("=")+1, line.size());
            if(params[current].find(key) != params[current].end()) {
                map<string, int> newMap;
                current++;
                params.push_back(newMap);
            }
            params[current][key] = stoi(param);        
        } 
    }

    return params;
}