#include<iostream>
#include<string>
#include<unordered_map>

/***重新安排行程***/
using namespace std;

class Solution {
public:
    // <出发机场，<到达机场,航班次数>>
    unordered_map<string, unordered_map<string, int>> targets;

    // 回溯函数
    bool backtracking(int size, vector<string>& res){
        // 终止条件
        if(size == res.size())
            return true;


        // 回溯循环
        for(pair<string, int> target: targets[res[res.size()-1]]){
            
            if(target.second > 0){
                res.push_back(target.first);
                target.second--;
                if(backtracking(size,res))
                    return true;
                res.pop_back();
                target.second--;
            }
        }
        return false;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> res;

        for(vector<string> ticket : tickets){
            targets[ticket[0]][ticket[1]]++;
        }
        res.push_back("JFK");

        backtracking(tickets.size(), res);

        return res;

    }
};