#include<iostream>
#include<vector>


/***买卖股票的最佳时机***/
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = INT_MAX;
        int max = 0;
        for(int i  = 0; i < prices.size(); i++){
            if(prices[i] < min)
                min = prices[i];
            else if(prices[i] - min > max)
                max = prices[i] - min;
        }
        return max;
    }
};