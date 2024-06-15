#include<iostream>
#include<vector>

/**被围绕的区域 **/
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j){
        if(i >= grid.size() || j >= grid[0].size() || i < 0 || j < 0)
            return;

        if (grid[i][j] == 'A' || grid[i][j] == 'X') 
            return;

        grid[i][j] = 'A';

        // 四个方向开始深度遍历
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
        dfs(grid, i-1, j);
        dfs(grid, i+1, j);
        return;
    }
    
    void solve(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
       // 找左右边界处的'O'
        for(int i = 0; i < n; i++){
            if(grid[i][0] == 'O')
                dfs(grid, i, 0);
            if(grid[i][m-1] == 'O')
                dfs(grid, i, m-1);
        }
        
        // 找上下边界处的'O'
        for(int j = 0; j < m; j++){
            if(grid[0][j] == 'O')
                dfs(grid, 0, j);
            if(grid[n-1][j] == 'O')
                dfs(grid, n-1, j);
        }

        // 再遍历一遍
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 'O')
                    grid[i][j] = 'X';
                else if(grid[i][j] == 'A')
                    grid[i][j] = 'O';
            }
        }
    }
};