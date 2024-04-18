#include<iostream>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode * cur = root;
        while(cur != nullptr){
            if(cur->val > p ->val && cur->val > q->val)
                cur = cur->left;
            else if(cur->val < p->val && cur->val < q->val)
                cur = cur->right;
            else
                break;
        }
        return cur;
    }
};