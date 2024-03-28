#include<iostream>
#include<vector>
#include<stack>

using namespace std;

// 迭代法进行前序遍历

/*
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;
        if(root == nullptr)
            return res;
        st.push(root);
        while(!st.empty()){
            TreeNode* cur = st.top();
            res.push_back(cur->val);
            st.pop();
            if(cur->right != nullptr)
                st.push(cur->right);
            if(cur->left != nullptr)
                st.push(cur->left);        
        }
        return res;
    }
};*/

// 迭代法进行中序遍历
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;
        if(root == nullptr)
            return res;
        st.push(root);
        while(!st.empty()){
            TreeNode* cur = st.top();
            res.push_back(cur->val);
            st.pop();
            if(cur->right != nullptr)
                st.push(cur->right);
            if(cur->left != nullptr)
                st.push(cur->left);        
        }
        return res;
    }
};
