#include<iostream>
#include<vector>
#include<queue>

/*岛屿数量*/
using namespace std;

class Solution {
public:
    // 深搜，将所有属于一块岛屿的所有陆地给标记
    void dfs(vector<vector<char>>& grid, int i, int j){
        if(i >= grid.size() || j >= grid[0].size())
            return;
        if (grid[i][j] == '2' || grid[i][j] == '0') 
            return;
        grid[i][j] = '2';

        // 四个方向开始深度遍历
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
        dfs(grid, i-1, j);
        dfs(grid, i+1, j);

        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    res++;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }
};

/*
class Solution {
public:
    queue<int, int> que; // que<i,j>
    void bfs(vector<vector<char>>& grid, int i, int j){
        queue<pair<int, int>> que;
        que.push({i, j});
        while(!que.empty()){
            pair<int ,int> cur = que.front(); 
            que.pop();
            grid[i][j] = '2';
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    res++;
                    bfs(grid, i, j);
                }
            }
        }
        return res;
    }
};
*/
int main(){
    Solution s;
    vector<vector<char>> grid = {{'1','1','1','1','0'},
                                {'1','1','0','1','0'},
                                {'1','1','0','0','0'},
                                {'0','0','0','0','0'}};
    int res = s.numIslands(grid);
    return 0;
}