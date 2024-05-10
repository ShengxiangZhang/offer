#include<iostream>
#include<vector>

/**目标和**/
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        int count = 0;
        for(int i = 0; i < nums.size(); i++)
            sum += nums[i];

        if(abs(target) > sum)
            return 0;
            
        if((sum + target) % 2 != 0)
            return 0;

        int cap = (sum + target) / 2;
        
        // dp[i]表示装满容量为i的背包由几种方法
        vector<int> dp(cap+1);
        
        dp[0] = 1;

        for(int i = 0; i < nums.size(); i++){
            for(int j = cap; j >= nums[i]; j--)
                dp[j] += dp[j-nums[i]];
        }
        return dp[cap];
    }
};

int main(){
    Solution s;
    vector<int> nums{1};

    int a = s.findTargetSumWays(nums, 1);
    cout << a;
    system("pause");
    return 0;
}