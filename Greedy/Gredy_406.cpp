#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:

    static bool comp(vector<int> &a, vector<int> &b){
        if(a[0] == b[0])
            return a[1] < b[1];
        else
            return a[0] > b[0];
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // 先确定第一个维度
        sort(people.begin(), people.end(), comp);
        vector<vector<int>> que;
        // 再确定第二个维度
        for(int i = 0; i < people.size(); i++){
            int pos = people[i][1];
            que.insert(que.begin() + pos, people[i]);
        }
        return que;
    }
};