#include<iostream>
#include<vector>

// dfs 有向图路径问题
/*所有可能的路径*/
using namespace std;

class Solution {
public:
    
    vector<vector<int>> res; // 存放所有路径
    vector<int> path; // 存放当前路径
    void dfs(vector<vector<int>>& graph, int x){
        // 终止条件，即到达目标节点
        if(x == graph.size()-1){
            res.push_back(path);
            return;
        }
        
        // 回溯
        for(int i = 0; i < graph[x].size(); i++){
            path.push_back(graph[x][i]);
            dfs(graph, graph[x][i]);
            path.pop_back();
        }
        return;
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        path.push_back(0);
        dfs(graph, 0);
        return res;
    }
};