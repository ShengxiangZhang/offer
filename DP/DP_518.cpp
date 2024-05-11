#include<iostream>

#include<vector>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        // 凑成总金额为i，共有dp[i]种组合方法
        vector<int> dp(amount + 1);

        // 初始化
        dp[0] = 1;

        // 递推公式
        for(int i = 0; i < coins.size(); i++){
            for(int j = coins[i]; j <= amount; j++){
                // d[j]等于上一层的d[j]加上的dp[j-coins]，具体分析见md笔记
                dp[j] += dp[j-coins[i]];
            }
        }
        return dp[amount];
    }
};