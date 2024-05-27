#include<iostream>
#include<vector>
#include<string>

/**1143. 最长公共子序列**/
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // dp[i][j]表示以nums1中第i个元素和nums2中第j个元素结尾的最长子数组长度
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size()));
        int maxLen = 0;

        // 初始化
        int flag = 0;
        for(int j = 0; j < text2.size();j++){
            if(text1[0] == text2[j] || flag == 1){
                dp[0][j] = 1;
                flag = 1;
            }
        }
        flag = 0;
         for(int i = 0; i < text1.size();i++){
            if(text2[0] == text1[i] || flag == 1){
                dp[i][0] = 1;
                flag = 1;
            }
        }

        // 递推公式要琢磨一下，dp[i][j]应该由dp[i-1][j-1]的来
        for(int i = 1; i < text1.size(); i++){
            for(int j = 1; j < text2.size(); j++){
                if(text1[i] == text2[j])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[text1.size()-1][text2.size()-1];
    }
};
int main(){
    Solution s;
    string str1 = "abc";
    string str2 = "def";
    int res = s.longestCommonSubsequence(str1, str2);
    return 0;
}