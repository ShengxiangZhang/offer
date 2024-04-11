#include<iostream>
#include<vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

// 递归前序
/*
class Solution {
public:
    void traversal(TreeNode* cur, vector<int>& vec){
        // 终止条件
        if(cur == nullptr)
            return;
        
        // 单层循环逻辑
        vec.push_back(cur->val);
        traversal(cur->left, vec);
        traversal(cur->right, vec);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vec;
        traversal(root, vec);
        return vec;
    }
};*/

// 递归中序
/*class Solution {
public:
    void traversal(TreeNode* cur, vector<int> &vec){
        // 终止条件
        if(!cur)
            return;
        
        traversal(cur->left, vec);
        traversal(cur->right, vec);
        vec.push_back(cur->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        traversal(root, res);
        return res;
    }
};*/
// 递归中序
class Solution {
public:
    void traversal(TreeNode* cur, vector<int> &vec){
        // 终止条件
        if(!cur)
            return;
        
        traversal(cur->left, vec);
        vec.push_back(cur->val);
        traversal(cur->right, vec);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        traversal(root, res);
        return res;
    }
};