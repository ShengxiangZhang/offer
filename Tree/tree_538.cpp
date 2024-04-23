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
/*class Solution {
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
        for(int i = len-2; i >= 0; i--)
            sum[i] += sum[i+1];

        int k = 0;
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
                cur->val = sum[k];
                k++;
                cur = cur->right;
            }
        }
        return root;
    }
};*/

// 反中序遍历
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode * cur;
        cur = root;
        int sum = 0;
        while(cur || !st.empty()){
            if(cur){
                st.push(cur);
                cur = cur->right;
            }
            else{
                cur = st.top();
                st.pop();
                sum += cur->val;
                cur->val = sum;
                cur = cur->left;
            }
        }
        return root;
    }
};

// 递归遍历
class Solution {
public:

    // 反中序递归，右左中
    int sum = 0;
    void traversal(TreeNode* root){
        if(!root)
            return;
        traversal(root->right);
        sum += root->val;
        root->val = sum;
        traversal(root->left);
        return;
    }

    TreeNode* convertBST(TreeNode* root) {
        traversal(root);
        return root;
    }
};