#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;


int main(){
    unordered_map<string,int> map;

    string s = "ab";
    map[s]++;
    for(const auto& pair : map) 
        cout << pair.first << " " << pair.second << endl;
    system("pause");
    return 0;
}