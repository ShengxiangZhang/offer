#include<iostream>
#include<queue>
#include<vector>
#include<stack>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};


/*给你二叉树的根节点 root 和一个表示目标和的整数 targetSum 。判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和 targetSum 。如果存在，返回 true ；否则，返回 false */

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        // 第一个栈用于存放树
        stack<TreeNode*> treeST;

        // 第二个栈用于存放路径
        stack<int> resST;

        vector<int> pathSum;
        if(!root)
            return false;
        treeST.push(root);
        resST.push(root->val);
        while(!treeST.empty()){
            TreeNode* cur = treeST.top();
            int temp = resST.top();
            treeST.pop();
            resST.pop();
            
            // 当一条路径走到尽头，即到达叶子节点，存下来
            if(!cur->left && !cur->right)
                pathSum.push_back(temp);

            if(cur->right){
                treeST.push(cur->right);
                resST.push(temp + cur->right->val);
            }
            if(cur->left){
                treeST.push(cur->left);
                resST.push(temp + cur->left->val);
            }
        }
        for(int sum : pathSum){
            if(sum == targetSum)
                return true;
        }
        return false;
    }
};  