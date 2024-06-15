#include<iostream>
#include<vector>

using namespace std;

    class Solution {
public:
    bool Pa;
    bool At;
    int dir[4][2] = {-1, 0, 0, -1, 1, 0, 0, 1};
    void dfs(vector<vector<int>>& heights, int i, int j, vector<vector<bool>>& visited){
        if(i >= heights.size() || j >= heights[0].size() || i < 0 || j < 0)
            return;
        if(visited[i][j])
            return;
        visited[i][j] = true;

        for(int k = 0; k < 4; k++){
            int nexti = i + dir[k][0];
            int nextj = j + dir[k][1];
            if(nexti >= heights.size() || nextj >= heights[0].size() || nexti < 0 || nextj < 0)
                continue;
            dfs(heights, nexti, nextj, visited);
        }
        return;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> Pa(m, vector<bool>(n, false));
        vector<vector<bool>> At(m, vector<bool>(n, false));

        // 遍历最左边和最右边的列
        for(int i = 0; i < m; i++){
            dfs(heights, i, 0, Pa);
            dfs(heights, i, n-1, At);
        }

        // 遍历最上面和最下面的行
        for(int j = 0; j < n; j++){
            dfs(heights, 0, j, Pa);
            dfs(heights, m-1, j, At);
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(Pa[i][j] && At[i][j])
                    res.push_back({i,j});
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> heights = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    vector<vector<int>> res = s.pacificAtlantic(heights);
    return 0;
}