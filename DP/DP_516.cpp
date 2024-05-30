#include<iostream>
#include<string>
#include<vector>

/**最长回文子序列**/
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        // dp[i][j]表示s[i-j]中包含的最长回文子序列
        vector<vector<int>> dp(s.size(), vector<int>(s.size(),0));

        // 初始化,全为0就行

        // 递推公式, 遍历顺序比较重要
        for(int i = s.size()-1; i >=0; i--){
            for(int j = i; j < s.size(); j++){
                if(s[i] == s[j]){ 
                    if(j==i) // 单个字符
                        dp[i][j] = 1;
                    else // 删除首尾字符后的最长长度+2
                        dp[i][j] = dp[i+1][j-1] + 2;
                }
                else // 不相等的时候有两种情况，删除首字符和删除尾字符
                    dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
            }
        }
        return dp[0][s.size()-1];
    }
};

int main(){
    string s = "bbbab";
    Solution so;
    int res = so.longestPalindromeSubseq(s);
    return 0;
}

