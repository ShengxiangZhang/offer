#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int res;
    int flag;
    void dfs(vector<vector<int>>& grid, int i, int j){
        if(i >= grid.size() || j >= grid[0].size() || i < 0 || j < 0){
            flag = 1;
            return;
        }
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
    int numEnclaves(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    res = 0;
                    flag = 0;
                    dfs(grid,i,j);
                    if(flag == 0)
                        ans += res;
                }  
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = { {0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}};
    int res = s.numEnclaves(grid);
    
    return 0;
}