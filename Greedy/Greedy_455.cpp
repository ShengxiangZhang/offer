#include<iostream>
#include<vector>
#include<algorithm>



/*分发饼干*/
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // 给数组排序，每次分配最小能满足需求的饼干
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0;
        int j = 0;
        int count = 0;
        while(i < g.size() && j < s.size()){
            // 饼干满足需求， 分配下一个孩子
            if(s[j] >= g[i]){
                count++;
                i++;
            }
            j++;
        }
        return count;
    }
};