#include<iostream>

#include<vector>

/**统计已测试设备**/
using namespace std;

class Solution{
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int count = 0;
        int size = batteryPercentages.size();

        for(int i = 0; i < size; i++){
            if(batteryPercentages[i] - count > 0)
                count++;
        }
        return count;
    }
};