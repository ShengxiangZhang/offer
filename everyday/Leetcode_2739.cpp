#include<iostream>

using namespace std;
/***总行驶距离***/

class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int s = 0;
        int count = 0;
        while(mainTank > 0){
            mainTank--;
            s += 10;
            count++;
            if(count%5 == 0){
                if(additionalTank){
                    additionalTank--;
                    mainTank++;
                }
            }
        }
        return s;
    }
};