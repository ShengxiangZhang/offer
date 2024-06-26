#include<iostream>
#include<vector>

using namespace std;
/*
class Solution {
public:
    vector<bool> vis;
    vector<vector<int>> match;
    int num;
    void backtracking(int index, int n){
        // 终止条件
        if(index == n+1){
            num++;
            return;
        }

        // 回溯
        for(auto& x: match[index]){
            if(!vis[x]){
                vis[x] = true;
                backtracking(index+1, n);
                vis[x] = false;
            }

        }

    }
    int countArrangement(int n) {
        vis.resize(n+1, false);
        match.resize(n+1);
        num = 0;
        // 优化
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i % j == 0 || j % i == 0)
                    match[i].push_back(j);
            }
        }
        backtracking(1, n);
        return num;
    }
};*/