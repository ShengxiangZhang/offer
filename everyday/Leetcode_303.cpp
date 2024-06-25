#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

/**找到矩阵中的好子集**/
// 灵神题解：https://leetcode.cn/problems/find-a-good-subset-of-the-matrix/solutions/2305490/xiang-xi-fen-xi-wei-shi-yao-zhi-duo-kao-mbl6a/
class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        unordered_map<int,int> umap;
        for(int i = 0; i < grid.size(); i++){
            int mask = 0;
            for(int j = 0; j < grid[0].size(); j++){
                // grid[i][j]右移j位，与mask进行或运算
                mask |= grid[i][j] << j;
            }
            // 如果mask == 0,则第i行全为0，返回
            if(mask == 0)
                return {i};
            // umap中存上，同时也去除了重复的行
            umap[mask] = i;
        }

        // 双层循环遍历，如果任意两行进行与运算和为0，则返回这两行的序号
        for(auto& [x, i]: umap){
            for(auto& [y, j]: umap){
                if((x&y) == 0)
                    return {min(i,j),max(i,j)};
            }
        }
        return {};
    }
};