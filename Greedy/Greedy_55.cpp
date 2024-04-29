#include<iostream>
#include<vector>

/***跳跃游戏***/
using namespace std;

/*
class Solution {
public:
    // 局部最优：每次选取单步能到达最远距离的值，争取最大的跳跃步数
    // 全局最优：得到整体能够到达的最远距离

    bool canJump(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            int max = -1;
            int index = -1;
            for(int j = 1; j <= nums[i]; j++){
                if(i + j + nums[i+j] >= nums.size() - 1)
                    return true;
                if( i + j + nums[i+j] > max){
                    max = i + j + nums[i+j];
                    index = i + j;
                }   
            }
            i = index - 1;
        }
        return false;
    }
};*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1)
            return true;
        int cover = 0;
        for(int i = 0; i <= cover; i++){
            if(cover >= nums.size() - 1)
                return true;
            // 每次取最大覆盖范围
            if(nums[i] + i > cover)
                cover = nums[i] + i;
        }
        return false;
    }
};

/*int main(){
    vector<int> nums = {3,2,1,0,4};
    Solution s;
    bool b = s.canJump(nums);
    system("pause");
    return 0;
}*/