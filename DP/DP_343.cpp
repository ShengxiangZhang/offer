#include<iostream>
#include<vector>

using namespace std;
/**整数拆分**/


class Solution {
public:
    int integerBreak(int n) {

        // 难点1：dp[i]，分拆数字i，可以得到的最大乘积为dp[i]
        vector<int> dp(n+1);
        dp[2] = 1;
        
        // 难点2：递推公式
        for(int i = 3; i <= n; i++){
            for(int j = 1; j <= i/2; j++){
                dp[i] = max(dp[i], max(j*(i-j), j*dp[i-j]));
            }
        }
        return dp[n];
    }
};