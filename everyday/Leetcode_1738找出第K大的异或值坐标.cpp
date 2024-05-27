#include<iostream>
#include<vector>


using namespace std;

class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        vector<int> res;
        // dp[i][j]表示maxtrix[0-i][0-j]
        vector<vector<int>> dp(matrix.size(), vector<int> (matrix[0].size()));

    }
};