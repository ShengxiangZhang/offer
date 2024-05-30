#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        // dp[i][j]表示s[i-j]是否是一个
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(),false));

        // 表示有多少个回文串
        int res = 0;
        // 初始化

        // 递推公式,遍历顺序比较重要
        for(int i = s.size()-1; i >=0; i--){
            for(int j = i; j < s.size(); j++){
                if(s[i] == s[j]){
                    if(j-i <= 1){
                         res++;
                         dp[i][j] = true;
                    } 
                    else if(dp[i+1][j-1]){
                        res++;
                         dp[i][j] = true;
                    }
                }
            }
        }
        return res;
    }
};