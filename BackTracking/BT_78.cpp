#include<iostream>
#include<vector>
#include<algorithm>

/*求子集*/
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    void backtracking(int index, vector<int>& nums, vector<int>& vec, vector<bool>& used){
        if(index == nums.size())
            return;
            
        for(int i = index; i < nums.size(); i++){
            if(i > 0 && nums[i-1] == nums[i] && used[i-1] == false)
                continue;
            vec.push_back(nums[i]);
            used[i] = true;
            res.push_back(vec);
            backtracking(i+1, nums, vec, used);
            vec.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> r;
        vector<bool> used(nums.size(), false);
        res.push_back(r);
        sort(nums.begin(), nums.end());
        backtracking(0, nums, r, used);
        return res;
    }
};