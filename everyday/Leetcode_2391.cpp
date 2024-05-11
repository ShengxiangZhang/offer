#include<iostream>
#include<vector>

/***收集垃圾的最少总时间**/
using namespace std;

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int count = 0;
        int posP = 0;
        int posG = 0;
        int posM = 0;
        for(int i = 0; i < garbage.size(); i++){
            for(int j = 0; j < garbage[i].size(); j++){
                if(garbage[i][j] == 'M'){
                    for(int k = posM; k < i; k++)
                        count += travel[k];
                    count++;
                    posM = i;
                }
                else if(garbage[i][j] == 'G'){
                    for(int k = posG; k < i; k++)
                        count += travel[k];
                    count++;
                    posG = i;
                }
                else{
                    for(int k = posP; k < i; k++)
                        count += travel[k];
                    count++;
                    posP = i;
                }
            }
        }
        return count;
    }
};