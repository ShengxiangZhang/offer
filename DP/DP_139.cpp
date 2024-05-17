#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // 提高查询效率
        unordered_set wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1);
        dp[0] = true;
        for(int i = i; i <= s.size(); i++){
            for(int j = 0; j < i; j++){
                string word = s.substr(j, i-j);//substr(起始位置，截取个数)
                if(wordSet.find(word) != wordSet.end() && dp[j])
                    dp[i] = true;
            }
        }
        return dp[s.size()];
    }
};