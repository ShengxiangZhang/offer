#include<iostream>
#include<vector>
#include<stack>

using namespace std;

/****给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。****/
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int _val): val(_val), left(nullptr), right(nullptr);
};

// 中序遍历的二叉搜索数是有序的
/*
class Solution {
public:

    void traversal(TreeNode* root, vector<int> &res){
        if(!root)
            return;
        
        traversal(root->left, res);
        res.push_back(root->val);
        traversal(root->right, res);
    }

    bool isValidBST(TreeNode* root) {
        vector<int> res;
        traversal(root, res);
        for(int i = 1; i < res.size(); i++){
            if(res[i] <= res[i-1])
                return false;
        }
        return true;
    }
};*/

// 递归方法 
/*class Solution {
public:
    long long max = LONG_LONG_MIN;
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;

        bool left = isValidBST(root->left);

        if(root->val <= max)
            return false;
        max = root->val;
        
        bool right = isValidBST(root->right);
        return left && right;
    }
};*/

// 迭代方法
/*class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        long long pre = LONG_LONG_MIN;
        while(cur || !st.empty()){
            if(cur){
                st.push(cur);
                cur = cur->left;
            }
            else{
                cur = st.top();
                st.pop();
                if(cur->val <= pre)
                    return false;
                pre = cur->val;
                cur = cur->right;
            }
        }
        return true;
    }
};*/