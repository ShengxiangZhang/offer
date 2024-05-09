#include<iostream>
#include<vector>

using namespace std;

/*
int main(){
    int M;
    int N;
    cin >> M >> N;
    vector<int> weight(M);
    vector<int> value(M);
    for(int i = 0; i < M; i++)
        cin >> weight[i];
    for(int i = 0; i < M; i++)
        cin >> value[i];
        
    // 定义二维dp数组
    // dp[i-1][j]表示，取第0-i个材料中的任意个，放入容量为j的背包中可以获得的最大价值
    vector<vector<int>> dp(M,vector<int>(N+1));

    for(int i = 0; i < M; i++)
        dp[i][0] = 0;

    for(int j = 1; j <= N; j++){
        if(weight[0] <= j)
            dp[0][j] = value[0];
    }

    // 递推公式
    for(int i = 1; i < M; i++){
        for(int j = 1; j <= N; j++){
            if(j-weight[i] >=0)
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    cout << dp[M-1][N];
    system("pause");
    return 0;
}
*/
int main(){
    int M;
    int N;
    cin >> M >> N;
    vector<int> weight(M);
    vector<int> value(M);
    for(int i = 0; i < M; i++)
        cin >> weight[i];
    for(int i = 0; i < M; i++)
        cin >> value[i];

    vector<int> dp(N+1);

    for(int i = 0; i < M; i++){
        for(int j = N; j >= weight[i]; j--)
            dp[j] = max(dp[j], dp[j-weight[i]] + value[i]);
    }
    cout << dp[N];
    system("pause");
    return 0;
}