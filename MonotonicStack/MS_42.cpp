#include<iostream>
#include<vector>
#include<stack>

/*接雨水*/
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        stack<int> st;

        for(int i = 0; i < height.size(); i++){
            while(!st.empty() && height[i] > height[st.top()]){
                int mid = st.top();
                st.pop();
                if(!st.empty()){
                    // 高度
                    int h = min(height[i], height[st.top()]) - height[mid];
                    // 宽度
                    int w = i - st.top() - 1;
                    res += w*h;
                }
            }
            st.push(i);
        }
        return res;
    }
};