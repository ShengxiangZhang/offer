#include<iostream>
#include<vector>

/***买卖股票的最佳时机***/
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int count = 0;
        for(int i = 0; i < prices.size() -1 ; i++){
            if(prices[i+1] - prices[i] > 0)
                count += prices[i+1] - prices[i];
        }
        return count;
    }
};