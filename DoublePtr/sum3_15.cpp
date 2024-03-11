#include<iostream>
#include<vector>

using namespace std;

/*
给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请

你返回所有和为 0 且不重复的三元组。
*/


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int len = nums.size();
        //数组排序
        for(int i = 0; i<len;i++){
            for(int j = i+1;j<len;j++){
                if(nums[i] > nums[j])
                {
                    int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                }
            }
        }
        //for(int i = 0; i<len;i++)
            //cout << nums[i] <<' ';



        for(int i = 0; i<len-2;i++){
            if(nums[i] > 0)
                return ans;

            //正确去重
            if(i>0 && nums[i-1] == nums[i])
                continue;
            int slowIndex = i + 1;
            int fastIndex = nums.size() - 1;
            while(slowIndex < fastIndex){
                if(nums[i] + nums[slowIndex] + nums[fastIndex] > 0)
                    fastIndex--;
                else if(nums[i] + nums[slowIndex] + nums[fastIndex] < 0)
                    slowIndex++;
                else{
                    ans.push_back({nums[i],nums[slowIndex],nums[fastIndex]});
                    while(slowIndex < fastIndex && nums[fastIndex] == nums[fastIndex-1])
                        fastIndex--;
                    while(slowIndex < fastIndex && nums[slowIndex] == nums[slowIndex+1])
                        slowIndex++;
                    slowIndex++;
                    fastIndex--;         
                }     
            }

        }
        return ans;
    }
};