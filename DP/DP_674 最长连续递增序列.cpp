#include<iostream>
#include<vector>

/*最长连续递增序列*/
using namespace std;

/*
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size() == 1)
            return 1;
        int maxLen = 1;
        
        int left = 0; // 记录递增序列的开始位置
        int right = 1; // 记录递增序列的结束位置
        while(right < nums.size()){
            if(nums[right] <= nums[right - 1]){
                maxLen = max(maxLen, right-left);
                left = right;
            }
            right++;
        }
        // 最后，right超出num.size(),直接跳出while,需再一次比较
        return max(maxLen, right-left);
    }
};
*/

// 动态规划
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        // 以num[i]为尾元素的最长子序列
        int maxdp = 1;
        vector<int> dp(nums.size(),  1);
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i-1])
                dp[i] = dp[i-1] + 1;
            maxdp = max(dp[i], maxdp);
        }
        return maxdp;
    }   
};