#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        // dp[i][j]表示要使以word1[i-1]结尾的word1和以word2[j-1]为结尾的word2相同要删除的最少元素
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1));

        // 初始化
        for(int i = 0; i <= word1.size(); i++)
            dp[i][0] = i;

        for(int j = 1; j <= word2.size(); j++)
            dp[0][j] = j;

        // 递推
        for(int i = 1; i <= word1.size(); i++){
            for(int j = 1; j <= word2.size(); j++){
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1]; // 不需要删除元素
                else{
                    dp[i][j] = min(dp[i-1][j] + 1, dp[i][j-1] + 1);
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};

int main(){
    Solution s;
    string s1 = "a";
    string s2 = "b";
    int res = s.minDistance(s1, s2);
    return 0;
}