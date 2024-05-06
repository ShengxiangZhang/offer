#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

/**给定一个非负整数N，找出小于或等于N的最大的整数，同时这个整数需要满足其各个位数上的数字是单调递增。**/

using namespace std;
// 重点是怎么将一个整数转化为递增的最大数，72->69
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        vector<int> singleAlph;
        while(n!=0){
            singleAlph.push_back(n%10);
            n = n / 10;
        }

        int index = -1;

        for(int i = 0; i < singleAlph.size() - 1; i++){
            if(singleAlph[i] < singleAlph[i+1]){
                index = i;
                singleAlph[i+1]--;
            }
        }

        for(int i = 0; i <= index; i++)
            singleAlph[i] = 9;
        int res = 0;
        for(int i = 0; i < singleAlph.size(); i++)
            res += singleAlph[i] * pow(10,i);
        return res;
    }
};

int main(){
    int a = 10;
    Solution s;
    s.monotoneIncreasingDigits(a);
    return 0;
}