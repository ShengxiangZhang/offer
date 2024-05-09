#include<iostream>
#include<vector>

/**最小花费爬楼梯**/
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // dp[i]：到达第i阶楼梯所消耗的体力
        vector<int> dp(cost.size() + 1);
        dp[0] = 0;
        dp[1] = 0;

        // 递推，dp[i-1]跳到dp[i]需要花费dp[i-1]+cost[i-1]
        for(int i = 2; i <= cost.size(); i++){
            // 跳2格
            int temp1 = dp[i-2] + cost[i-2];
            // 跳1格
            int temp2 = dp[i-1] + cost[i-1];
            dp[i] = temp1 < temp2 ? temp1:temp2;
        }
        return dp[cost.size()];
    }   
};