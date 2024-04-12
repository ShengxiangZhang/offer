#include<iostream>
#include<queue>
#include<vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};

/*给定一个二叉树的根节点root，请找出该二叉树的最底层最左边节点的值。假设二叉树中至少有一个节点。*/

// 层序遍历
/*class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        int res;
        while(!que.empty()){
            int size = que.size();
            for(int i = 0; i < size; i++){
                TreeNode* cur = que.front();
                que.pop();
                if(i == 0)
                    res = cur->val;
                if(cur->left)
                    que.push(cur->left);
                if(cur->right)
                    que.push(cur->right);
            }
        }
        return res;
    }
};*/

// 递归法