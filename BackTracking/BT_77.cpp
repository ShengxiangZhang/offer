#include<iostream>
#include<vector>


/*给定两个整数n和k，返回范围[1, n]中所有可能的k个数的组合。
你可以按任何顺序返回答案。*/
using namespace std;

class Solution {
public:

    // 存放最终结果
    vector<vector<int>> res;    

    //存放路径
    vector<int> path;

    void backtracking(int n, int k, int index){
        // 终止条件，path中值等于k
        if(path.size() ==  k){
            res.push_back(path);
            return;
        }
            
        // 回溯
        for(int i = index; i <=  n-(k-path.size()) + 1; i++){
            path.push_back(i);
            // 进入下一层
            backtracking(n, k, i + 1);
            // 撤回节点
            path.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        // 调用回溯
        backtracking(n, k, 1);
        return res;
    }
};