#include<iostream>
#include<vector>

using namespace std;

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
            dp[i][0] = max(-prices[i], dp[i-1][0]);
            dp[i][1] = max(prices[i] + dp[i-1][0], dp[i-1][1]);
        }
        return dp[prices.size() - 1][1];
    }
};

int main(){
    vector<int> nums{7,1,5,3,6,4};
    Solution s;
    int res = s.maxProfit(nums);
    return 0;
}