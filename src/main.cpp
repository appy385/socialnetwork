#include "maindriver.h"
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include <sstream>

using namespace std;

int main(){
    Driver driver;
    ifstream inFile;
    string inFileName = "operations.txt";
    inFile.open(inFileName);
    
    if(!inFile.is_open()){
        return 1;
    }
    
    // inFile >> line; //this reads element before space 
    while(!inFile.eof()) {

        string line,intermediate;
        getline(inFile,line); 

        stringstream ss(line);
        vector <string> tokens;

        while(getline(ss, intermediate, '~'))
        {
              tokens.push_back(intermediate);
        }

        inFile >> ws;  

        driver.callAction(tokens);
        

    }

    inFile.close();

    return 0;
}
