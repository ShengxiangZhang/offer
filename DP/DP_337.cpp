#include<iostream>
#include<vector>
#include<queue>

/**打家劫舍3**/
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int _val): val(_val), left(nullptr), right(nullptr){}
};
class Solution {
public:
    int rob(TreeNode* root) {
        vector<int> res = treeDP(root);
        return max(res[0], res[1]);
    }

    vector<int> treeDP(TreeNode* cur){
        if(cur == nullptr)
            return {0,0};
        vector<int> left = treeDP(cur->left);
        vector<int> right = treeDP(cur->right);
        
        // 偷当前节点
        int val1 = cur->val + left[0] + right[0];
        
        // 不偷当前节点
        int val2 = max(left[0], left[1]) + max(right[0], right[1]);

        return {val2, val1};
    }
};