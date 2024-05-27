#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = 0;
        vector<int> res(n, 0);
        for(int i = 0; i < rolls.size(); i++)
            sum += rolls[i];
        
        int rest = mean*(rolls.size() + n) - sum;

        if((rest / (n*0.1)) > 6 || rest < n)
            return {};
        int k  = 0;
        while(rest > 0){
            res[k % n]++;
            k++;
            rest--; 
        }
        return res;
    }
};



