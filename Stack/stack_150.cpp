#include<iostream>
#include<vector>
#include<string>
#include<stack>

/******* 逆波兰表达式求值 ********/

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        int len = tokens.size();
        for(int i = 0; i < len; i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/" ){
                long long temp1 = st.top();
                st.pop();
                long long temp =st.top();
                st.pop();
                if(tokens[i] == "+")
                    st.push(temp + temp1);
                if(tokens[i] == "-")
                    st.push(temp - temp1);
                if(tokens[i] == "*")
                    st.push(temp * temp1);
                if(tokens[i] == "/")
                    st.push(temp / temp1);
            }
            else
                st.push(stoll(tokens[i]));
        }
        return st.top();
    }
};