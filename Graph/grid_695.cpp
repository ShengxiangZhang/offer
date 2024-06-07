#include<iostream>
#include<vector>
#include<queue>


/*最大面积*/
class Solution {
public:
    // 深搜，找没有相连的岛屿
    int res;
    void dfs(vector<vector<int>>& grid, int i, int j){
        if(i >= grid.size() || j >= grid[0].size() || i < 0 || j < 0)
            return;
        if (grid[i][j] == 2 || grid[i][j] == 0) 
            return;
        grid[i][j] = 2;
        res++;
        // 四个方向开始深度遍历
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
        dfs(grid, i-1, j);
        dfs(grid, i+1, j);
        return;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxRes= 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    res = 0;
                    dfs(grid, i, j);
                    maxRes = max(res, maxRes);
                }
            }
        }
        return maxRes;
    }
};