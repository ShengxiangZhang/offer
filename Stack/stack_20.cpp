#include<iostream>
#include<stack>
#include<string>
using namespace std;

/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号。
*/

class Solution {
public:
    bool isValid(string s) {
        int len = s.size();
        stack<char> st1;
        stack<char> st2;
        for(int i = 0; i<len; i++ ){
            if(s[i]=='(' || s[i]==')' || s[i]=='{' || s[i]=='}' || s[i]=='[' || s[i]==']')
                st1.push(s[i]);
        }
        while(st1.empty()){
            st2.pop()
            if(!st2.empty() && st1.top() == st2.top()){
                st1.pop();
                st2.pop();  
            }
        }
        return true;
    }
};