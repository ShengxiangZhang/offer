#include<iostream>
#include<vector>

// 单调栈
// https://leetcode.cn/problems/find-the-most-competitive-subsequence/solutions/2788312/gen-zhao-wo-guo-yi-bian-shi-li-2ni-jiu-m-36c4/
using namespace std;


class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int len = nums.size();
        // 充当栈
        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            while( res.size() > 0 && (len - i) + res.size() > k && nums[i] < res[res.size()-1])
                res.pop_back();

            if(res.size() < k)
                res.push_back(nums[i]);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {71,18,52,29,55,73,24,42,66,8,80,2};
    vector<int> res = s.mostCompetitive(nums, 3);
    for(int num : res)
        cout << num << " ";
    system("pause");
    return 0;
}