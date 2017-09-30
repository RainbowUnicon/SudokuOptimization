#include <stdio.h>
#include <iostream>
#include <gperftools/profiler.h>

#include "Sudoku.h"
#include "FileReader.h"
#include "FileWriter.h"
#include "Backtracking.h"

int main() {
    clock_t begin = clock();
    ProfilerStart("sudoku_45.log");
    for(int i = 0;i < 10000; i++){
        string tBoard = FileReader::getBoard("boards/sudoku_45",i++);
        Sudoku s(tBoard);
        // std::cout << "------Board------\n" << s.toString_d();
        Backtracking b(s);
        b.solve();
        // std::cout << "------Solved-----\n" << b.getSudoku().toString_d();
        FileWriter::appendBoard("boards/sudoku_solution_45", b.getSudoku().toString());
    }
    ProfilerStop();
    clock_t end = clock();
    long elapsed = long(end-begin);
    cout << elapsed << "\n";
    return 0;
}
