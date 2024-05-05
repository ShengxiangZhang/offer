#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:

    static bool comp(const vector<int> a, const vector<int> b){
        if(a[0] == b[0])
            return a[1] < b[1];
        return a[0] < b[0];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        int right = intervals[0][1];
        int count = 0;

        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] >= right)
                right = intervals[i][1];
            else{
                count++;
                right = min(right, intervals[i][1]);
            }
        }
        return count;
    }
};