#include<iostream>
#include<vector>
#include<queue>

/*****在每个树行中找最大值*****/
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> que;
        vector<int> res;
        if(root == nullptr)
            return res;
        else    
            que.push(root);
        while(!que.empty()){
            int size = que.size();
            int max = que.front()->val;
            for(int i = 0; i < size; i++){
                TreeNode* temp = que.front();
                que.pop();
                if(temp->val > max)
                    max = temp->val;
                if(temp->left != nullptr)
                    que.push(temp->left);
                if(temp->right != nullptr)
                    que.push(temp->right);
            }
            res.push_back(max);
        }
        return res;
    }
};


