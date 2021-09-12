//
//  main.cpp
//  Sudoku
//
//  Created by 万嘉威 on 2021/09/09.
//

#include <iostream>
#include "sudoku.h"
//#pragma once
using namespace std;

int main() {
    int *input;
    input = new int[81];
    cout<<"请按顺序输入题目，空格用‘0’表示"<<endl;
    for(int i = 0; i < 81; ++i)
        cin>>input[i];
    sudoku sd(input);
    cout<<"解题结果："<<endl;
    if(sd.solveSudoku() == true)
        sd.sudokuGrid();
    else
        cout<<"无解"<<endl;
    return 0;
}
