#include<iostream>
#include<vector>

using namespace std;

/***摆动序列***/

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int count = 0;
        int preDiff = 0;
        int curDiff = 0;
        for(int i = 0; i < nums.size() -1 ; i++){
            curDiff = nums[i+1] - nums[i];
            if((curDiff > 0 && preDiff <= 0) || (curDiff < 0 && preDiff >= 0)){
                count++;
                            preDiff = curDiff;
            }
        }
        return count;
    }
};