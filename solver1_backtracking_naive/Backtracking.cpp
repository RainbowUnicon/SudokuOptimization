#include "Backtracking.h"
#include <tuple>

tuple<int,int> Backtracking::getNext(){
    for(int r=0; r< Sudoku::SIZE; r++){
        for(int c=0; c< Sudoku::SIZE; c++){
            if(sudoku.getValue(r,c) == 0){
                return make_tuple(r,c); }
        }
    }
    return make_tuple(-1,-1);
}

bool Backtracking::solve(){
    if(sudoku.isComplete()){
        return true;
    }
    tuple<int,int> next = getNext();
    for(int value = 1; value <= 9; value ++){
        int row = get<0>(next);int col = get<1>(next);
        if(sudoku.canPlace(row, col, value)){
            sudoku.setValue(row,col,value);
            bool result = solve();
            if(result == true){
                return true;
            }
            else{
                sudoku.setValue(row, col, 0);
            }
        }
    }
    return false;
}

Sudoku Backtracking::getSudoku(){
    return sudoku;
}
