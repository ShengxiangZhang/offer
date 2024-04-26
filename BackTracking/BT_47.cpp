#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>

/***全排列***/
/*给定一个可包含重复数字的序列nums，按任意顺序 返回所有不重复的全排列*/
using namespace std;


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
        unordered_set<int> uset; // 用户去重
        for(int i = 0; i < nums.size(); i++){
            // 当前元素已经加入集合，跳过；同一层的重复元素，跳过
            if(used[i] == true || uset.find(nums[i]) != uset.end())
                continue;
            else{
                path.push_back(nums[i]);
                used[i] = true;
                uset.insert(nums[i]);
                backtracking(nums, used);
                // 退栈，回溯
                path.pop_back();
                used[i] = false;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // nums里的元素可以重复，情况变复杂，res里的集合不能有重复，需要去重
        vector<bool> used(nums.size(), false);// 记录元素的使用情况
        sort(nums.begin(), nums.end());
        backtracking(nums, used);
        return res;
    }
};
