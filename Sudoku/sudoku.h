//
//  sudoku.h
//  Sudoku
//
//  Created by 万嘉威 on 2021/09/09.
//

#ifndef sudoku_h
#define sudoku_h


#endif /* sudoku_h */

#include <iostream>
using namespace std;

class sudoku
{
private:
    int grid[9][9] = {0}, col, row, num, boxStartCol, boxStartRow;
public:
    sudoku(int*);
    ~sudoku();
    bool isPresentInCol(int, int);
    bool isPresentInRow(int, int);
    bool isPresentInBox(int, int, int);
    bool findEmptyPlace(int&, int&);
    bool isValidPlace(int, int, int);
    bool solveSudoku();
    void sudokuGrid();
};

sudoku::sudoku(int *input)
{
    for(int i = 0; i < 9; ++i)
        for(int j = 0; j < 9; ++j)
            grid[i][j] = *(input++);
}

sudoku::~sudoku()
{
}

bool sudoku::isPresentInCol(int col, int num) // 检查该数字是否已经存在于某列
{
    for(int row = 0; row < 9; ++row)
        if(grid[row][col] == num)
            return true;
    
    return false;
}

bool sudoku::isPresentInRow(int row, int num) // 检查该数字是否已经存在于某行
{
    for(int col = 0; col < 9; ++col)
        if(grid[row][col] == num)
            return true;
    
    return false;
}

bool sudoku::isPresentInBox(int boxStartRow, int boxStartCol, int num) // 检查该数字是否已经存在于某个方块
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row+boxStartRow][col+boxStartCol] == num)
                return true;

    return false;
}

void sudoku::sudokuGrid() // 打印结果
{
    for(int row = 0; row < 9; ++row)
    {
        for(int col = 0; col < 9; ++col)
        {
            if(col == 3 || col == 6)
                cout<<"|";
            cout<<grid[row][col]<<" ";
        }
        if(row == 2 || row == 5)
        {
            cout<<endl;
            for(int i = 0; i < 9; ++i)
                cout<<"---";
        }
        cout<<endl;
    }
}

bool sudoku::findEmptyPlace(int &row, int &col) // 寻找空闲的位置，用引用返回空闲的位置
{
    for(row = 0; row < 9; ++row)
        for(col = 0; col < 9; ++col)
            if(grid[row][col] == 0)
                return true;
    
    return false;
}

bool sudoku::isValidPlace(int row, int col, int num){
   // 检查填写是否合法
   return !isPresentInRow(row, num) && !isPresentInCol(col, num) && !isPresentInBox(row - row%3 ,
col - col%3, num);
}

bool sudoku::solveSudoku()
{
    int row, col;
    if (!findEmptyPlace(row, col))
        return true; // 当所有位置都被填满
    for (int num = 1; num <= 9; num++)
    {
        if (isValidPlace(row, col, num))
        {
            grid[row][col] = num;
            if (solveSudoku())
                return true;
            grid[row][col] = 0;
        }
    }
    return false;
}
