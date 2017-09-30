#ifndef BACKTRACKING_H
#define BACKTRACKING_H

#include "Sudoku.h"

class Backtracking{
    private:
        Sudoku sudoku;
        tuple<int,int> getNext();

    public:
        Backtracking(Sudoku sudoku) : sudoku(sudoku){};
        bool solve();
        Sudoku getSudoku();
};

#endif
