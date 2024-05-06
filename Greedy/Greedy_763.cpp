#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// 这道题的本质是什么？ 找到遍历过字母的最远边界
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> alphabet(26,0);
        vector<int> res;

        // 统计每个字母最后出现的位置
        for(int i = 0; i < s.size(); i++)
            alphabet[s[i]-97] = i;
        
        int left = 0;
        int right = 0;

        for(int i = 0; i < s.size(); i++){
            right = max(alphabet[s[i]-'a'], right);
            // 这里比较难想到（i==right）
            if(i == right){
                res.push_back(right-left+1);
                left = right+1;
            }
        }
        return res;
    }
};