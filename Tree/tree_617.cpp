#include<iostream>
#include<stack>
#include<queue>
#include<vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int _val): val(_val), left(nullptr), right(nullptr){}
};

// 递归
/*class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1)
            return root2;
        if(!root2)
            return root1;
        root1->val += root2->val;

        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);

        return root1;
    }
};*/

// 层序遍历
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1)
            return root2;
        if(!root2)
            return root1;
        queue<TreeNode*> que;
        que.push(root1);
        que.push(root2);
        while(!que.empty()){
            TreeNode* cur1 = que.front();
            que.pop();
            TreeNode* cur2 = que.front();
            que.pop();
            
            cur1->val += cur2->val;

            if(cur1->left && cur2->left){
                que.push(cur1->left);
                que.push(cur2->left);
            }

            if(cur1->right && cur2->right){
                que.push(cur1->right);
                que.push(cur2->right);
            }

            if(!cur1->left && cur2->left)
                cur1->left = cur2->left;
            
            if(!cur1->right && cur2->right)
                cur1->right = cur2->right;
        }
        return root1;
    }
};