#include<iostream>
#include<vector>

/*找出所有相加之和为 n 的 k 个数的组合，且满足下列条件：*/

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(int k, int n, int index){
        if(path.size() == k){
            int sum = 0;
            for(int i = 0; i < k; i++)
                sum += path[i];
            if(sum == n)
                res.push_back(path);
            return;
        }

        for(int i = index; i < 9 - (k-path.size()) + 1; i++){
            path.push_back(i);
            backtracking(k, n, i+1);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k, n, 1);
        return res;
    }
};
