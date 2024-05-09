#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        // dp[i]表示i个节点可能构成的二叉搜索树的个数
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;

        // 递推公式
        // 缓冲区溢出
        for(int i = 3; i <= n; i++){
            for(int j = 0; j < i; j++)
                dp[i] += dp[j] * dp[i - j - 1];
        }
        return dp[n];
    }   
};

int main(){
    Solution s;
    int res = s.numTrees(2);
    cout << res;
    system("pause");
    return 0;
}