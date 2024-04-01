#include<iostream>
#include<string>

using namespace std;
class Solution {
public:

    void reverse(int start, int end, string &s){
        while(start < end){
            char temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            start++;
            end++;
        }
    }
    string finalString(string s) {
        
    }
};