#include<iostream>
#include<vector>
#include<stack>

/*下一个更大元素Ⅱ*/
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(nums.size(), -1);
        stack<int> st;
        // 模拟整个数组走两边
        for(int i = 0; i < nums.size()*2;i++){
            while(!st.empty() && nums[i%n] > nums[st.top()]){
                res[st.top()] = nums[i%n];
                st.pop();
            }
            st.push(i%n);
        }
        return res;
    }
};