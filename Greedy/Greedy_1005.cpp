#include<iostream>
#include<vector>
#include<algorithm>

/*K次取反后最大化的数组和*/
using namespace std;

// 我的思路，用了贪心思想，但时间复杂度高
/*class Solution {
public:
    // 局部最优：每次给最小值加负号
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        for(int i = 0; i < k; i++){           
            sort(nums.begin(), nums.end());
            nums[0] = -nums[0];
        }
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
            sum += nums[i];
        return sum;
    }
};*/

class Solution {
public:
    // 按照绝对值大小排序
    static bool comp(int a, int b){
        return abs(a) > abs(b);
    }
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), comp);
        
        // 将绝对值大的复数变为正数
        for(int i = 0; i < nums.size(); i++){
            if(k == 0)
                break;
            if(nums[i] < 0){
                if(k > 0){
                    nums[i] = -nums[i];
                    k--;
                }   
            }      
        }
        if(k%2 == 1)
            nums[nums.size() - 1] = -nums[nums.size() - 1];
        int sum = 0;
        for(int num : nums)
            sum += num;
        return sum;
    }
};