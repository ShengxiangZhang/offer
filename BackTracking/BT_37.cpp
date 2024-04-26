#include<iostream>
#include<vector>

/***编写一个程序，通过填充空格来解决数独问题。***/
using namespace std;

    /*class Solution {
    public:
        bool isVaild(int row, int col, char k, vector<vector<char>>& board){
            // 同一行不能有重复
            for(int j = 0; j < 9; j++){
                if(board[row][j] == k)
                    return false;
            }
            // 同一列不能重复
            for(int i = 0; i < 9; i++){
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
                for(int j = 0; j < board[0].size(); j++){
                    // 直接++字符
                    if(board[i][j] == '.'){
                        for(char k = '1'; k <= '9'; k++){
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
            backtracking(board);
        }
    };
*/

class Solution {
    public:
        bool isVaild(int row, int col, char k, vector<vector<char>>& board){
            // 同一行不能有重复
            for(int j = 0; j < 9; j++){
                if(board[row][j] == k)
                    return false;
            }
            // 同一列不能重复
            for(int i = 0; i < 9; i++){
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

        void backtracking(vector<vector<char>>& board){
            // 终止条件
            if(i = )

            for(int i = 0; i < board.size(); i++){
                for(int j = 0; j < board[0].size(); j++){
                    // 直接++字符
                    if(board[i][j] == '.'){
                        for(char k = '1'; k <= '9'; k++){
                            if(isVaild(i, j, k, board))
                            {
                                board[i][j] = k;
                                backtracking(board);
                                board[i][j] = '.';
                            }
                        }
                    }
                }      
            }
    }

        void solveSudoku(vector<vector<char>>& board) {
            backtracking(board);
        }
    };