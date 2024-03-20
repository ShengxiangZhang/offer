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

//自己的思路，需要用两个栈
/*
class Solution {
public:
    bool isValid(string s) {
        int len = s.size();
        stack<char> st1;
        stack<char> st2;
        //去除字母，将所有符号入栈st1
        for(int i = 0; i<len; i++ ){
            if(s[i]=='(' || s[i]==')' || s[i]=='{' || s[i]=='}' || s[i]=='[' || s[i]==']')
                st1.push(s[i]);
        }

        //依次从st1中取出符号，放入st2中，
        while(!st1.empty()){
            int temp = st1.top();
            //判断st1和st2的栈顶元素是否匹配成一个括号，如果相同则两个栈顶元素都出栈
            if(!st2.empty() && ((temp == '(' && st2.top()==')')||(temp == '[' && st2.top()==']')||(temp == '{' && st2.top()=='}'))){
                st1.pop();
                st2.pop();  
            }
            //如果不同，则st1的栈顶元素入栈st2
            else{
                st2.push(temp);
                st1.pop();
            }
        }
        //最后，如果st2是空的则说明全部匹配出栈了
        if(st2.empty())
            return true;
        else
            return false;
    }
};
*/

//用一个栈解决问题
//思路：如果这个符号串是正确的，那么从最内部的一个匹配的括号开始消除，最终这个符号串会完全消除/*
/*class Solution {
public:
    bool isValid(string s) {
        stack<int> st1;
        int len = s.size();
        for(int i = 0; i < len; i++){
            if(!st1.empty() && ((st1.top() == '(' && s[i]==')')||(st1.top() == '[' && s[i]==']')||(st1.top() == '{' && s[i]=='}')))
                st1.pop();
            else
                st1.push(s[i]);
        }
        if(st1.empty())
            return true;
        else
            return false;
    }
};*/
