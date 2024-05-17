#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>

/**给你一个整数n，返回和为n的完全平方数的最少数量。**/
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1);
        for(int i = 0; i <= n; i++){
            dp[i] = i;
        }
        // 1.完全背包，所以j从小到大遍历，2.组合问题，所以先遍历物品再背包
        for(int i = 2; i <= sqrt(n); i++){
            for(int j = (i*i); j <= n; j++){
                dp[j] = min(dp[j], dp[j-(i*i)] + 1);
            }
        }
        return dp[n];
    }
};

int main(){
    Solution s;
    int res = s.numSquares(13);
    cout << res; 
    system("pause");
    return res;
}