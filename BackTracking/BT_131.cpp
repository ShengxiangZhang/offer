#include<iostream>
#include<vector>
#include<string>

/*给你一个字符串s，请你将s分割成一些子串，使每个子串都是 
回文串。返回s所有可能的分割方案。*/
using namespace std;

class Solution {
public:
    vector<vector<string>> res;
    vector<string> vec;
    // 判断是否回文串
    bool IsOrNot(string& s, int left, int right){
        while(left < right){
            if(s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }

    void backtracking(int startIndex, string s){
        if(startIndex >= s.size()){
            res.push_back(vec);
            return;
        }

        for(int i = startIndex; i < s.size(); i++){
            if(IsOrNot(s, startIndex, i))
                // string.substr(起始位置，字串长度)
                vec.push_back(s.substr(startIndex, i-startIndex+1));
            else
                continue;
            backtracking(i+1,s);
            vec.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        backtracking(0,s);
        return res;
    }
};