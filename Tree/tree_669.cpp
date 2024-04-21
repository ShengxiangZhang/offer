#include<iostream>

using namespace std;

/*修剪二叉搜索树*/
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int _val): val(_val), left(nullptr), right(nullptr){}
};


class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {

        // 先让根节点在范围内
        while(root && (root->val < low || root->val > high)){
            if(root->val < low)
                root = root->right;
            if(root->val > high)
                root = root->left;
        }
        // 如果根节点为空，直接返回空
        if(!root)
            return nullptr;

        TreeNode* leftPre = root;
        TreeNode* rightPre = root;
        
        // 左子树
        while(leftPre->left){
            if(leftPre->left->val < low)
                leftPre->left = leftPre->left->right;
            else
                leftPre = leftPre->left;
        }

        // 右子树
        while(rightPre->right){
            if(rightPre->right->val > high)
                rightPre->right = rightPre->right->left;
            else
                rightPre = rightPre->right;
        }
        return root;
    }
};