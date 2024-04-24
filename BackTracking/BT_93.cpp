#include<iostream>
#include<vector>
#include<string>

/***复原 IP 地址***/
using namespace std;

class Solution {
public:
    vector<string> vec;
    vector<vector<string>> res;

    void backtracking(int index, string s, int depth){
        if(depth == 4){
            if(index == s.size()){
                res.push_back(vec);
            return;
            }
        }
        for(int i = index; i < s.size() && i < index + 3; i++){
            string substr = s.substr(index, i-index+1);
            int num = stoi(substr);
            if(num >= 0 && num <= 255)
                vec.push_back(substr);
            else
                continue;
            backtracking(i+1, s, depth+1);
            vec.pop_back();
        }

    }
    void restoreIpAddresses(string s){
        backtracking(0, s, 0);
        for(int i = 0; i < res.size(); i++){
            for(int j = 0; j < res[i].size();j++)
                cout << res[i][j] << ".";
            cout << "\n";
        }
    }
};

int main(){
    string str = "25525511135";
    Solution s;
    s.restoreIpAddresses(str);
    system("pause");
    return 0;
}