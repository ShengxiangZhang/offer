#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int dim = grid[0].size();
        bool flag = true;
        int i = 0;
        for(i; i < dim; i++){
            for(int j = 0; j < dim; j++){
                if(i != j && grid[i][j] != 1){
                    flag = false;
                    break;
                }
            }
            if(flag == true)
                break;
        }
        return i;
    }
};