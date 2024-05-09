#include<iostream>
#include<vector>

/**给植物浇水**/
using namespace std;

class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int countStep = 0;
        int water = capacity;
        for(int i = 0; i < plants.size(); i++){
            countStep++;
            if(water >= plants[i])
                water -= plants[i];
                
            else{
                countStep += 2*i;
                water = capacity;
                water -= plants[i];
            }
        }
        return countStep;
    }
};