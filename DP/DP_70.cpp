#include<iostream>
#include<vector>

/**爬楼梯**/
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n <=2)
            return n;
        // 确定dp[i]的意义：爬第i层楼梯，有dp[i]中方法
        vector<int> dp(n+1);
        // 初始化
        dp[1] = 1;
        dp[2] = 2;
        //确定递归的条件，dp[i] = dp[i-1] + dp[i-2]
        for(int i = 3; i <= n; i++)
            dp[i] = dp[i-1] + dp[i-2]; 

        return dp[n];
    }
};