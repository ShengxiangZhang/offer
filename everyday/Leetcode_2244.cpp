#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> cnt;
        for(int i = 0; i < tasks.size(); i++)
            cnt[tasks[i]]++;
        
        int res = 0;
        // 遍历哈希表
        for(const auto& pair : cnt) {
            if(pair.second == 1)
                return -1;
            if(pair.second % 3 == 0)
                res += pair.second/3;
            else
                res += pair.second/3 + 1;
        }
        return res;
    }
};