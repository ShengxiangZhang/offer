#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>

/*下一个更大元素Ⅰ*/
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> map;
        stack<int> st;

        for(int i = 0; i < nums1.size(); i++) 
            map[nums1[i]] = i;
            
        for(int i = 0; i < nums2.size(); i++){
            while(!st.empty() && nums2[i] > nums2[st.top()]){
                st.pop();
                map[st.top()] = nums2[i];
            }
            st.push(i);
        }


    }
};