#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    
    static bool comp(const vector<int> a, const vector<int> b){
        return a[0] < b[0];   
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 1)
            return intervals;
        sort(intervals.begin(), intervals.end(), comp);
        vector<vector<int>> res;
        int left = intervals[0][0];
        int right = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] > right){
                res.push_back({left, right});
                left = intervals[i][0];
                right = intervals[i][1];
            }
            else{
                right = max(right, intervals[i][1]);
            }
        }
        res.push_back({left, right});
        return res;
    }
};