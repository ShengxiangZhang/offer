#include<iostream>
#include<vector>
#include <iomanip> 

using namespace std;

class Solution {
public:
    vector<vector<int>> maxProfit(vector<int>& prices) {
        //if (prices.size() == 0) return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(5, 0));
        dp[0][1] = -prices[0];
        dp[0][3] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
            dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
        }
        return dp;
    }
};

int main(){
    Solution s;
    vector<int> p{3,3,5,0,0,3,1,4};
    vector<vector<int>> dp = s.maxProfit(p);
    for(int i = 0; i < p.size(); i++){
        for(int j = 0; j < 5; j++)
            cout << setw(4) << right << dp[i][j] << " ";
        cout << endl;
    }
    system("pause");
    return 0;
}