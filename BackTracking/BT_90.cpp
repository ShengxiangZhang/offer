#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;

    void backtracking(vector<int>& nums, int index, vector<int>& vec){
        if(index == nums.size())
            return;

        // 使用set对本层元素去重
        unordered_set<int> uset;
        for(int i = index; i < nums.size(); i++){
            // 这题去重不一样，这题不能对nums进行排序，不能用之前的方法去重
            if(!vec.empty() && nums[i] < vec.back() || uset.find(nums[i]) != uset.end())
                continue;
            vec.push_back(nums[i]);
            uset.insert(nums[i]);
            if(vec.size() > 1)
                res.push_back(vec);
            backtracking(nums, i+1, vec);
            vec.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> vec;
        backtracking(nums, 0, vec); 
        return res;
    }
};
int main(){
    vector<int> nums = {7,7};
    Solution s;
    vector<vector<int>> r = s.findSubsequences(nums);
    cout << r.size();
    system("pause");
    return 0;
}