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
            }
            return;
        }
        for(int i = index; i < s.size() && i < index + 3; i++){
            string substr = s.substr(index, i-index+1);
            if(substr.size() > 1 && substr[index] == '0')
                continue;
            int num = stoi(substr);
            if(num >= 0 && num <= 255)
                vec.push_back(substr);
            else
                continue;
            backtracking(i+1, s, depth+1);
            vec.pop_back();
        }

    }
    vector<string> restoreIpAddresses(string s){
        vector<string> r;
        backtracking(0, s, 0);
        cout << res.size() << endl;
        for(int i = 0; i < res.size(); i++){
            string temp;
            for(int j = 0; j < res[i].size(); j++){
                temp += res[i][j];
                if(j != res[i].size() - 1)
                    temp += ".";
            }
            r.push_back(temp);
        }
        return r;
    }
};


int main(){
    string str = "101023";
    Solution s;
    vector<string> res = s.restoreIpAddresses(str);
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << endl;
    system("pause");
    return 0;
}