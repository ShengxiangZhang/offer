#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    void backtracking(int index, vector<int>& nums, vector<int>& vec){
        if(index == nums.size())
            return;
            
        for(int i= index; i < nums.size(); i++){
            vec.push_back(nums[i]);
            res.push_back(vec);
            backtracking(i+1, nums, vec);
            vec.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> r;
        res.push_back(r);
        backtracking(0, nums, r);
        return res;
    }
};