#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

/**出现最少三次的最长特殊子字符串**/
using namespace std;

class Solution {
public:
    static bool comp(int a, int b){
        return a > b;
    }
    int maximumLength(string s) {
        vector<int> vec[26];
        int cnt = 0;
        for(int i = 0; i < s.size(); i++){
            cnt++;
            if(i == (s.size()-1) || s[i] != s[i+1] ){
                vec[s[i] - 'a'].push_back(cnt);
                cnt = 0;
            }   
        }
        
        int ans = 0;
        for(int i = 0; i < 26; i++){
            if(vec[i].empty())
                continue;
            
            // sort(vec[i].begin(), vec[i].end());升序排列
            sort(vec[i].begin(), vec[i].end(), comp);
            vec[i].push_back(0);
            vec[i].push_back(0); // 假设还有两个空串
            ans = max({ans, vec[i][0] - 2, min(vec[i][0] - 1, vec[i][1]), vec[i][2]});
    }
    return ans ? ans : -1;
    }
};