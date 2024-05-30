#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

/**编辑距离**/
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1));
        
        // 初始化
        for(int i = 0; i <= word1.size(); i++)
            dp[i][0] = i;
        for(int j = 0; j <= word2.size(); j++)
            dp[0][j] = j;

        // 递推公式
        for(int i = 1; i <= word1.size(); i++){
            for(int j = 1; j <= word2.size(); j++){
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]})+1;
            }
        }
        return dp[word1.size()][word2.size()];
    }
};

int main(){
    string word1 = "";
    string word2 = "a";
    Solution s;
    int res = s.minDistance(word1, word2);
    return 0;
}