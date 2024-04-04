#include<iostream>
#include<vector>
#include<queue>

/*给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。*/
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> r;
        queue<TreeNode*> que;
        if(root != nullptr)
            que.push(root);
        else
            return r;
        while(!que.empty()){
            vector<int> vec;
            // 每层的节点个数
            int size = que.size();
            for(int i = 0; i<size; i++){
                TreeNode* cur = que.front();
                que.pop();
                vec.push_back(cur->val);
                if(cur->left != nullptr)
                    que.push(cur->left);
                if(cur->right != nullptr)
                    que.push(cur->right);
            }
            res.push_back(vec);
        }
        for(int i = 0; i<res.size();i++)
            r.push_back(res[i][res[i].size()-1]);
        return r;
    }
};