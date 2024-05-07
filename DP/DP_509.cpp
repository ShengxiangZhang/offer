#include<iostream>
#include<vector>


/**斐波那契数**/
using namespace std;

// 递归法
/*
class Solution {
public:
    int fib(int n) {
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        return fib(n-1) + fib(n-2);
    }
};
*/

// 动态规划
// 时间复杂度O(n)，空间复杂度O(n)
class Solution {
public:
    int fib(int n) {
        if(n <=1)
            return n;
        
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n; i++)
            dp[i] = dp[i-1] + dp[i-2];
        return dp[n];
    }
};
