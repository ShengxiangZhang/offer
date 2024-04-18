#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
/*给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。*/

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == nullptr || root == p || root == q)
            return root;
        
        TreeNode * left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right =  lowestCommonAncestor(root->right, p, q);

        if(left && right)
            return root;
        else if(!left && right)
            return right;
        else if(left && !right)
            return left;
        else 
            return nullptr;
    }    
};