#include<iostream>
#include<vector>

using namespace std;

/***零钱兑换***/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        // dp[i]表示凑成金额为i所需的最少硬币数
        vector<int> dp(amount+1, INT_MAX);

        // 初始化
        dp[0] = 0;

        for(int i = 0; i < coins.size(); i++){
            for(int j = coins[i]; j <= amount; j++){
                if( dp[j-coins[i]] < INT_MAX)
                    dp[j] = min(dp[j], dp[j-coins[i]] + 1);
            }
        }
        if(dp[amount] == INT_MAX)
            return -1;
        else
            return dp[amount];
    }   
};

int main(){
    Solution s;
    vector<int> coins{1, 2, 5};
    int dp = s.coinChange(coins, 11);
    cout << dp;
    system("pause");
    return 0;
}