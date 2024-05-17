#include<iostream>
#include<vector>

/**打家劫舍**/
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int sum1 = 0; 
        int sum2 = 0; 
        int i = 0;
        while(i <= nums.size()){
            sum1 += nums[i];
            i += 2;
        }
        i = 1;
        while(i <= nums.size()){
            sum2 += nums[i];
            i += 2;
        }
        
        return sum1 > sum2 ? sum1:sum2;
    }
};

int main(){
    Solution s;
    vector<int> nums{1,2,3,1};
    int res = s.rob(nums);
    return 0;
}