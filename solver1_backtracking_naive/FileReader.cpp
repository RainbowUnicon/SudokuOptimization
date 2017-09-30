#include <iostream>
#include <fstream>
#include "FileReader.h"


string FileReader::getBoard(string fileName, int index){
    string line;
    ifstream file(fileName);
    int n = 0;
    if(file.is_open()){
        while(getline(file,line)){
            if(n == index){
                return line;
            }
            n++;
        }
    }
    return "";
}

