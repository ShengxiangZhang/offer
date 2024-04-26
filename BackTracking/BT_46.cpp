#include<iostream>
#include<vector>

/***全排列***/
/*给定一个不含重复数字的数组nums，返回其所有可能的全排列。你可以按任意顺序返回答案*/
using namespace std;

// 我的思路
class Solution {
public:
    // 存放答案
    vector<vector<int>> res;
    vector<int> path;
    // 回溯
    void backtracking(vector<int>& nums, vector<bool> used){
        // 终止条件
        if(path.size() == nums.size()){
            res.push_back(path);
            return;
        }
        // 循环
        for(int i = 0; i < nums.size(); i++){
            // 当前元素已经加入集合，跳过
            if(used[i] == true)
                continue;
            else{
                path.push_back(nums[i]);
                used[i] = true;
                backtracking(nums, used);
                // 退栈，回溯
                path.pop_back();
                used[i] = false;
            }
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        // 全排列，集合里元素不能重复，顺序不同
        vector<bool> used(nums.size(), false);// 记录元素的使用情况
        backtracking(nums, used);
        return res;
    }
};