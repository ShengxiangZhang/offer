#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

// 定义树结构
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

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
/*class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;
        TreeNode* cur = root;
        while(cur!= nullptr || !st.empty()){
            if(cur != nullptr){
                st.push(cur);
                cur = cur->left;
            }
            else{
                cur = st.top();
                res.push_back(cur->val);   
                st.pop();
                cur = cur->right;      
            }
        }
        return res;
    }
};*/

// 迭代法后序遍历

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root){
        TreeNode* cur = root;
        stack<TreeNode*> st;
        vector<int> res;
        if(root == nullptr)
            return res;
        st.push(root);
        while(!st.empty()){
            TreeNode* cur = st.top();
            st.pop();
            res.push_back(cur->val);
            if(cur->left != nullptr)
                st.push(cur->left);
            if(cur->right != nullptr)
                st.push(cur->right);
        }
        reverse(res.begin(), res.end()); // 将结果反转之后就是左右中的顺序了
        return res;
    }
}