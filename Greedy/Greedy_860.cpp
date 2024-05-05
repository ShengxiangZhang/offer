#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fiveNum = 0;
        int tenNum = 0;
        for(int i = 0; i < bills.size(); i++){
            // 收到5元
            if(bills[i] == 5)
                fiveNum++;
            // 收到10元
            else if(bills[i] == 10){
                if(fiveNum <= 0)
                    return false;
                else{
                    fiveNum--;
                    tenNum++;
                }   
            }
            // 收到20元
            else{
                // 有10元的先找零10元的加一张五元的
                if(tenNum >0 && fiveNum > 0){
                    tenNum--;
                    fiveNum--;
                }
                else if(fiveNum >=3 )
                    fiveNum = fiveNum -3;
                else
                    return false;
            }
        }
        return true;
    }
};