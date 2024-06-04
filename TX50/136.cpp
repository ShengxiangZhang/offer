#include<iostream>
#include<vector>

using namespace std;

// 异或运算的性质，任何数和它本身异或都为0，a^a = a，任何数和0异或都为0，a^0 = 0;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int num: nums)
            res ^= num;
        return res;
    }
};


/*只出现一次的数字*/