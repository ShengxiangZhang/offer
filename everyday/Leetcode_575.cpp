#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_map<int, int> candy;
        int n = candyType.size();
        int type = 0;
        for(int i = 0; i < n; i++){
            if(candy[candyType[i]] == 0){
                type++;
                candy[candyType[i]]++;
            }       
        }
        if(type <= (n/2))
            return type;
        else
            return n/2;
    }
};

int main(){
    Solution s;
    vector<int> c = {6,6,6,6};
    int res = s.distributeCandies(c);
    system("pause");
    return 0;
}