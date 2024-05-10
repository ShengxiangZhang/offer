#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        // dp[i][j]表示最多有i个0和j个1的子集的最大长度
        vector<vector<int>> dp(m+1, vector<int>(n+1));

        // 遍历物品
        for(int k = 0;k < strs.size(); k++){
            int oneNum = 0;
            int zeroNum = 0;
            // 统计物品重量
            for(char c : strs[k]){
                if(c == '0')
                    zeroNum++;
                else
                    oneNum++;
            }
            // 变成了一个二维的背包，容量有两个维度，0维度和1维度
            for(int i = m; i >= zeroNum; i--){
                for(int j = n; j >= oneNum; j--)
                dp[i][j] = max(dp[i][j], dp[i-zeroNum][j-oneNum] + 1);
            }
        }
        return dp[m][n];
    }
};