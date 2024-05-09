#include<iostream>
#include<vector>

using namespace std;

/**给植物浇水II**/
class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        // 装水次数
        int fillNum = 0;

        // 罐子A和B中的水量
        int waterA = capacityA;
        int waterB = capacityB;

        int left = 0;
        int right = plants.size()-1;

        // 双指针
        while(left < right){
            if(waterA >= plants[left])
                waterA -= plants[left];
            else{
                fillNum++;
                waterA = capacityA;
                waterA -= plants[left];
            }
            left++;
            if(waterB >= plants[right])
                waterB -= plants[right];
            else{
                fillNum++;
                waterB = capacityB;
                waterB -= plants[right];
            }
            right--;
        }
        if(left == right){
            int water = max(waterA, waterB);
            if(water < plants[left])
                fillNum++;
        }
        return fillNum;
    }
};