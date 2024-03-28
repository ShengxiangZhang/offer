#include<iostream>
#include<vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};
// 用递归法实现二叉树的前中后序遍历

// 前序的递归写法
/*class Solution {
public:
    // 1.确认函数返回类型
    void traversal(TreeNode* cur, vector<int>& vec) {
        // 2.确认中止条件
        if(cur == nullptr)
            return;
        // 3.确认单层的递归逻辑 
        vec.push_back(cur->val);
        traversal(cur->left, vec);
        traversal(cur->right,vec);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vec;
        traversal(root, vec);
        return vec;
    }
};*/

/*
class Solution {
public:
    void traversal(TreeNode* cur, vector<int>& res){
        if(cur == nullptr)
            return;
        traversal(cur->left,res);
        res.push_back(cur->val);
        traversal(cur->right,res);  
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        traversal(root, res);
        return res;
    }
};*/

//后序
class Solution {
public:
    void traversal(TreeNode* cur, vector<int>& res){
        if(cur == nullptr)
            return;
        traversal(cur->left,res);
        traversal(cur->right,res); 
        res.push_back(cur->val);
         
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        traversal(root, res);
        return res;
    }
};