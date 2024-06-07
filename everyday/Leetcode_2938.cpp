#include<iostream>
#include<vector>

/*区分黑球与白球*/
using namespace std;

class Solution {
public:
    // 每个1后面有几个0就需要移动多少次
    long long minimumSteps(string s) {
        long long res = 0;
        long long cnt = 0;
        int n = s.size();
        for(int i = n-1; i >= 0; i--){
            if(s[i] == '1')
                res += cnt;
            else
                cnt++;
        }
        return res;
    }
};