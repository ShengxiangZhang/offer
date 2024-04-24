#include<iostream>
#include<vector>
#include<algorithm>

/*给你一个无重复元素的整数数组candidates和一个目标整数target，找出candidates中可以使数字和为目标数target的所有不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合。*/
using namespace std;

// 回溯，剪枝
// 这一题没有想到for循环里每次i从哪里开始
class Solution {
public:

    vector<vector<int>> res;
    vector<int> path;
    // 回溯函数
    void backtracking(vector<int>& candidates, int target, int sum, int index){
        if(sum == target){
            res.push_back(path);
            return;
        }
        // 剪枝优化
        if(sum > target)
            return;

        // 剪枝优化，sum > target的情况可继续优化，看代码随想录的图
        // for(int i = index; i < candidates.size() && sum + candidates[i] <= target; i++)
        for(int i = index; i < candidates.size(); i++){
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, sum, i);
            sum -= candidates[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // 剪枝需要排序
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0);
        return res;
    }
};

int main(){
    vector<int> candidates = {2,3,6,7};
    int target = 7;
    Solution s;
    vector<vector<int>> res = s.combinationSum(candidates, target);
    for(int i = 0; i < res.size(); i++){
        for(int j =0; j < res[i].size();j++)
            cout << res[i][j];
        cout << "\n";
    }
    system("pause");
    return 0;
}