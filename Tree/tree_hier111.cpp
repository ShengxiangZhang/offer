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

// 层次遍历
/*class Solution {
public:
    int minDepth(TreeNode* root) {
        int depth = 0;
        queue<TreeNode*> que;
        if(root != nullptr)
            que.push(root);
        else
            return depth;
        while(!que.empty()){
            int size = que.size();
            depth++;
            for(int i = 0; i<size; i++){
                TreeNode* cur = que.front();
                que.pop();
                if(cur->left != nullptr)
                    que.push(cur->left);
                if(cur->right != nullptr)
                    que.push(cur->right);
                if (!cur->left && !cur->right) // 当左右孩子都为空的时候，说明是最低点的一层了，退出
                    return depth;
            }

        }
        return depth;
    }
};*/