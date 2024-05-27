#include<iostream>
#include<vector>
#include<string>

/**判断s是否是t的子序列**/
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        // dp[i][j]代表
        vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, 0));

        // 递推
        for(int i = 1; i <= s.size(); i++){
            for(int j = 1; j <= t.size(); j++){
                if(s[i-1] == t[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                if(dp[i][j] == s.size())
                    return true;
            }
        }
        if(dp[s.size()][t.size()] == s.size())
            return true;
        return false;
    }
};

int main(){
    Solution s;
    string str1 = "abc";
    string str2 = "ahbgdc";
    bool res = s.isSubsequence(str1, str2);
    return 0;

}