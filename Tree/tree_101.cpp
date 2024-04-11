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

//迭代法,这题不能直接用层次遍历
/*class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> que;
        bool flag = true;
        // 先入队，循环里再判断是否相等
        que.push(root->left);
        que.push(root->right);

        while(!que.empty()){
            TreeNode* cur1 = que.front();
            que.pop();
            TreeNode* cur2 = que.front();
            que.pop();
            // 两个节点都为空，继续
            if(!cur1 && !cur2)
                continue;
            
            // 一个为空,或者两个值不相同
            if(!cur1 || !cur2 || (cur1->val != cur2->val))
                return false;
            
            //按比较顺序入队
            que.push(cur1->left);
            que.push(cur2->right);
            que.push(cur1->right);
            que.push(cur2->left);
        }
        return true;

    }
};*/

// 递归
class Solution {
public:
    bool isornot(TreeNode* left, TreeNode* right){
        if(!left && !right)
            return true;
        else if(!left || !right)
            return false;
        else if(left->val != right->val)
            return false;
        
        bool flag1 = isornot(left->left, right->right);
        bool flag2 = isornot(left->right, right->left);
        return flag1 && flag2;
    }

    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return isornot(root->left, root->right);
    }
};