#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

/**矩阵中严格递增的单元格数**/
using namespace std;

class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        // dp[i][j]表示到达mat[i][j]时，访问过单元格的最大数量
        int m = mat.size();
        int n = mat[0].size();

        // map时key有序的
        map<int, vector<pair<int,int>>> map;

        // 将值相同的位置放到一个vector里，一起处理
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++)
                map[mat[i][j]].push_back({i,j});
        }

        vector<int> maxRow(m), maxCol(n);
        for(auto& [_,pos]: map){
            // 记录dp最大值
            vector<int> mx;
            for(auto& [i, j]: pos){
                mx.push_back(max(maxRow[i], maxCol[j])+1);
            }
            for(int k = 0; k < pos.size(); k++){
                auto& [i, j] = pos[k];
                maxRow[i] = max(maxRow[i], mx[k]); // 更新第i行的最大dp值
                maxCol[j] = max(maxCol[j], mx[k]); // 更新第j列的最大dp值
            }
        }
        // max_element求最大值，返回的时指针
        return *max_element(maxRow.begin(), maxRow.end());
        // 若求最大值下标，return max_element(maxRow.begin(), maxRow.end()) - maxRow.begin();
    }
};