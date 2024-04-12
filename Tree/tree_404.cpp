#include<iostream>
#include<queue>
#include<vector>

using namespace std;

/**** 给定二叉树的根节点root，返回所有左叶子之和。****/
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};


// 层序遍历
/*
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int res = 0;
        queue<TreeNode*> que;
        if(!root)
            return res;
        
        que.push(root); 
        while(!que.empty()){
            int size = que.size();

            for(int i= 0; i < size; i++){
                TreeNode* cur = que.front();
                que.pop();
                if(cur->left){
                    que.push(cur->left);
                    if(!cur->left->left && !cur->left->right)
                        res += cur->left->val;
                }
                if(cur->right)
                    que.push(cur->right);
            }
        }
        return res;
    }
};*/

// 递归法
class Solution {
public:
    int res;
    void getres(TreeNode* node){
        if(!node)
            return;
        if(!node->left && !node->right)
            return;
        if(node->left && !node->left->left && !node->left->right)
            res +=  node->left->val;
        getres(node->left);
        getres(node->right);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        res = 0;
        getres(root);
        return res;
    }
};