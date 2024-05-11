#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // dp[i]表示和为i的组合方案有dp[i]个
        vector<int> dp(target+1);

        dp[0] = 1;

        for(int j = 0; j <= target; j++){
            for(int i = 0; i < nums.size(); i++)
                if(j-nums[i] >=0 && INT_MAX - dp[j - nums[i]])
                    dp[j] += dp[j-nums[i]];
        }
        return dp[target];
    }
};