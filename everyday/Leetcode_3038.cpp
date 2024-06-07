#include<iostream>
#include<vector>
using namespace std;

/*相同分数的最大操作数目Ⅰ*/
class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int sum = nums[0] + nums[1];
        int cnt = 1;
        int i = 2;
        while(i + 1 < nums.size()){
            if(nums[i] + nums[i+1] == sum)
                cnt++;
            else
                break;
            i += 2;
        }
        return cnt;
    }
};