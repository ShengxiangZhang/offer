#include<iostream>
#include<queue>
#include<vector>

using namespace std;

/****给定二叉搜索树（BST）的根节点 root 和一个整数值 val。
你需要在 BST 中找到节点值等于val的节点。返回以该节点为根的子树。如果节点不存在，则返回null。****/
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int _val): val(_val), left(nullptr), right(nullptr);
};


/* 迭代法
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root){
            if(val == root->val)
                return root;
            if(val < root->val)
                root = root->left;
            else
                root = root->right;
        }
        return nullptr;
    }
};
*/

// 递归法
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {

        if(!root || val == root->val)
            return root;

        if(val < root->val)
            root = searchBST(root->left, val);
        else
            root = searchBST(root->right, val);
        return root;
    }
};