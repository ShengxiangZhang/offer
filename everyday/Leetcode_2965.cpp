#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;


class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> res;
        unordered_map<int,int> map;
        int n = grid.size();
        for(int i = 1; i <= n*n; i++)
            map[i] = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                auto it = map.find(grid[i][j]);
                if(it != map.end())
                    map.erase(it);
                else
                    res.push_back(grid[i][j]);
            }
        }
        res.push_back(map.begin()->first);
        return res;
    }
};