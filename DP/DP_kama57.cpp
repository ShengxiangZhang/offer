#include<iostream>
#include<vector>

/***爬楼梯进阶***/
using namespace std;

int main(){
    int n;
    int m;
    cin >> n >> m;
    vector<int> dp(n+1);
    dp[0] = 1;

    // 完全背包问题，每个物品可以无限选择，先遍历容量再遍历物品
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){    
            if(i - j >= 0)
                dp[i] += dp[i-j];
        }
    }
    cout << dp[n];
    system("pause");
    return 0;
}