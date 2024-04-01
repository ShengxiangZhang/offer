#include<iostream>
#include<vector>
#include<queue>

using namespace std;    
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr);
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> que;
        if(root != nullptr)
            que.push(root);
        else
            return root;
        while(!que.empty()){    
            int size = que.size();
            for(int i = 0; i<size; i++){
                TreeNode* cur = que.front();
                que.pop();
                TreeNode * temp = cur->left;
                // 左右子树反转
                cur->left = cur->right;
                cur->right = temp;
                if(cur->left != nullptr)
                    que.push(cur->left);
                if(cur->right != nullptr)
                    que.push(cur->right);
            }
        }
        return root;
    }
};