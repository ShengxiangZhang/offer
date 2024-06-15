#include<iostream>
#include<vector>

using namespace std;

/**最大人工岛**/

class Solution {
public:
    int cnt;
    int dir[4][2] = {-1, 0, 0, -1, 1, 0, 0, 1}; 
    void dfs(vector<vector<int>>& grid, int i, int j, int v){
         if(i >= grid.size() || j >= grid[0].size() || i < 0 || j < 0)
            return;
        
        if(grid[i][j] == v || grid[i][j] == 0)
            return;
        grid[i][j] = v;
        cnt++;

        for(int k = 0; k < 4; k++){
            int nexti = i + dir[k][0];
            int nextj = j + dir[k][1];
            if(nexti >= grid.size() || nextj >= grid[0].size() || nexti < 0 || nextj < 0)
                continue;
            dfs(grid, nexti, nextj, v);
        }
        return;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int flag = 0;
        int v = 1;
        int res = 0;
        int maxS = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    flag = 1;
                    res = 0;
                    v++;
                    for(int k = 0; k < 4; k++){
                        int nextx = i + dir[k][0];
                        int nexty = j + dir[k][1];
                        if(nextx >= m || nexty >= n || nextx < 0 || nexty < 0)
                                continue;
                        else if(grid[nextx][nexty] != 0 && grid[nextx][nexty] != v-1){
                            cnt = 0;
                            dfs(grid,nextx,nexty,v);
                            res += cnt;
                        }
                    }
                    maxS = max(maxS, res);
                }
            }
        }
        if(flag == 0)
            return m*n;
        return maxS + 1;
    }
};

int main(){

    vector<vector<int>> grid = {{0,0,0,0,0,0,0},
                                {0,1,1,1,1,0,0},
                                {0,1,0,0,1,0,0},
                                {1,0,1,0,1,0,0},
                                {0,1,0,0,1,0,0},
                                {0,1,0,0,1,0,0},
                                {0,1,1,1,1,0,0}};
    Solution s;
    int res = s.largestIsland(grid);
    return 0;

    
}
