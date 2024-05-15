#include<iostream>
#include<vector>

/***吃掉橘子的最少天数**/

// 超时
using namespace std;

/*class Solution {
public:
    int DP(int n){
        if(n <= 2)
            return n;
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        dp[2] = 2;

        for(int i = 3; i <= n; i++){
            int way1 = INT_MAX;
            int way2 = INT_MAX;
            int way3 = INT_MAX;
            if(i % 3 == 0)
                way1 = dp[i-2*(i/3)] + 1;
            if(i % 2 == 0)
                way2 = dp[i/2] + 1;
            way3 = dp[i-1] + 1;
            
            // 选最小的
            int minDate = INT_MAX;
            minDate = min(way1, way2);
            minDate = min(minDate, way3);
            dp[i] = minDate;
        }
        return dp[n];
    }
    int minDays(int n) {
        if(n <= 2)
            return n;
        int way1 = 0;
        int way2 = 0;
        if(n % 2 == 0 && n % 3 == 0){
            way1 = DP(n/2) + 1;
            cout << "way1 " << way1 << endl;
            way2 = DP(n/3) + 1;
            cout << "way2 " << way2 << endl;
        }
        else if(n % 3 == 0){
            way1 = DP((n-1)/2) + 2;
            way2 = DP(n/3) + 1;
        }
        else if(n % 2 == 0){
            way1 = DP(n/2) + 1;
            if((n-1) % 3 == 0 )
                way2 = DP((n-1)/3) + 2;
            else
                way2 = DP((n-2)/3) + 3;
        }
        else
        {
            way1 = DP((n-1)/2) + 2;
            way2 = DP((n-2)/3) + 3;
        }
        return min(way1,way2);
    }
};

*/

/*递归*/
class Solution {
public:
    int minDays(int n) {
        if(n <= 2)
            return n;

        if(n % 2 == 0 && n % 3 == 0)
            return min(minDays(n/2) + 1, minDays(n/3) + 1);
        else if(n % 3 == 0){
            return min(minDays((n-1)/2) + 2, minDays(n/3) + 1);
        }
        else if(n % 2 == 0){
            int t1 = 0;
            int t2 = 0;
            t1 = minDays(n/2) + 1;
            if((n-1) % 3 == 0)
                t2 = minDays((n-1)/3) + 2;
            else
                t2 = minDays((n-2)/3) + 3;
            return min(t1,t2);
        }
        else
        {
            int t1 = 0;
            int t2 = 0;
            t1 = minDays((n-1)/2) + 2;
            if((n-1)% 3 == 0)
                t2 = minDays((n-1)/3) + 2;
            else
                t2 = minDays((n-2)/3) + 3;
            return min(t1,t2);
        }
        return 0;
    }
};

int main(){
    Solution s;
    int r = s.minDays(182);
    cout << r;
    system("pause");
    return 0;
}