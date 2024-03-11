#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：

0 <= a, b, c, d < n
a、b、c 和 d 互不相同
nums[a] + nums[b] + nums[c] + nums[d] == target
你可以按 任意顺序 返回答案 。
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //快速排序
        sort(nums.begin(),nums.end());

        //存储结果
        vector<vector<int>> ans;

        //循环遍历
        int len = nums.size();
        for(int i = 0;i<len-3;i++){
            //减少计算，剪枝
            if(nums[i] > target && nums[i] > 0)
                break;
            //去重,这里是重点，如果这里用nums[i] == nums[i+1]判断，则j会无法取全部情况，如-2,-2,0,0,1,2时，j无法取到-2
            if(i>0 && nums[i] == nums[i-1])
                continue;
            for(int j = i+1;j<len-2;j++){
                //减少计算,剪枝,注意target可能是负数
                if(nums[i]+nums[j] > target && nums[i]+nums[j] > 0)
                    //不能直接return ans
                    break;
                //去重
                if(j>i+1 && nums[j] == nums[j-1])
                    continue;
                //定义双指针
                int slowIndex = j+1;
                int fastIndex = len-1;
                while(slowIndex < fastIndex){
                    //注意使用long,数值范围
                    if((long)nums[i] + nums[j] + nums[slowIndex] + nums[fastIndex] < target)
                        slowIndex++;
                    else if((long)nums[i] + nums[j] + nums[slowIndex] + nums[fastIndex] > target)
                        fastIndex--;
                    else{
                        ans.push_back({nums[i], nums[j], nums[slowIndex], nums[fastIndex]});
                        while(slowIndex < fastIndex && nums[slowIndex] == nums[slowIndex+1])
                            slowIndex++;
                        while(slowIndex < fastIndex && nums[fastIndex] == nums[fastIndex-1])
                            fastIndex--;
                        slowIndex++;
                        fastIndex--;
                    }
                }
            }
        }
    return ans;   
    }
};