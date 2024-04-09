#include<iostream>
#include<stack>
#include<vector>
#include<string>

using namespace std;

/***给你一个二叉树的根节点root，按任意顺序，返回所有从根节点到叶子节点的路径。***/
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};

//
class Solution {
public:
    // 定义两个栈，一个树栈，一个路径栈，两个栈操作同步
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        // 树栈
        stack<TreeNode*> treeST;
        // 路径栈
        stack<string> pathST;
        if(root == nullptr)
            return res;
        treeST.push(root);
        pathST.push(to_string(root->val));
        while(!treeST.empty()){
            TreeNode* cur = treeST.top();
            treeST.pop();
            string path = pathST.top();
            pathST.pop();

            if(cur->left == nullptr && cur->right == nullptr)
                res.push_back(path);
            
            if(cur->right != nullptr){
                treeST.push(cur->right);
                string pathRight = path + "->" + to_string(cur->right->val);
                pathST.push(pathRight);
            }

            if(cur->left != nullptr){
                treeST.push(cur->left);
                string pathLeft = path + "->" + to_string(cur->left->val);
                pathST.push(pathLeft);
            }
        }
        return res;
    }
};