#include<iostream>
#include<vector>

/******/
using namespace std;

// 暴力解法（超时）
/*class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            int count = 0;
            for(int j = i ; j < nums.size(); j++){
                count += nums[j];
                max = count > max ? count : max;
            }
        }
        return max;
    }
};*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = INT_MIN;
        int count = 0;
        // 如果连续子序列的和是小于零的，直接放弃这个子序列（要想明白）
        // 为什么可以直接跳过整个和零的子序列？（因为从子序列的任何一个位置开始，到子序列结束的和都不会大于整个子序列的和，以为从子序列任何一个位置之前的和一定是大于0的）
        // 从子序列中任何一个位置开始到子序列结束的和一定都是小于零
        // 另外，子序列中任何一个位置的前序序列一定都是大于零的
        for(int i = 0; i < nums.size(); i++){
            count += nums[i];
            if(count > max)
                max = count;
            if(count < 0)
                count = 0;
        }
        return max;
    }
};