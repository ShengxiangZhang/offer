#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;

    void backtracking(vector<int>& nums, int index, vector<int>& vec, vector<bool>& used){
        if(index == nums.size())
            return;

        for(int i = index; i < nums.size(); i++){
            if(vec.size() == 0 || (vec.size() > 0 && nums[i] >= vec[vec.size()-1])){
                if(i > 0 && nums[i-1] == nums[i] && used[i-1] == false)
                    continue;
                vec.push_back(nums[i]);
                used[i] = true;
                if(vec.size() > 1)
                    res.push_back(vec);
                backtracking(nums, i+1, vec, used);
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
int main(){
    vector<int> nums = {7,7};
    Solution s;
    vector<vector<int>> r = s.findSubsequences(nums);
    cout << r.size();
    system("pause");
    return 0;
}