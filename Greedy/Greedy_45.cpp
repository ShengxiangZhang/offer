#include<iostream>
#include<vector>


/***跳跃游戏II***/
using namespace std;

class Solution {
public: 
    
    int jump(vector<int>& nums) {
        if(nums.size() == 1)
            return 0;
        int count = 1;
        for(int i = 0; i < nums.size(); i++){
            int max = -1;
            int index = -1;
            if(nums[i] + i >= nums.size() - 1)
                return count;
            for(int j = 1; j <= nums[i]; j++){
                if(i + j + nums[i+j] >= nums.size() - 1)
                    return count + 1;
                if( i + j + nums[i+j] > max){
                    max = i + j + nums[i+j];
                    index = i + j;
                }   
            }
            i = index - 1;
            count++;
        }
        return count;
    }
};