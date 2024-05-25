#include<iostream>
#include<vector>

using namespace std;

/*class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 1)
            return 0;
        // dp[i]表示截止到第i天的最大利润
        vector<int> dp(prices.size());
        dp[0] = 0;
        dp[1] = (prices[1]-prices[0]) > 0?(prices[1] - prices[0]):0;
        for(int i = 2; i < prices.size(); i++){
            if(prices[i] - prices[i-1] > 0) 
                dp[i] = dp[i-1] + prices[i] - prices[i-1];
            else
                dp[i] = dp[i-1];
        }
        return dp[prices.size() - 1];
    }
};*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1)
            return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(2));
        // dp[i][0]表示第i天持有股票拥有的最大现金数（负的）
        // dp[i][1]表示第i天不持有股票拥有的最大现金数（正的）
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for(int i = 1; i < prices.size(); i++){
            dp[i][0] = max(dp[i - 1][1] - prices[i], dp[i-1][0]);
            dp[i][1] = max(prices[i] + dp[i-1][0], dp[i-1][1]);
        }
        return dp[prices.size() - 1][1];
    }
};
