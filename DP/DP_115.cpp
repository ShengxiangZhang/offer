#include<iostream>
#include<vector>

/**不同的子序列**/
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        // dp[i][j]表示以t[j-1]结尾的t在s[i-1]结尾的s和中出现的个数
        vector<vector<long long>> dp(s.size()+1, vector<long long>(t.size()+1));

        // 初始化
        for(int i = 0; i < s.size(); i++)
            dp[i][0] = 1;

        // 递推
        for(int i = 1; i <= s.size(); i++){
            for(int j = 1; j <= t.size(); j++){
                // 由两部分组成：   
                // 1.不考虑s子串和t子串的最后一位字母
                // 2.不考虑s字串的最后一位字母
                if(s[i-1] == t[i-1])
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }

        return dp[s.size()][t.size()];
    }
};