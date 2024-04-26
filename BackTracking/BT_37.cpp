#include<iostream>
#include<vector>

/***编写一个程序，通过填充空格来解决数独问题。***/
using namespace std;

class Solution {
public:
    bool isVaild(int row, int col, char k, vector<vector<char>>& board){
        // 同一行不能有重复
        for(int j = 0; j != col && j < board.size(); j++){
            if(board[row][j] == k)
                return false;
        }
        // 同一列不能重复
        for(int i = 0; i != row && i < board.size(); i++){
            if(board[i][col] == k)
                return false;
        }
        // 九宫格内不能重复
        int startRow = (row/3)*3;
        int startCol = (col/3)*3;
        for(int i = startRow; i < startRow + 3; i++ ){
            for(int j = startCol; j < startCol + 3; j++){
                if(board[i][j] == k)
                    return false;
            }
        }
        return true;
    }

    bool backtracking(vector<vector<char>>& board){
        // 终止条件

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board.size(); j++){
                // 直接++字符
                for(char k = '1'; k <= '9'; k++){
                    if(board[i][j] == '.'){
                        if(isVaild(i, j, k, board))
                        {
                            board[i][j] = k;
                            if(backtracking(board))
                                return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }

            }
                
        }
    return true;
}

    void solveSudoku(vector<vector<char>>& board) {

    }
};
