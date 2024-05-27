#include<iostream>
#include<vector>

/**最长递增子序列**/
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 1)
            return 1;
        int maxdp = 0;
        // dp[i]表示nums[0-i]中nums[i]为尾元素的最长递增子序列
        vector<int> dp(nums.size(), 1);
        for(int i = 1; i < nums.size(); i++){
            // 遍历从0-(i-1)，找到以nums[i]为尾元素的最长子序列
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j]+1);
            }
            maxdp = max(maxdp, dp[i]);
        }
        return maxdp;
    }
};