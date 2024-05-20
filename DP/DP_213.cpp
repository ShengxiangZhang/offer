#include<iostream>
#include<vector>

/**打家劫舍2**/
using namespace std;

class Solution {
public:
    int robRange(vector<int>& nums, int left, int right) {
        // 从nums[0]-nums[i]，可以偷的最大金额是dp[i]
        vector<int> dp(nums.size(), 0);
        dp[left] = nums[left];
        dp[left + 1] = max(nums[left], nums[left+1]);

        for(int i = left+2; i <= right; i++)
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
       
        return dp[right];
    }

    int rob(vector<int>& nums){
        if(nums.size() == 1)
            return nums[0];
        if(nums.size() == 2)
            return max(nums[0], nums[1]);
        int res1 = robRange(nums, 0, nums.size()-2);
        int res2 = robRange(nums, 1, nums.size()-1);
        return max(res1, res2);
    }
};
