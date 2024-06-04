#include<iostream>
#include<vector>
#include<stack>

/*柱状图中最大矩形*/
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int res = 0;
        heights.insert(heights.begin(), 0);
        heights.insert(heights.end(), 0);

        // 从栈底到栈顶是递增的
        // 栈顶元素前面元素和当前要入栈的元素都是比它小的
        for(int i = 0; i < heights.size(); i++){
            while(!st.empty() && heights[i] < heights[st.top()]){
                int mid = st.top();
                st.pop();
                if(!st.empty()){
                    int h = heights[mid];
                    int w = i - st.top() - 1;
                    res = max(res, h*w);
                }
            }
            st.push(i);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> heights = {1,2,1};
    int res = s.largestRectangleArea(heights);
    cout << res << endl;
    system("pause");
    return res;
}