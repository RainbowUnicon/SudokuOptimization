#include <stdio.h>
#include <iostream>

#include "Sudoku.h"
#include "FileReader.h"
#include "FileWriter.h"
#include "Backtracking.h"

int main(int argc, char** argv) {
    string fileName = string(argv[1]);
    int iteration = stoi(argv[2]);

    clock_t begin = clock();
    for(int i = 0;i < iteration; i++){
        string tBoard = FileReader::getBoard(fileName,i++);
        Sudoku s(tBoard);
        // std::cout << "------Board------\n" << s.toString_d();
        Backtracking b(s);
        b.solve();
        // std::cout << "------Solved-----\n" << b.getSudoku().toString_d();
        FileWriter::appendBoard(fileName, b.getSudoku().toString());
    }
    clock_t end = clock();
    long elapsed = long(end-begin);
    cout << elapsed << "\n";
    return 0;
}
