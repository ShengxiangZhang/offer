#include<iostream>
#include<queue>
#include<vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};
/*给你两棵二叉树的根节点p和q，编写一个函数来检验这两棵树是否相同。
  如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。*/

// 这一题和对称二叉树是一类题
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> que;
        que.push(p);
        que.push(q);
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
            que.push(cur2->left);
            que.push(cur1->right);
            que.push(cur2->right);
        }
        return true;
    }
};