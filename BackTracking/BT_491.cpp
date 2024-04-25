#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*给你一个整数数组nums，找出并返回所有该数组中不同的递增子序列，递增子序列中至少有两个元素。你可以按任意顺序返回答案。*/

class Solution {
public:
    vector<vector<int>> res;

    void backtracking(vector<int>& nums, int index, vector<int>& vec, vector<bool> used){
        if(index == nums.size())
            return;

        for(int i = index; i < nums.size(); i++){
            if(vec.size() == 0 || (vec.size() > 0 && nums[i] >= vec[vec.size()-1])){
                if(nums[i-1] = nums[i] && used[i] == false)
                    continue;
                vec.push_back(nums[i]);
                used[i] = true;
                if(vec.size() > 1)
                    res.push_back(vec);
                backtracking(nums, i+1,vec, used);
                vec.pop_back();
                used[i] = false;
            }
            else
                continue;
        }

    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> vec;
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtracking(nums, 0, vec, used);
        return res;
    }
};