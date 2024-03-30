#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};


// 用队列解决层次遍历问题

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        vector<vector<int>> res;
        if(root == nullptr)
            return res;
        else
            que.push(root);
        while(!que.empty()){
            vector<int> vec;
            // 注意que.size()是不断变化的
            int size = que.size();
            for(int i = 0; i < size; i++){
                TreeNode* temp = que.front();
                que.pop();
                vec.push_back(temp->val);
                if(temp->left != nullptr)
                    que.push(temp->left);
                if(temp->right != nullptr)
                    que.push(temp->right);
            }
            res.push_back(vec);
        }
        return res;
    }
};