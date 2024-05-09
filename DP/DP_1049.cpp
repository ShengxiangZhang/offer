#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {

        //将石头分为尽可能相近的两堆

        int sum = 0;
        for(int i = 0; i < stones.size(); i++)
            sum += stones[i];
        int mid = sum / 2;
        // 
        vector<int> dp(mid + 1, 0);

        for(int i = 0; i < stones.size(); i++){
            for(int j = mid; j >= stones[i]; j--)
                dp[j] = max(dp[j], dp[j-stones[i]] + stones[i]);
        }
        return sum - 2*dp[mid]; 
    }
};