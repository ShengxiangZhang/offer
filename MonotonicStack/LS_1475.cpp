#include<iostream>
#include<vector>
#include<stack>

/*商品折扣后的最终价格*/
using namespace std;

// 单调栈
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;

        // 找后续比当前元素小的元素
        // 应该使用一个从栈底到栈顶递增的单调栈
        for(int i = 0; i < prices.size(); i++){
            while(!st.empty() && prices[i] <= prices[st.top()]){
                prices[st.top()] -= prices[i];
                st.pop();
            }
            st.push(i);
        }
        return prices;
    }
};