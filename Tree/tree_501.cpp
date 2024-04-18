#include<iostream>
#include<queue>
#include<vector>
#include<stack>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int _val): val(_val), left(nullptr), right(nullptr){}
};

/*给你一个含重复值的二叉搜索树（BST）的根节点 root ，找出并返回 BST 中的所有 众数（即，出现频率最高的元素）。*/
class Solution {
public:
    int num;
    int maxNum = 0;
    int pre = INT_MIN;
    vector<int> res;
    void traversal(TreeNode* root){
        if(!root)
            return;
        
        traversal(root->left);
        if(root->val != pre){
            num = 1;
            pre = root->val;
        }
        else
            num++;
        if(num > maxNum){
            maxNum = num;
            res.clear();
            res.push_back(root->val);
        }
        else if(num == maxNum){
            res.push_back(root->val);
        }
        traversal(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        traversal(root);
        return res;
    }
};