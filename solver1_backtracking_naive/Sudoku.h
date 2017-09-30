#ifndef SUDOKU_H
#define SUDOKU_H

#include <string>
#include <vector>

using namespace std;

class Sudoku{
    private:
        vector<vector<int>> board;

    public:
        const static int SIZE = 9;

        Sudoku(string);

        int getValue(int row, int col);
        bool canPlace(int row, int col, int value);
        void setValue(int row, int col, int value);
        bool isComplete();
        string toString();

        string toString_d();
};
#endif
