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
};