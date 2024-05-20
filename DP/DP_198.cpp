#include<iostream>
#include<vector>

/**打家劫舍1**/
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        if(nums.size() == 2)
            return nums[0] > nums[1] ? nums[0]: nums[1];

        // 从nums[0]-nums[i]，可以偷的最大金额是dp[i]
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = nums[0] > nums[1] ? nums[0]: nums[1];

        for(int i = 2; i < nums.size(); i++)
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
       
        return dp[nums.size() - 1];
    }
};


int main(){
    Solution s;
    vector<int> nums{1,2,3,1};
    int res = s.rob(nums);
    cout << res;
    system("pause");
    return 0;
}

