#include "FileWriter.h"
#include <iostream>
#include <fstream>

using namespace std;

void FileWriter::appendBoard(string fileName, string str){
    ofstream file(fileName, ofstream::out | ofstream::app);
    if(file.is_open()){
        file << str << "\n";
        file.close();
    }
}

