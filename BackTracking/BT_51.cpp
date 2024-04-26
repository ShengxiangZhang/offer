#include<iostream>
#include<vector>
#include<string>

using namespace std;

/***N皇后***/

// 自己的想法，申请了一个二维的used数组
/*
class Solution {
public:
    vector<vector<string>> res;
    vector<string> s;
    string queen(int index, int n){
        string str;
        for(int i = 0; i < n; i++){
            if(i != index)
                str += ".";
            else
                str += "Q";
        }
        return str;
    }
    void backtracking(int n, int depth, vector<vector<bool>>& used){
        // 终止条件
        if(s.size() == n){
            res.push_back(s);
            return;
        }

        // 回溯
        for(int i = 0; i < n; i++){
            int flag = 0;
            for(int j = depth-1; j >=0; j--){
                if(used[j][i] == true){
                    flag = 1;
                    break;
                }    
            }
            int m = depth -1;
            int k = i-1;
            int j = i+1;
            while(m >= 0){
                if(k >= 0 && used[m][k] == true){
                    flag = 1;
                    break;
                }
                if(j < n && used[m][j] == true){
                    flag = 1;
                    break;
                }
                k--;
                j++;
                m--;
            }

            if(flag == 1)
                continue;
            string str = queen(i,n);
            s.push_back(str);
            used[depth][i] = true;
            backtracking(n, depth + 1, used);
            s.pop_back();
            used[depth][i] = false;

        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<bool>> used;
        for(int i = 0; i < n; i++){
            vector<bool> vec(n, false);
            used.push_back(vec);
        }
        backtracking(n, 0, used);
        return res;
    }
};*/