#include<iostream>
#include<vector>
#include<stack>

/*每日温度*/
using namespace std;

// 暴力来解，超时了
/*
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res;
        for(int i = 0; i < temperatures.size(); i++){
            int j = i+1;
            while(j < temperatures.size()){
                if(temperatures[j] > temperatures[i])
                    break;
                j++;
            }
            if(j == temperatures.size())
                res.push_back(0);
            else
                res.push_back(j-i);
        }

        return res;
    }
};
*/

// 单调栈，写法1，从左到右遍历。栈中记录还没算出「下一个更大元素」的那些数（的下标）
/*class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(),0);
        stack<int> st;
        st.push(0);

        for(int i = 1; i < temperatures.size(); i++){
            while(!st.empty() && temperatures[i] > temperatures[st.top()]){
                    res[st.top()] = i - st.top();
                    st.pop();
            }
            st.push(i);
        }
        return res;
    }
};*/
// 写法2 栈中记录下一个更大元素的「候选项」。
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(temperatures.size(),0);
        stack<int> st;

        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && temperatures[i] >= temperatures[st.top()]){
                    st.pop();
            }
            if(!st.empty()){
                res[i] = st.top() - i;
            }
            st.push(i);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> T = {73,74,75,71,69,72,76,73};
    vector<int> res = s.dailyTemperatures(T);
    return 0;
}