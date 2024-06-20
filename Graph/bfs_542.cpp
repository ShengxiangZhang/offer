#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int dir[4][2] = {1,0,-1,0,0,1,0,-1};
    int bfs(vector<vector<int>>& mat, int i, int j){;
        queue<vector<int>> que;
        vector<int> start = {i, j, 0};
        que.push(start);
        while(!que.empty()){
            vector<int> ele = que.front();
            que.pop();
            for(int k = 0; k < 4; k++){
                int nexti = ele[0] + dir[k][0];
                int nextj = ele[1] + dir[k][1];
                if(nexti >= mat.size() || nexti < 0 || nextj >= mat[0].size() || nextj < 0)
                    continue;
                if(mat[nexti][nextj] == 0)
                    return ele[2] + 1;
                que.push({nexti, nextj, ele[2] + 1});
            }
        }
        return INT_MAX;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0)
                    continue;
                int pathLen = bfs(mat, i, j);
                mat[i][j] = pathLen;
            }
        }
        return mat;
    }
};