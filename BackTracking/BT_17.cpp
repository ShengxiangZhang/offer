#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<string> res;
    string path;

    void traversal(string& digits, int index, int len, vector<string>& map){
        if(path.size() == len){
            res.push_back(path);
            return;
        }
        
        for(int i = 0; i < map[digits[index] - 48].size(); i++){
            path.push_back(map[digits[index] - 48][i]);
            traversal(digits, index + 1, len, map);
            path.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)
            return res;
        vector<string> map;
        map.push_back("");
        map.push_back("");
        map.push_back("abc");
        map.push_back("def");
        map.push_back("ghi");
        map.push_back("jkl");
        map.push_back("mno");
        map.push_back("pqrs");
        map.push_back("tuv");
        map.push_back("wxyz");
        int len = digits.size();
        traversal(digits, 0, len, map);
        return res;
    }
};