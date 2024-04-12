#include<iostream>
#include<vector>

using namespace std;

/****给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。****/
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int _val): val(_val), left(nullptr), right(nullptr);
};

// 中序遍历的二叉搜索数是有序的
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
};