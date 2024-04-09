#include<iostream>
#include<queue>
#include<vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};
/*****给定一个二叉树，判断它是否是高度平衡的二叉树*****/

// 迭代法
class Solution {
public:
    // 求当前节点的高度（当前节点到叶子节点）
    int getDepth(TreeNode* root){
        int depth = 0;
        if(root == nullptr)
            return depth;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            depth++;
            int size = que.size();
            for(int i = 0; i < size; i++){
                TreeNode* cur = que.front();
                que.pop();
                if(cur->left != nullptr)
                    que.push(cur->left);
                if(cur->right != nullptr)
                    que.push(cur->right);
            }
        }
        return depth;
    }

    bool isBalanced(TreeNode* root) {
        queue<TreeNode*> que;
        bool flag = true;
        if(root == nullptr)
            return true;
        else
            que.push(root);
        while(!que.empty()){
            int size = que.size();
            for(int i = 0; i < size; i++){
                TreeNode* cur = que.front();
                que.pop();
                int num1 = getDepth(cur->left);
                int num2 = getDepth(cur->right);
                if(abs(num1 - num2) > 1){
                    flag = false;
                    break;
                }
                if(cur->left != nullptr)
                    que.push(cur->left);
                if(cur->right != nullptr)
                    que.push(cur->right);

            }
        }
        return flag;
    }
};