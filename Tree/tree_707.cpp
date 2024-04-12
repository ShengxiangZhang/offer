#include<iostream>
#include<queue>
#include<vector>

using namespace std;

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