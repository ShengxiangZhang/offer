#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*二叉树的最大深度*/

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

// 迭代法
/*
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int depth = 0;
        queue<TreeNode*> que;
        if(root != nullptr)
            que.push(root);
        else
            return depth;
        while(!que.empty()){
            int size = que.size();
            for(int i = 0; i<size; i++){
                TreeNode* cur = que.front();
                que.pop();
                if(cur->left != nullptr)
                    que.push(cur->left);
                if(cur->right != nullptr)
                    que.push(cur->right);
            }
            depth++;
        }
        return depth;
    }
};*/
class Solution {
public:
    int res;
    void mDepth(TreeNode* cur, int depth){
        if(depth > res)
            res = depth;
        if(!cur->left && !cur->right)
            return;
        if(cur->left)
            mDepth(cur->left, depth+1);
        if(cur->right)
            mDepth(cur->right, depth+1);
    }
    int maxDepth(TreeNode* root) {
        res = 0;
        if(!root)
            return res;
        mDepth(root, 1);
        return res;
    }
};