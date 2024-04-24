#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


/*给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的每个数字在每个组合中只能使用 一次 。*/

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;


    void backtracking(int index, vector<int>& candidates, int target, int sum, vector<bool> used){
        if(sum == target){
            res.push_back(path);
            return;
        }

        for(int i = index; i < candidates.size() && sum + candidates[i] <= target; i++){
            if(i > 0 && candidates[i] == candidates[i-1] && used[i-1] == false)
                continue;
            path.push_back(candidates[i]);
            used[i] = true;
            sum += candidates[i];
            backtracking(i+1, candidates, target, sum, used);
            path.pop_back();
            // 同一层，如果used[i] == true，表示用过了
            used[i] = false;
            sum -= candidates[i];
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> used(candidates.size(), false);
        sort(candidates.begin(), candidates.end());
        backtracking(0, candidates, target, 0, used);
        return res;
    }
};