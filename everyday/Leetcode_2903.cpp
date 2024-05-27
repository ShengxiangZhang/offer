#include<iostream>
#include<vector>


/*找出满足差值条件的标*/
using namespace std;

class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        for(int i = 0; i < nums.size() ; i++){
            for( int j = i + indexDifference; j < nums.size(); j++){
                if(abs(nums[i]-nums[j]) >= valueDifference){
                    return {i, j};
                }
            }
        }
        return {-1,-1};
    }
};

int main(){
    /*Solution s;
    vector<int> nums ={ 0 };
    vector<int> res = s.findIndices(nums, 100, 50);
    return 0;*/
    for(int i = 0; i < -99; i++){
        cout <<  i;
    }
    return 0;
}