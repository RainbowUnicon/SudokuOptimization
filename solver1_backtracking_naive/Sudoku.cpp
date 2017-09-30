#include <stdio.h>
#include <set>
#include <tuple>
#include "Sudoku.h"

using namespace std;

Sudoku::Sudoku(string textBoard){
    //Construct the board
    int i =0;
    for(int r = 0; r < SIZE; r++){
        vector<int> row;
        for(int c = 0; c < SIZE; c++){
            row.push_back(textBoard[i] - 48);
            i++;
        }
        board.push_back(row);
    }
}

bool Sudoku::canPlace(int row, int col, int value){
    set<tuple<int, int>> neighbors; 
    for(int i =0; i < SIZE; i++){
        neighbors.insert(make_tuple(row,i));
        neighbors.insert(make_tuple(i,col)); neighbors.insert(make_tuple(row/3 * 3 + i/3,col/3 * 3 + i%3)); }

    neighbors.erase(make_tuple(row,col));
    for(set<tuple<int,int>>::iterator item = neighbors.begin(); item != neighbors.end(); ++ item){
        int itemValue = board[get<0>(*item)][get<1>(*item)];
        if(itemValue == value){
            return false;
        }
    }
    return true;
}

int Sudoku::getValue(int row, int col){
    return board[row][col];
}

void Sudoku::setValue(int row, int col, int value){
    board[row][col] = value;
}

bool Sudoku::isComplete(){
    for(vector<vector<int>>::iterator row = board.begin(); row != board.end(); ++row){
        for(vector<int>::iterator slot = row->begin(); slot != row->end(); ++ slot){
            if((*slot) == 0){
                return false;
            }
        }
    }
    return true;
}

string Sudoku::toString(){
    string str;
    for(vector<vector<int>>::iterator row = board.begin(); row != board.end(); ++row){
        for(vector<int>::iterator slot = row->begin(); slot != row->end(); ++ slot){
            str.push_back((int)(*slot) + 48);
        }
    }
    return str;

}

string Sudoku::toString_d(){
    string str;
    for(vector<vector<int>>::iterator row = board.begin(); row != board.end(); ++row){
        for(vector<int>::iterator slot = row->begin(); slot != row->end(); ++ slot){
            str.push_back((int)(*slot) + 48);
            str.push_back(' ');
        }
        str.push_back('\n');
    }
    return str;
}
