#include<iostream>
#include<stack>

using namespace std;

//用栈解决（单纯为了用栈而用栈）
class Solution {
public:
    string removeDuplicates(string s) {
        //用了两个栈
        stack<int> st1;
        stack<int> st2;
        for(int i =0; i<s.size();i++)
            st1.push(s[i]);
        while(!st1.empty()){
            if(!st2.empty() && st1.top() == st2.top()){
                st1.pop();
                st2.pop();
            }
            else{
                st2.push(st1.top());
                st1.pop();
            }
        }
        int count = 0;
        while (!st2.empty())
        {
            s[count] = st2.top();
            st2.pop();
            count++;
        }
        s.resize(count);
        return s;     
    }
};
