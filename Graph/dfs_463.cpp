#include<iostream>
#include<vector>

/**岛屿的周长**/
using namespace std;

class Solution {
public:
    int dir[4][2] = {1,0,-1,0,0,1,0,-1};
    int res;
    void dfs(vector<vector<int>>& grid, int i, int j){
        if(grid[i][j] == 2)
            return;
        grid[i][j] = 2;
        for(int k = 0; k < 4;k++){
            int nexti = i + dir[k][0];
            int nextj = j + dir[k][1];
            if(nexti >= grid.size() || nexti < 0 
            ||nextj >= grid[0].size() || nextj < 0){
                res += 1;
                continue;
            }
            if( grid[nexti][nextj] == 0){
                res += 1;
                continue;
            }
            dfs(grid, nexti, nextj);            
        }
        return;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        res = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    dfs(grid, i, j);
                    return res;
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> nums = {{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
    s.islandPerimeter(nums);
    return 0;
}