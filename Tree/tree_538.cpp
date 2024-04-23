#include<iostream>
#include<stack>
#include<vector>

/*把二叉搜索树转化为累加树*/

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};

// 迭代法，两次中序 （起始可以做一次反中序遍历）
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> sum;
        TreeNode* cur = root;
        // 中序遍历
        while (!st.empty() || cur)
        {
            if(cur){
                st.push(cur);
                cur = cur->left;
            }
            else{
                cur = st.top();
                st.pop();
                sum.push_back(cur->val);
                cur = cur->right;
            }
        }  
        int len = sum.size();
        // 得到sum是一个顺序序列，进行累加
        for(int i = len-1; i >= 0; i--)
            sum[i] += sum[i+1];
        int k = len-1;
        cur = root;
        while (!st.empty() || cur)
        {
            if(cur){
                st.push(cur);
                cur = cur->left;
            }
            else{
                cur = st.top();
                st.pop();
                cur->val = sums[k];
                k--;
                cur = cur->right;
            }
        }
        return root;
    }
};