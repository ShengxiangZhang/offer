#include<iostream>
#include<vector>

using namespace std;

int main(){
    int N;
    int V;
    cin >> N >> V;
    vector<int> weight(N);
    vector<int> value(N);

    for(int i = 0; i < weight.size(); i++)
        cin >> weight[i] >> value[i];

    // dp[i]表示容量为i的背包最多可装的材料价值
    vector<int> dp(V+1);

    for(int i = 0; i < weight.size(); i++){
        int count = 0;
        // 完全背包，每种材料可选无数次，内层遍历顺序和01背包不同
        for(int j = weight[i]; j <= V; j++)
            dp[j] = max(dp[j], dp[j-weight[i]] + value[i]);

    }
    cout << dp[V];
    system("pause");
    return 0;
}