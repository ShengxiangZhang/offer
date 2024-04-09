#include<iostream>
#include<queue>
#include<vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};
/*给你一个二叉树的根节点 root，检查它是否轴对称*/

// 用递归来解决
/*class Solution {
public:
    bool compare(TreeNode* left, TreeNode* right){
        if(left == nullptr && right == nullptr)
            return true;
        else if((left == nullptr && right != nullptr) || (left != nullptr && right == nullptr) )
            return false;
        else if(left->val != right->val)
            return false;
        
        bool outside = compare(left->left, right->right);
        bool inside = compare(left->right, right->left);
        return outside && inside;

    }
    bool isSymmetric(TreeNode* root) {
        bool res = compare(root->left, root->right);
            return res;
    }
};*/

//迭代法
