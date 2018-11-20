#pragma once

#include <fstream>
#include <vector>
#include <map>

using namespace std;

class Parser {
    private:
        string file;

    public:
        Parser(string file);
        map<string, int> getCameraParams();
        vector<map<string, int> > searchKey(string key);    
};

#include "Parser.cpp"