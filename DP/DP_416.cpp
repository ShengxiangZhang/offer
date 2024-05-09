#include<iostream>
#include<vector>

using namespace std;

/**分割等和子集**/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        // 求和
        for(int i = 0; i < nums.size(); i++)
            sum += nums[i];
        
        // 如果不能被2整除，则不可能分割成两个等和子集
        if(sum %2 != 0)
            return false;
        
        // 转化为01背包
        int cap = sum / 2;

        vector<int> dp(cap+1);
        for(int i = 0; i < nums.size(); i++){
            for(int j = cap; j >= nums[i]; j--)
                dp[j] = max(dp[j], dp[j-nums[i]] + nums[i]);
        }
        
        // 这个背包要装满    
        if(dp[cap] == cap)
            return true;
        else
            return false;
    }
};

int main(){
    Solution s;
    vector<int> nums{1,5,11,5};
    s.canPartition(nums);
    return 0;
}