#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:
    static bool comp(const vector<int> a, const vector<int> b){
        return a[0] < b[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), comp);
        int count = 1;
        int left = points[0][0];
        int right = points[0][1];

        for(int i = 1; i < points.size(); i++){
            if(points[i][0] >= left && points[i][0] <= right){
                left = points[i][0];
                if(points[i][1] < right)
                    right = points[i][1];
            }
            else{
                count++;
                left = points[i][0];
                right = points[i][1];
            }
        }
        return count;
    }
};

int m452n(){
    Solution s;
    vector<vector<int>> v{{10,16},{2,8},{1,6},{7,12}};
    s.findMinArrowShots(v);
    return 0;
}