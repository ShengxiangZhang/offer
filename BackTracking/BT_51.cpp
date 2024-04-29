#include<iostream>
#include<vector>
#include<string>

using namespace std;


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
    void backtracking(int n, int depth, vector<vector<bool>> used){
        // 终止条件
        if(s.size() == n){
            res.push_back(s);
            return;
        }

        // 回溯
        for(int i = 0; i < n; i++){
            int flag = 0;
            for(int j = 0; j < depth; j++   ){
                if(used[j][i] == true){
                    flag = 1;
                    break;
                }
            }
            if(flag == 1)
                continue;

            if(depth-1 > 0){
                if((i-1>0 && used[depth-1][i-1] == true))
                    continue;
                if((used[depth-1][i+1] == true))
                    continue;
            }
            string str = queen(i,n);
            s.push_back(str);
            used[depth][i] = true;
            backtracking(n, depth + 1, used);
            s.pop_back();

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
};