#include<iostream>
#include<vector>

/***加油站***/
using namespace std;

// 超时了
/*
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int count = 0;
        for(int i = 0; i < gas.size(); i++){
            int j = i;
            int len = cost.size();
            while(len > 0){
                count += gas[j % cost.size()];
                if(count < cost[j % cost.size()])
                    break;
                else
                    count -= cost[j % cost.size()];
                j++;
                len--;
            }
            if(len == 0)
                return i;
        }
        return 0;
    }
};*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // 剩油量数组   
        vector<int> rest;
        for(int i = 0; i < gas.size(); i++)
            rest.push_back(gas[i] - cost[i]);
        int curSum = 0;
        int totalSum = 0;
        int index = 0;
        for(int i = 0; i < gas.size(); i++){
            totalSum += rest[i];
            curSum += rest[i];
            if(curSum < 0){
                curSum = 0;
                index = i + 1;
            }
        }
        if(totalSum < 0)
            return -1;
        return index;
    }
};